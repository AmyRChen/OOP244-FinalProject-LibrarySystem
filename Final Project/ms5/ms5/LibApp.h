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
#ifndef SDDS_LIBAPP_H_
#define SDDS_LIBAPP_H_
#include <iostream>
#include "Menu.h"
#include "Utils.h"
#include "Lib.h"
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"

namespace sdds {
   class LibApp {
      bool m_changed{};
      Menu m_mainMenu{};
      Menu m_exitMenu{};
      //ms5 attributes:
      char m_fileName[SDDS_TITLE_MAX_LEN]{};
      Publication* m_allPublication[SDDS_LIBRARY_CAPACITY]{}; //PPA: populated with all the records of the publication data file when the LibApp is instantiated.
      int m_publicationNum{};   //NOLP: number of Publications loaded into the PPA
      int m_lastLibRefNum{}; //LLRN: will be used to assign new library reference numbers to new publications added to the library.
      Menu m_typeSel{};

      //private method
      bool confirm(const char* message);
      void load();
      void save();
      int search(const char* mode); //add argument: search all, checkout items, available items
      void returnPub();
      void newPublication();
      void removePublication();
      void checkOutPub();
      void terminates();

   public:
      LibApp(const char* filename);
      void init();
      void run();
      //ms5
      Publication* getPub(int libRef); //return match address
      void showTxt();
   };
}

#endif // !SDDS_LIBAPP_H_
