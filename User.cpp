
#include "User.h"
#include <iostream>
#include <fstream>
#include <algorithm>

User::User(const std::string& _name, float _balance, int _loyaltyTier)
  : id(generateUserID()), name(_name), balance(_balance),  loyaltyTier(_loyaltyTier), accountStatus("Active"), maxBorrowedBooks(5)  {}

int User::getID() const { return id; }
std::string User::getName() const { return name; }
float User::getBalance() const { return balance; }
int User::getLoyaltyTier() const { return loyaltyTier; }
std::string User::getAccountStatus() const { return accountStatus; }
std::vector<std::string> User::getTransactionHistory() const { return transactionHistory; }
void User::setCurrentReward(const std::string& reward) { currentReward = reward; }
int User::getMaxBorrowedBooks() const { return maxBorrowedBooks; }
std::vector<int> User::getBorrowedBookIDs() const { return borrowedBookIDs; }

void User::setAccountStatus(const std::string& _accountStatus) { accountStatus = _accountStatus; }
void User::addTransaction(const std::string& transaction) { transactionHistory.push_back(transaction); }
std::string User::getCurrentReward() const { return currentReward; }
void User::setBorrowedBook(int bookID) { borrowedBookIDs.push_back(bookID); }
void User::returnBook(int bookID) {
  auto it = std::find(borrowedBookIDs.begin(), borrowedBookIDs.end(), bookID);
  if (it != borrowedBookIDs.end()) {
    borrowedBookIDs.erase(it);
  }
}

void User::loadFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    file >> id >> name >> balance >> loyaltyTier >> accountStatus >> maxBorrowedBooks;
    int borrowedBookID;
    while (file >> borrowedBookID) {
      borrowedBookIDs.push_back(borrowedBookID);
    }
    std::string transaction;
    while (std::getline(file, transaction)) {
      transactionHistory.push_back(transaction);
    }
    file.close();
  } 
  else {
    std::cerr << "Unable to open file: " << filename << std::endl;
  }
}

void User::saveToFile(const std::string& filename) {
  std::ofstream file(filename);
  if (file.is_open()) {
    file << id << " " << name << " " << balance << " " << loyaltyTier << " " << accountStatus << " " << maxBorrowedBooks << std::endl;
    for (const auto& bookID : borrowedBookIDs) {
      file << bookID << " ";
    }
    file << std::endl;
    for (const auto& transaction : transactionHistory) {
      file << transaction << std::endl;
    }
    file.close();
  } 
  else {
    std::cerr << "Unable to open file: " << filename << std::endl;
  }
}

void User::setLastUserIdFromFile(int lastUserID){
  setLastUserId(lastUserID);
}
  