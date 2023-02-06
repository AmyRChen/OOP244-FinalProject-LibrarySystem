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
#ifndef SDDS_PUBLISHER_H_
#define SDDS_PUBLISHER_H_
#include <iostream>
#include "Lib.h"
#include "Date.h"
#include "Streamable.h"
namespace sdds {
   class Publication:public Streamable {
      char* m_title{};
      char m_shelfId[SDDS_SHELF_ID_LEN + 1]{};
      int m_membership{};
      int m_libRef = -1;
      Date m_date{};

   public:
      Publication();
      //Rule of three...
      Publication(const Publication& src);
      Publication& operator=(const Publication& src);
      ~Publication();
      
      //method...
      // Sets the membership attribute to either zero or a five-digit integer.
      virtual void set(int member_id);
      // Sets the **libRef** attribute value
      void setRef(int value);
      // Sets the date to the current date of the system.
      void resetDate();
      //Returns the character 'P' to identify this object as a "Publication object"
      virtual char type()const;
      //Returns true is the publication is checkout (membership is non-zero)
      bool onLoan()const;
      //Returns the date attribute
      Date checkoutDate()const;
      //Returns true if the argument title appears anywhere in the title of the 
      //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
      bool operator==(const char* title)const;
      //Returns the title attribute
      operator const char* ()const;
      //Returns the libRef attirbute.
      int getRef()const;

      // custume functions...
      void setEmpty();
      void readConsole(std::istream& istr, Publication& temp, char* tempTitle);
      void readFile(std::istream& istr, Publication& temp, char* tempTitle);

      //implementation pure virtual function...
      bool conIO(std::ios& io)const;
      std::ostream& write(std::ostream& os) const;
      std::istream& read(std::istream& istr);
      operator bool() const;

   };
}
#endif // !SDDS_PUBLISHER_H_