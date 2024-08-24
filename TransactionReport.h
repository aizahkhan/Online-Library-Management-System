#pragma once

#include <string>
#include "Transaction.h"
#include "Book.h"

class TransactionReport {
public:
  static void generateReport(const std::vector<Transaction*>& transactions, const std::vector<Book*>& books,int userID);
};
