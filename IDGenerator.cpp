#include "IDGenerator.h"

int IDGenerator::lastAdminID = 0;
int IDGenerator::lastBookID = 0;
int IDGenerator::lastUserID = 0;
int IDGenerator::lastTransactionID = 0;


int IDGenerator::generateAdminID() {
    return ++lastAdminID;
}


void IDGenerator::setLastBookId(int lastBookID) { IDGenerator::lastBookID = lastBookID; }

void IDGenerator::setLastUserId(int lastUserID) { IDGenerator::lastUserID = lastUserID; }

void IDGenerator::setLastTransactionId(int lastTransactionID) { IDGenerator::lastTransactionID = lastTransactionID; }

int IDGenerator::generateBookID() {
    return ++lastBookID;
}

int IDGenerator::generateUserID() {
    return ++lastUserID;
}

int IDGenerator::generateTransactionID() {
    return ++lastTransactionID;
}