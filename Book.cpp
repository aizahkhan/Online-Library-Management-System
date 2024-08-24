
#include "Book.h"
#include <iostream>
#include <fstream>


Book::Book(const std::string& _title, const std::string& _genre, const std::string& _author, float _size): id(generateBookID()), title(_title), genre(_genre), author(_author), availability(true), size(_size) {}

int Book::getID() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getGenre() const { return genre; }
std::string Book::getAuthor() const { return author; }
bool Book::isAvailable() const { return availability; }
float Book::getSize() const { return size; }

void Book::setAvailable(bool _available) { availability = _available; }

void Book::loadFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    file >> id;
    std::getline(file, title);
    std::getline(file, genre);
    std::getline(file, author);
    file >> availability >> size;
    file.close();
  } 
  else {
    std::cerr << "Unable to open file: " << filename << std::endl;
  }
}

void Book::saveToFile(const std::string& filename) {
std::ofstream file(filename);
  if (file.is_open()) {
    file << id << " " << title << std::endl<< genre  << std::endl << author  << std::endl << availability << " " << size;
    file.close();
  } 
  else {
    std::cerr << "Unable to open file: " << filename << std::endl;
  }
}

void Book::setLastBookIdFromFile(int lastBookID){
  setLastBookId(lastBookID);
}
