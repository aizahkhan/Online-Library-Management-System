#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

class IDGenerator {
protected:
  static int lastAdminID;
  static int lastBookID;
  static int lastUserID;
  static int lastTransactionID;
public:
  static int generateAdminID();
  static int generateBookID();
  static int generateUserID();
  static int generateTransactionID();
  static void setLastBookId(int lastBookID); 
  static void setLastUserId(int lastUserID); 
  static void setLastTransactionId(int lastTransactionID);

};
