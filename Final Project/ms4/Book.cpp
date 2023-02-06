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
#include "Book.h"
using namespace std;
namespace sdds {

   Book::Book(){
      m_author = nullptr;
   }

   Book::Book(const Book& src){
      m_author = nullptr;
      *this = src;
   }

   Book& Book::operator=(const Book& src){
      if (this != &src) {
         Publication& publication = *this;
         publication = src;
         delete[] m_author;

         if (src.m_author) {
            m_author = new char[strlen(src.m_author) + 1];
            strcpy(m_author, src.m_author);
         }
         else {
            m_author = nullptr;
         }
      }
      return *this;
   }

   Book::~Book(){
      delete[] m_author;
      m_author = nullptr;
   }

   char Book::type() const{
      return 'B';
   }

   std::ostream& Book::write(std::ostream& os) const{
      // strncpy() -> won't add '\0' automatically.
      //Set the Author to show, and manually add '\0' to avoid error.
      char tempAuthor[SDDS_AUTHOR_WIDTH + 1];
      strncpy(tempAuthor, m_author, SDDS_AUTHOR_WIDTH);
      tempAuthor[SDDS_AUTHOR_WIDTH] = '\0';

      Publication::write(os);
      if (conIO(os)) {
         os << " ";
         os.width(SDDS_AUTHOR_WIDTH);
         os.setf(ios::left);
         os << tempAuthor << " |";
         os.unsetf(ios::left);
      }
      else {
         os << "\t" << m_author;
      }
      return os;
   }

   std::istream& Book::read(std::istream& istr){
      char tempAuthor[SDDS_AUTHOR_MAX_LEN + 1]{};
      Publication::read(istr);
      delete[] m_author;
      if (conIO(istr)) {
         istr.ignore(1, '\n');
         cout << "Author: ";
         //getline() will eat the '\n' and main will eat again -> read incomplete.
         istr.get(tempAuthor, SDDS_AUTHOR_MAX_LEN);
      }
      else {
         istr.ignore(1, '\t');
         istr.get(tempAuthor, SDDS_AUTHOR_MAX_LEN);
      }
      if (!istr.fail()) {
         m_author = new char[strlen(tempAuthor) + 1];
         strcpy(m_author, tempAuthor);
      }
      return istr;
   }

   void Book::set(int member_id){
      Publication::set(member_id);
      resetDate();
   }

   Book::operator bool() const{
      return m_author && Publication::operator bool();
   }



}