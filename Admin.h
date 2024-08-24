#pragma once

#include <string>
#include "Library.h" 
#include "User.h" 
#include "IDGenerator.h" 

class Admin : public IDGenerator {
private:
  int id;
  std::string name;
  int yearsWithLibrary;
  float salary;
  Library* library;
  std::string currReward;

public:
  Admin(const std::string& _name, int _yearsWithLibrary, float _salary, Library* _library);

  void setCurrentReward(const std::string& reward);

  int getID() const;
  std::string getName() const;
  int getYearsWithLibrary() const;
  float getSalary() const;
  std::string getCurrentReward() const;


  void addWorker(User* user); 
  void removeWorker(int userID); 
  void rewardUser(User* user); 
  void rewardAdmin(Admin* admin); 
  void rewardWorker(User* user, const std::string& reward); 
  void loadFromFile(const std::string& filename);
  void saveToFile(const std::string& filename);
};

