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
#include <iostream>
using namespace std;
#include "Utils.h"
namespace sdds {
   bool checkIntRange(unsigned int value, int min, int max) {
      bool valid{};
      if ((int)value < min || (int)value > max) {
         cin.clear();
         cout << "Invalid Selection, try again: ";
         valid = false;
      }
      else {
         valid = true;
      }
      return valid;
   }
}