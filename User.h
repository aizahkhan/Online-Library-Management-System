#pragma once

#include <string>
#include "IDGenerator.h"

class User : public IDGenerator {
private:
  int id; 
  std::string name; 
  float balance; 
  int loyaltyTier; 
  std::string accountStatus; 
  std::vector<std::string> transactionHistory; 
  std::string currentReward; 
  int maxBorrowedBooks; 
  std::vector<int> borrowedBookIDs; 

public:
  User(const std::string& _name, float _balance, int _loyaltyTier);

  int getID() const; 
  std::string getName() const; 
  float getBalance() const; 
  int getLoyaltyTier() const; 
  std::string getAccountStatus() const; 
  std::vector<std::string> getTransactionHistory() const; 
  void setCurrentReward(const std::string& reward); 
  int getMaxBorrowedBooks() const; 
  std::vector<int> getBorrowedBookIDs() const; 

  void setAccountStatus(const std::string& _accountStatus); 
  void addTransaction(const std::string& transaction); 
  std::string getCurrentReward() const; 
  void setBorrowedBook(int bookID); 
  void returnBook(int bookID); 

  void loadFromFile(const std::string& filename); 
  void saveToFile(const std::string& filename); 
  void setLastUserIdFromFile(int lastUserID); 
};