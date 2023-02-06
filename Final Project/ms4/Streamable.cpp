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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Streamable.h"
using namespace std;
namespace sdds {
   std::ostream& operator<<(std::ostream& ostr, const Streamable& right){
      if (right) {
         right.write(ostr);
      }
      return ostr;
   }

   std::istream& operator>>(std::istream& istr, Streamable& right){
      return right.read(istr);
   }
}
