#pragma once

#include <string>
#include <vector>
#include "IDGenerator.h"

class Transaction : public IDGenerator {
private:
  int id; 
  std::time_t dateTime; 
  std::string type; 
  std::vector<int> bookIDs; 
  int userID;

public:
  Transaction(const std::string& _type, const std::vector<int>& _bookIDs, int _userID);

  int getID() const; 
  std::time_t getDateTime() const; 
  std::string getType() const; 
  std::vector<int> getBookIDs() const;
  int getUserID() const; 

  void loadFromFile(const std::string& filename); 
  void saveToFile(const std::string& filename); 
  void setLastTransactionIdFromFile(int lastTransactionID); 
};
