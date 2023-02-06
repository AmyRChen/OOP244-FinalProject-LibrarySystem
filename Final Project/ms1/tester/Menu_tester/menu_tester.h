// Final Project Milestone 1
// Date Module
// File  Date.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ping-Ju, Chen      2022/07/08           First edit
// 
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my project milestones.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#ifndef SDDS_MENU_TESTER_H__
#define SDDS_MENU_TESTER_H__
#include <iostream>
namespace sdds {
   const unsigned int MAX_MENU_ITEMS = 20;

   class MenuItem {
      char* m_content{};
      friend class Menu;
      MenuItem();
      MenuItem(const char* itemName);
      ~MenuItem();
      MenuItem(const MenuItem& item) = delete;
      MenuItem& operator=(const MenuItem& item) = delete;

      operator bool()const;
      operator const char* ()const;
      std::ostream& display(std::ostream& ostr = std::cout)const;
   };

   class Menu {
   private:
      MenuItem m_title{};
      MenuItem* m_items[MAX_MENU_ITEMS]{};
      int m_numOfItem{};

   public:
      Menu();
      Menu(const char* title);
      ~Menu();
      Menu(const Menu& M) = delete;
      Menu& operator=(const Menu& M) = delete;
      void setEmpty();
      std::ostream& displayTitle(std::ostream& ostr = std::cout)const;
      std::ostream& displayMenu(std::ostream& ostr = std::cout)const;
      //methods
      unsigned int run();
      unsigned int operator~();
      Menu& operator<<(const char* menuitemConent);
      operator int() const;
      operator unsigned int()const;
      operator bool()const;
      const char* operator[](int index)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Menu& menu);
}

#endif // SDDS_MENU_H__#pragma once
