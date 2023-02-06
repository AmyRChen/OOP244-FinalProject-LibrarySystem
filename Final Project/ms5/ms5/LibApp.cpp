/***********************************************************************
// OOP244 Utils Module
// File  utils.h
// Version 1.0
// Author  PingJu, Chen
// Description
// Usgin for final project utilities
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Ping-Ju, Chen   2022/08/05      First edit
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "LibApp.h"

using namespace std;
namespace sdds{
   bool LibApp::confirm(const char* message){
      Menu M(message);
      M << "Yes";
      return M.run() == 1;
   }

   void LibApp::load(){
      cout << "Loading Data" << endl;
      ifstream infile(m_fileName);
      char type{};
      for (int i = 0; infile; i++) {
         infile >> type;
         infile.ignore();
         if (infile) {
            if (type == 'P') {
               m_allPublication[i] = new Publication;
            }
            else if (type == 'B') {
               m_allPublication[i] = new Book;
            }
            if (m_allPublication[i]) {
               infile >> *m_allPublication[i];
               m_publicationNum += 1;
               m_lastLibRefNum = m_allPublication[i]->getRef();
            }
         }
      }
   }

   void LibApp::save(){
      cout << "Saving Data" << endl;
      ofstream fout(m_fileName);
      for (int i = 0; i < m_publicationNum; i++) {
         if (m_allPublication[i]->getRef() != 0) {
            fout << *m_allPublication[i] << endl;
         }
      }
   }

   int LibApp::search(const char* mode){
      int found{};
      int selLibRef{};
      char searchKey[SDDS_TITLE_MAX_LEN + 1]{};
      PublicationSelector searchResult("Select one of the following found matches:");
      unsigned int selType = m_typeSel.run();
      char keyType{};
      cout << "Publication Title: ";
      cin.getline(searchKey, SDDS_TITLE_MAX_LEN, '\n');
      if ((int)selType == 1) {
         keyType = 'B';
      }
      else if ((int)selType == 2) {
         keyType = 'P';
      }
      else {
         cout << "Aborted!" << endl;
         cout << endl;
      }

      for (int i = 0; i < m_publicationNum; i++) {
         if (m_allPublication[i]->getRef() != 0 &&    //not delete
            m_allPublication[i]->type() == keyType && //type match
            *m_allPublication[i]==searchKey) {        //title contains
            if (!strcmp(mode,"onLoan") && m_allPublication[i]->onLoan()) {
               searchResult << m_allPublication[i];
               found++;
            }
            if (!strcmp(mode,"available") && !m_allPublication[i]->onLoan()) {
               searchResult << m_allPublication[i];
               found++;
            }
            if(!strcmp(mode, "all")){
               searchResult << m_allPublication[i];
               found++;
            }
         }
      }
      if (found) {
         searchResult.sort();
         selLibRef = searchResult.run();
      }
      else {
         cout << "No matches found!" << endl;
         cout << endl;
      }
      return selLibRef;
   }

   void LibApp::returnPub(){
      cout << "Return publication to the library" << endl;
      int selLibRef = search("onLoan");
      if (selLibRef) {
         getPub(selLibRef)->formDisplay();
         cout << endl;
         if (confirm("Return Publication?")) {
            Date current;
            double penalty{};
            int lateDays{};
            lateDays = current - getPub(selLibRef)->checkoutDate();
            if (lateDays > 15) {
               penalty = (lateDays - 15) * 0.5;
               cout << "Please pay $";
               cout.setf(ios::fixed);
               cout.precision(2);
               cout << penalty;
               cout.unsetf(ios::fixed);
               cout << " penalty for being " << (lateDays - 15) << " days late!" << endl;
            }
            getPub(selLibRef)->set(0);
            m_changed = true;
            cout << "Publication returned" << endl;
            cout << endl;
         }
         else {
            cout << endl;
         }
      }
   }

   void LibApp::newPublication(){
      Publication* temp{};
      if (m_publicationNum == SDDS_LIBRARY_CAPACITY) {
         cout << "Library is at its maximum capacity!" << endl;
         cout << endl;
      }
      else {
         cout << "Adding new publication to the library" << endl;
         unsigned int selType = m_typeSel.run();
         if (selType == 1) {
            temp = new Book;
            cin >> *temp;
         }
         else if(selType == 2) {
            Publication newPub;
            temp = new Publication;
            cin >> *temp;
         }
         if (selType == 0) {
            if (!cin) {
               cin.ignore();
            }
            cout << "Aborted!" << endl;
            cout << endl;
         }
         else {
            if (confirm("Add this publication to the library?")) {
               if (temp) {
                  m_lastLibRefNum += 1;
                  temp->setRef(m_lastLibRefNum);
                  m_allPublication[m_publicationNum] = temp;
                  m_publicationNum += 1;
                  m_changed = true;
                  cout << "Publication added" << endl;
                  cout << endl;
               }
               else {
                  cout << "Failed to add publication!" << endl;
                  delete temp;
               }
            }
            else {
               cout << "Aborted!" << endl;
            }

         }
      }
   }

   void LibApp::removePublication(){
      cout << "Removing publication from the library" << endl;
      int selLibRef = search("all");
      if (selLibRef) {
         getPub(selLibRef)->formDisplay();
         cout << endl;
         if (confirm("Remove this publication from the library?")) {
            getPub(selLibRef)->setRef(0);
            m_changed = true;
            cout << "Publication removed" << endl;
            cout << endl;
         }
         else {
            cout << endl;
         }
      }
   }

   void LibApp::checkOutPub(){
      int member{};
      bool stopRead = false;
      cout << "Checkout publication from the library" << endl;
      int selLibRef = search("available");
      if (selLibRef) {
         getPub(selLibRef)->formDisplay();
         cout << endl;
         if (confirm("Check out publication?")) {
            cout << "Enter Membership number: ";
            do {
               cin >> member;
               if (member <= 9999 || member > 99999) {
                  cout << "Invalid membership number, try again: ";
               }
               else {
                  stopRead = true;
               }
            } while (!stopRead);
            getPub(selLibRef)->set(member);
            m_changed = true;
            cout << "Publication checked out" << endl;
            cout << endl;
         }
         else {
            cout << endl;
         }
      }
   }

   void LibApp::terminates(){
      cout << endl;
      cout << "-------------------------------------------" << endl;
      cout << "Thanks for using Seneca Library Application" << endl;
   }

   LibApp::LibApp(const char* filename){
      strcpy(m_fileName, filename);
      init();
      load();
   }

   void LibApp::init(){
      m_changed = false;
      m_mainMenu.setTitle("Seneca Library Application");
      m_mainMenu << "Add New Publication" << "Remove Publication" 
                 << "Checkout publication from library" << "Return publication to library";
      m_exitMenu.setTitle("Changes have been made to the data, what would you like to do?");
      m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
      m_typeSel.setTitle("Choose the type of publication:");
      m_typeSel << "Book" << "Publication";
   }

   void LibApp::run(){
      bool exit = false;
      unsigned int mainSelect{};
      unsigned int exitSelect{};
      do {
         mainSelect = m_mainMenu.run();
         if (mainSelect == 1) {
            newPublication();
         }
         else if (mainSelect == 2) {
            removePublication();
         }
         else if (mainSelect == 3) {
            checkOutPub();
         }
         else if (mainSelect == 4) {
            returnPub();
         }
         else {
            if (m_changed) {
               exitSelect = m_exitMenu.run();
               if (exitSelect == 1) {
                  save();
                  exit = true;
               }
               else if (!exitSelect) {
                  if (confirm("This will discard all the changes are you sure?")) {
                     exit = true;
                  } 
               }
               else {
                  cout << endl;
               }
            }
            else {
               exit = true;
            }
         }
      } while (!exit);
      terminates();
      showTxt();
      for (int i = 0; i < m_publicationNum; i++) {
         delete m_allPublication[i];
         m_allPublication[i] = nullptr;
      }
   }

   Publication* LibApp::getPub(int libRef){
      Publication* result{};
      bool stopSearch = false;
      for (int i = 0; i < m_publicationNum && !stopSearch; i++) {
         if (m_allPublication[i]->getRef() == libRef) {
            result = m_allPublication[i];
            stopSearch = true;
         }
      }
      return result;
   }

   void LibApp::showTxt(){
      ifstream fin(m_fileName);
      if (fin) {
         cout << fin.rdbuf();
      }
      fin.close();
   }
}