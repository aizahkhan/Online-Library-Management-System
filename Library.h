#pragma once

#include <string>
#include <vector> 
#include "Book.h"
#include "User.h"
#include "Transaction.h"

class Library {
private:
  std::string name;
  int totalBooks;
  float totalBandwidth;
  std::vector<Book*> books; 
  std::vector<User*> users; 
  std::vector<Transaction*> transactions;

public:
  Library(const std::string& _name);

  std::string getName() const;
  int getTotalBooks() const;
  float getTotalBandwidth() const;
  std::vector<Book*> getBooks() const; 
  std::vector<User*> getUsers() const; 
  std::vector<Transaction*> getTransactions() const; 

  void addBook(Book* book);
  void addUser(User* user);
  void removeBook(int bookID);
  void removeUser(int userID);
  void loadFromFile(const std::string& filename);
  void saveToFile(const std::string& filename);
  bool borrowBook(int userID, int bookID); 
  bool returnBook(int userID, int bookID); 
  void printBooks() const; 
  void printUsers() const; 
};
