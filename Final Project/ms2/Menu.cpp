// Final Project Milestone 2
// Date Module
// File  Date.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ping-Ju, Chen      2022/07/13           First edit
// 
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my project milestones.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <limits>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   // MenuItem module
   MenuItem::MenuItem() {
      m_content = nullptr;
   }

   MenuItem::MenuItem(const char* itemName) {
      m_content = new char[strlen(itemName) + 1];
      strcpy(m_content, itemName);
   }

   MenuItem::~MenuItem() {
      delete[] m_content;
   }

   MenuItem::operator bool() const {
      return m_content;
   }

   MenuItem::operator const char* () const {
      return m_content;
   }

   std::ostream& MenuItem::display(std::ostream& ostr) const {
      if (m_content) {
         //ostr << m_content;
         //MS2 edit
         ostr << m_content << endl;
      }
      return ostr;
   }

   // Menu module
   Menu::Menu() {
      setEmpty();
   }

   Menu::Menu(const char* title) {
      if (title && title[0]) {
         m_title.m_content = new char[strlen(title) + 1];
         strcpy(m_title.m_content, title);
      }
      *m_items = nullptr;
      m_numOfItem = 0;
   }

   Menu::~Menu() {
      for (int i = 0; i < m_numOfItem; i++) {
         delete m_items[i];   //delete single pointer (array of pointer)
         m_items[i] = nullptr;
      }
   }

   void Menu::setEmpty() {
      m_title.m_content = nullptr;
      *m_items = nullptr;
      m_numOfItem = 0;
   }

   std::ostream& Menu::displayTitle(std::ostream& ostr) const {
      return m_title.display();
   }

   std::ostream& Menu::displayMenu(std::ostream& ostr) const {
      displayTitle();
      // MS2 edit
      //if (m_title) {
      //   ostr << ":" << endl;
      //}
      for (int i = 0; i < m_numOfItem; i++) {
         ostr.width(2);
         ostr << i + 1 << "- " << m_items[i]->m_content << endl;  //arrow notation
      }
      ostr << " 0- Exit" << endl;
      ostr << "> ";
      return ostr;
   }

   unsigned int Menu::run() {
      displayMenu();
      unsigned int select{};
      bool valid{};
      do {
         cin >> select;
         if (cin.fail()) {
            cin.clear();
            cout << "Invalid Selection, try again: ";
            valid = false;
         }
         else {
            valid = checkIntRange(select, 0, m_numOfItem);
         }
         cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
      } while (!valid);
      return select;
   }

   unsigned int Menu::operator~() {
      displayMenu();
      unsigned int select{};
      bool valid{};
      do {
         cin >> select;
         valid = checkIntRange(select, 0, m_numOfItem);
      } while (!valid);
      return select;
   }

   Menu& Menu::operator<<(const char* menuitemConent) {
      if (m_numOfItem < (int)MAX_MENU_ITEMS) {
         char* tmp;
         tmp = new char[strlen(menuitemConent) + 1];
         strcpy(tmp, menuitemConent);
         m_items[m_numOfItem] = new MenuItem;   //new constructor -> create new ptr of object
         m_items[m_numOfItem]->m_content = tmp; //new ptr point to m_content and = tmp
         m_numOfItem++;
      }
      return *this;
   }

   Menu::operator int() const {
      return m_numOfItem;
   }

   Menu::operator unsigned int() const {
      return m_numOfItem;
   }

   Menu::operator bool() const {
      return m_numOfItem > 0;
   }

   const char* Menu::operator[](int index) const {
      int position{};
      if (index > m_numOfItem) {
         position = m_numOfItem % index;
      }
      else {
         position = index;
      }
      return m_items[position]->m_content;
   }

   void Menu::setTitle(const char* title){
      delete[] m_title.m_content;
      m_title.m_content = new char[strlen(title) + 1];
      strcpy(m_title.m_content, title);
   }

   std::ostream& operator<<(std::ostream& ostr, const Menu& menu) {
      return menu.displayTitle();
   }

}