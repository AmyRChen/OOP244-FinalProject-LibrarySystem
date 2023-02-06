// Final Project Milestone 4
// Date Module
// File  Date.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ping-Ju, Chen      2022/07/25           First edit
// 
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my project milestones.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <iostream>
#include "Lib.h"
#include "Publication.h"

namespace sdds {
   class Book : public Publication {
      char* m_author{};

   public:
      Book();
      //Rule of three...
      Book(const Book& src);
      Book& operator=(const Book& src);
      ~Book();

      //Methods...
      char type()const;
      std::ostream& write(std::ostream& os) const;
      std::istream& read(std::istream& istr);
      void set(int member_id);
      operator bool() const;

   };
}
#endif // !SDDS_BOOK_H_

