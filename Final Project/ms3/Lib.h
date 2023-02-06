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
#ifndef SDDS_LIB_H_
#define SDDS_LIB_H_
namespace sdds {
   const int SDDS_MAX_LOAN_DAYS = 15;  // Book -> maximum number of day a publication can be borrowed with no penalty
   const int SDDS_TITLE_WIDTH = 30; // The width in which the title of a publication should be printed on the console
   const int SDDS_AUTHOR_WIDTH = 15;   // The width in which the author name of a book should be printed on the console
   const int SDDS_SHELF_ID_LEN = 4; // The width in which the shelf id of a publication should be printed on the console
   const int SDDS_LIBRARY_CAPACITY = 5000;   // Maximum number of publications the library can hold.

   const int SDDS_TITLE_MAX_LEN = 255;
}

#endif // !SDDS_LIB_H_

