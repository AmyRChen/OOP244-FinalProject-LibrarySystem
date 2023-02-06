<<<<<<< HEAD
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
using namespace std;
namespace sdds {
   Publication::Publication() {
      setEmpty();
   }

   Publication::Publication(const Publication& src) {
      m_title = nullptr;
      *this = src;
   }

   Publication& Publication::operator=(const Publication& src) {
      if (this != &src) {
         Streamable& streamable = *this;
         streamable = src;
         delete[] m_title;
         strcpy(m_shelfId, src.m_shelfId);
         m_membership = src.m_membership;
         m_libRef = src.m_libRef;
         m_date = src.m_date;

         if (src.m_title) {
            m_title = new char[strlen(src.m_title) + 1];
            strcpy(m_title, src.m_title);
         }
         else {
            setEmpty();
         }
      }
      return *this;
   }

   Publication::~Publication() {
      delete[] m_title;
      m_title = nullptr;
   }

   void Publication::set(int member_id) {
      if (member_id == 0 || (member_id > 9999 && member_id <= 99999)) {
         m_membership = member_id;
      }
   }

   void Publication::setRef(int value) {
      m_libRef = value;
   }

   void Publication::resetDate() {
      Date current;
      m_date = current;
   }

   char Publication::type() const {
      return 'P';
   }

   bool Publication::onLoan() const {
      return m_membership != 0;
   }

   Date Publication::checkoutDate() const {
      return m_date;
   }

   bool Publication::operator==(const char* title) const {
      bool appears = false;
      if (strstr(m_title, title)) {
         appears = true;
      }
      return appears;
   }

   Publication::operator const char* () const {
      return m_title;
   }

   int Publication::getRef() const {
      return m_libRef;
   }

   void Publication::setEmpty() {
      m_title = nullptr;
      m_shelfId[0] = '\0';
      m_membership = 0;
      m_libRef = -1;
   }

   void Publication::readConsole(std::istream& istr, Publication& temp, char* tempTitle){
      cout << "Shelf No: ";
      istr.getline(temp.m_shelfId, SDDS_SHELF_ID_LEN + 1);
      if (!istr) {
         istr.setstate(ios::failbit);
      }
      cout << "Title: ";
      istr.getline(tempTitle, SDDS_TITLE_MAX_LEN + 1);
      cout << "Date: ";
      istr >> temp.m_date;
      if (temp.m_date.errCode() != 0) {
         istr.setstate(ios::failbit);
      }
   }

   void Publication::readFile(std::istream& istr, Publication& temp, char* tempTitle){
      char c;
      istr >> temp.m_libRef;
      istr.get(c);
      istr >> temp.m_shelfId;
      istr.get(c);
      istr.getline(tempTitle, SDDS_TITLE_MAX_LEN + 1, '\t');
      istr >> temp.m_membership;
      istr.get(c);
      istr >> temp.m_date;
      if (temp.m_date.errCode() != 0) {
         istr.setstate(ios::failbit);
      }

   }

   bool Publication::conIO(std::ios& io)const {
      return &io == &cin || &io == &cout;
   }

   std::ostream& Publication::write(std::ostream& os) const {
      if (conIO(os)) {
         os << "| " << m_shelfId << " | ";
         os.fill('.');
         os.width(30);
         os.setf(ios::left);
         os << m_title << " | ";
         os.unsetf(ios::left);
         if (!m_membership) {
            os << " N/A ";
         }
         else {
            os << m_membership;
         }
         os << " | ";
         os << m_date << " |";
      }
      else {
         os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t";
         os << m_title << "\t" << m_membership << "\t" << m_date;
      }
      return os;
   }

   std::istream& Publication::read(std::istream& istr) {
      char tempTitle[SDDS_TITLE_MAX_LEN + 1]{};
      Publication temp;
      setEmpty();
      if (conIO(istr)) {
         readConsole(istr, temp, tempTitle);
      }
      else {
         readFile(istr, temp, tempTitle);
      }
      if (!istr.fail()) {
         m_title = new char[strlen(tempTitle) + 1];
         strcpy(m_title, tempTitle);
         strcpy(m_shelfId, temp.m_shelfId);
         set(temp.m_membership);
         m_date = temp.m_date;
         setRef(temp.m_libRef);
      }
      return istr;
   }

   Publication::operator bool() const {
      return m_title && m_shelfId;
   }
}

=======
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Publication.h"
using namespace std;
namespace sdds {
   Publication::Publication() {
      setEmpty();
   }

   Publication::Publication(const Publication& src) {
      m_title = nullptr;
      *this = src;
   }

   Publication& Publication::operator=(const Publication& src) {
      if (this != &src) {
         Streamable& streamable = *this;
         streamable = src;
         delete[] m_title;
         strcpy(m_shelfId, src.m_shelfId);
         m_membership = src.m_membership;
         m_libRef = src.m_libRef;
         m_date = src.m_date;

         if (src.m_title) {
            m_title = new char[strlen(src.m_title) + 1];
            strcpy(m_title, src.m_title);
         }
         else {
            setEmpty();
         }
      }
      return *this;
   }

   Publication::~Publication() {
      delete[] m_title;
      m_title = nullptr;
   }

   void Publication::set(int member_id) {
      if (member_id == 0 || (member_id > 9999 && member_id <= 99999)) {
         m_membership = member_id;
      }
   }

   void Publication::setRef(int value) {
      m_libRef = value;
   }

   void Publication::resetDate() {
      Date current;
      m_date = current;
   }

   char Publication::type() const {
      return 'P';
   }

   bool Publication::onLoan() const {
      return m_membership != 0;
   }

   Date Publication::checkoutDate() const {
      return m_date;
   }

   bool Publication::operator==(const char* title) const {
      bool appears = false;
      if (strstr(m_title, title)) {
         appears = true;
      }
      return appears;
   }

   Publication::operator const char* () const {
      return m_title;
   }

   int Publication::getRef() const {
      return m_libRef;
   }

   void Publication::setEmpty() {
      m_title = nullptr;
      m_shelfId[0] = '\0';
      m_membership = 0;
      m_libRef = -1;
   }

   void Publication::readConsole(std::istream& istr, Publication& temp, char* tempTitle){
      cout << "Shelf No: ";
      istr.getline(temp.m_shelfId, SDDS_SHELF_ID_LEN + 1);
      if (!istr) {
         istr.setstate(ios::failbit);
      }
      cout << "Title: ";
      istr.getline(tempTitle, SDDS_TITLE_MAX_LEN + 1);
      cout << "Date: ";
      istr >> temp.m_date;
      if (temp.m_date.errCode() != 0) {
         istr.setstate(ios::failbit);
      }
   }

   void Publication::readFile(std::istream& istr, Publication& temp, char* tempTitle){
      char c;
      istr >> temp.m_libRef;
      istr.get(c);
      istr >> temp.m_shelfId;
      istr.get(c);
      istr.getline(tempTitle, SDDS_TITLE_MAX_LEN + 1, '\t');
      istr >> temp.m_membership;
      istr.get(c);
      istr >> temp.m_date;
      if (temp.m_date.errCode() != 0) {
         istr.setstate(ios::failbit);
      }

   }

   bool Publication::conIO(std::ios& io)const {
      return &io == &cin || &io == &cout;
   }

   std::ostream& Publication::write(std::ostream& os) const {
      if (conIO(os)) {
         os << "| " << m_shelfId << " | ";
         os.fill('.');
         os.width(30);
         os.setf(ios::left);
         os << m_title << " | ";
         os.unsetf(ios::left);
         if (!m_membership) {
            os << " N/A ";
         }
         else {
            os << m_membership;
         }
         os << " | ";
         os << m_date << " |";
      }
      else {
         os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t";
         os << m_title << "\t" << m_membership << "\t" << m_date;
      }
      return os;
   }

   std::istream& Publication::read(std::istream& istr) {
      char tempTitle[SDDS_TITLE_MAX_LEN + 1]{};
      Publication temp;
      setEmpty();
      if (conIO(istr)) {
         readConsole(istr, temp, tempTitle);
      }
      else {
         readFile(istr, temp, tempTitle);
      }
      if (!istr.fail()) {
         m_title = new char[strlen(tempTitle) + 1];
         strcpy(m_title, tempTitle);
         strcpy(m_shelfId, temp.m_shelfId);
         set(temp.m_membership);
         m_date = temp.m_date;
         setRef(temp.m_libRef);
      }
      return istr;
   }

   Publication::operator bool() const {
      return m_title && m_shelfId;
   }
}

>>>>>>> f4305efd9ec148542b948c43e8cbd9e2b5c5e888
