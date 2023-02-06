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
#ifndef SDDS_LIBAPP_H_
#define SDDS_LIBAPP_H_
#include <iostream>
#include "Menu.h"
#include "Utils.h"

namespace sdds {
   class LibApp {
      bool m_changed{};
      Menu m_mainMenu{};
      Menu m_exitMenu{};
      //private method
      bool confirm(const char* message);
      void load();
      void save();
      void search();
      void returnPub();
      void newPublication();
      void removePublication();
      void checkOutPub();
      void terminates();

   public:
      LibApp();
      void init();
      void run();
   };
}

#endif // !SDDS_LIBAPP_H_
