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
// Ping-Ju, Chen   2022/07/13      First edit
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
   }

   void LibApp::save(){
      cout << "Saving Data" << endl;
   }

   void LibApp::search(){
      cout << "Searching for publication" << endl;
   }

   void LibApp::returnPub(){
      search();
      cout << "Returning publication" << endl;
      cout << "Publication returned" << endl;
      cout << endl;
      m_changed = true;
   }

   void LibApp::newPublication(){
      bool add{};
      cout << "Adding new publication to library" << endl;
      add = confirm("Add this publication to library?");
      if (add) {
         m_changed = true;
         cout << "Publication added" << endl;
         cout << endl;
      }
      else {
         cout << endl;
      }
   }

   void LibApp::removePublication(){
      bool remove{};
      cout << "Removing publication from library" << endl;
      search();
      remove = confirm("Remove this publication from the library?");
      if (remove) {
         m_changed = true;
         cout << "Publication removed" << endl;
         cout << endl;
      }
      else {
         cout << endl;
      }

   }

   void LibApp::checkOutPub(){
      bool check{};
      search();
      check = confirm("Check out publication?");
      if (check) {
         m_changed = true;
         cout << "Publication checked out" << endl;
         cout << endl;
      }
      else {
         cout << endl;
      }

   }

   void LibApp::terminates(){
      cout << endl;
      cout << "-------------------------------------------" << endl;
      cout << "Thanks for using Seneca Library Application" << endl;
   }

   LibApp::LibApp(){
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
   }
}