// Final Project Milestone 3
// Date Module
// File  Date.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Ping-Ju, Chen      2022/07/19           First edit
// 
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my project milestones.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include <iostream>
namespace sdds {
   class Streamable {
   public:
      //Functions overriding this function will write into an ostream object.
      virtual std::ostream& write(std::ostream& ostr)const = 0;
      //Functions overriding this function will read from an istream object.
      virtual std::istream& read(std::istream& istr) = 0;
      //Functions overriding this function will determine if the incoming ios object is a console IO object or not.
      virtual bool conIO(std::ios&)const = 0;
      //overloads of this method will return if the Streamable object is in a valid state or not.
      virtual operator bool()const = 0;
      virtual ~Streamable() {};
   };
   std::ostream& operator<<(std::ostream& ostr, const Streamable& right);
   std::istream& operator>>(std::istream& istr, Streamable& right);

}
#endif // !SDDS_STREAMABLE_H_

