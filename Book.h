#pragma once

#include <string>
#include "IDGenerator.h"

class Book : public IDGenerator {
private:
  int id; 
  std::string title; 
  std::string genre; 
  std::string author; 
  bool availability; 
  float size;

public:
  Book(const std::string& _title, const std::string& _genre, const std::string& _author, float _size);

  int getID() const; 
  std::string getTitle() const; 
  std::string getGenre() const; 
  std::string getAuthor() const; 
  bool isAvailable() const; 
  float getSize() const; 

  void setAvailable(bool _available); 
  void loadFromFile(const std::string& filename); 
  void saveToFile(const std::string& filename); 
  void setLastBookIdFromFile(int lastBookID); 
};
