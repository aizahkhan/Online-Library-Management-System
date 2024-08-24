#include "Admin.h"
#include "Book.h"
#include "User.h"
#include "Transaction.h"
#include "Library.h"
#include "TransactionReport.h"


int main() {
    Library marsLibrary("Mars Library");

    std::ifstream libraryFile("library.txt");
    if (libraryFile.is_open()) {
        marsLibrary.loadFromFile("library.txt");
        libraryFile.close();
    } else {
        std::cout << "No existing library file found. Creating a new library." << std::endl;
    }

    std::string title = R"(
         .--.                   .---.
     .---|__|           .-.     |~~~|
  .--|===|--|_          |_|     |~~~|--.
  |  |===|  |'\     .---!~|  .--|   |--|
  |%%|   |  |.'\    |===| |--|%%|   |  |
  |%%|   |  |\.'\   |   | |__|  |   |  |
  |  |   |  | \  \  |===| |==|  |   |  |
  |  |   |__|  \.'\ |   |_|__|  |~~~|__|
  |  |===|--|   \.'\|===|~|--|%%|~~~|--|
  ^--^---'--^    `-'`---^-^--^--^---'--' 


   _    _      _                          
  | |  | |    | |                         
  | |  | | ___| | ___ ___  _ __ ___   ___ 
  | |/\| |/ _ \ |/ __/ _ \| '_ ` _ \ / _ \
  \  /\  /  __/ | (_| (_) | | | | | |  __/
   \/  \/ \___|_|\___\___/|_| |_| |_|\___|)";

    std::string menu = R"(
+++++++++++++++++++++++++
| 1.  Add Book          |
-------------------------
| 2.  Remove Book       |
-------------------------
| 3.  Add User          |
-------------------------
| 4.  Remove User       |
-------------------------
| 5.  Borrow Book       |
-------------------------
| 6.  Return Book       |
-------------------------
| 7.  Reward User       |
-------------------------
| 8.  Reward Admin      |
-------------------------
| 9.  View Books        |
-------------------------
| 10. View Users        |
-------------------------
| 11. View Transactions |
-------------------------
| 12. Exit              |
+++++++++++++++++++++++++
Enter your choice: )";


  std::vector<User*> users;
  std::string userFilename = "users.txt";

  std::ifstream userFile(userFilename);
  if (userFile.is_open()) {
    int numUsers;
    userFile >> numUsers;
    userFile.ignore(); 

    for (int i = 0; i < numUsers; i++) {
      User* user = new User("", 0.0f, 0);
      user->loadFromFile(userFilename + "." + std::to_string(i + 1));
      users.push_back(user);
    }
    userFile.close();
  } 
  else {
    std::cout << "No existing user file found. Creating a new user file." << std::endl;
  }

  Admin admin("John Doe", 5, 50000.0f, &marsLibrary);
  std::ifstream adminFile("admin.txt");
  if (adminFile.is_open()) {
    admin.loadFromFile("admin.txt");
    adminFile.close();
  } 
  else {
    std::cout << "No existing admin file found. Creating a new admin." << std::endl;
  }

  bool running = true;
  while (running) {
    std::cout << std::endl << title << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << menu << std::endl;

    int choice;
    std::cin >> choice;
    std::cin.ignore(); 

    switch (choice) {
      case 1: {
        std::string title, genre, author;
        float size;
        std::cout << "Enter book title: ";
        std::getline(std::cin, title);
        std::cout << "Enter book genre: ";
        std::getline(std::cin, genre);
        std::cout << "Enter book author: ";
        std::getline(std::cin, author);
        std::cout << "Enter book size (MB): ";
        std::cin >> size;
        std::cin.ignore();
        Book* newBook = new Book(title, genre, author, size);
        marsLibrary.addBook(newBook);
        std::cout << "Book added successfully!" << std::endl;
        break;
      }
      case 2: {
        int bookID;
        std::cout << "Enter book ID to remove: ";
        std::cin >> bookID;
        std::cin.ignore();
        marsLibrary.removeBook(bookID);
        std::cout << "Book removed successfully!" << std::endl;
        break;
      }
      case 3: {
        std::string name;
        float balance;
        int loyaltyTier;
        std::cout << "Enter user name: ";
        std::getline(std::cin, name);
        std::cout << "Enter user balance: ";
        std::cin >> balance;
        std::cin.ignore();
        std::cout << "Enter user loyalty years: ";
        std::cin >> loyaltyTier;
        std::cin.ignore();
        User* newUser = new User(name, balance, loyaltyTier);
        marsLibrary.addUser(newUser);
        users.push_back(newUser);
        std::cout << "User added successfully!" << std::endl;
        break;
      }
      case 4: {
        int userID;
        std::cout << "Enter user ID to remove: ";
        std::cin >> userID;
        std::cin.ignore();
        marsLibrary.removeUser(userID);
        std::cout << "User removed successfully!" << std::endl;
        break;
      }
      case 5: {
        int userID, bookID;
        std::cout << "Enter user ID to borrow a book: ";
        std::cin >> userID;
        std::cout << "Enter book ID to borrow: ";
        std::cin >> bookID;
        std::cin.ignore();
        if (marsLibrary.borrowBook(userID, bookID)) {
          std::cout << "Book borrowed successfully!" << std::endl;
        } 
        else {
          std::cout << "Failed to borrow the book." << std::endl;
        }
        break;
      }
      case 6: {
        int userID, bookID;
        std::cout << "Enter user ID to return a book: ";
        std::cin >> userID;
        std::cout << "Enter book ID to return: ";
        std::cin >> bookID;
        std::cin.ignore();
        if (marsLibrary.returnBook(userID, bookID)) {
          std::cout << "Book returned successfully!" << std::endl;
        } 
        else {
          std::cout << "Failed to return the book." << std::endl;
        }
        break;
      }
      case 7: {
        int userID;
        std::cout << "Enter user ID to reward: ";
        std::cin >> userID;
        std::cin.ignore();
        for (User* user : users) {
          if (user->getID() == userID) {
            admin.rewardUser(user);
            break;
          }
        }
        break;
      }
      case 8: {
        admin.rewardAdmin(&admin);
        break;
      }
      case 9: {
        marsLibrary.printBooks(); 
        break;
      }
      case 10: {
        marsLibrary.printUsers(); 
        break;
      }
      case 11: {
        int userID;
        std::cout << "Enter user ID to view transactions: ";
        std::cin >> userID;
        std::cin.ignore();
        TransactionReport::generateReport(marsLibrary.getTransactions(), marsLibrary.getBooks(), userID);
        break;
      }
      case 12: {
        running = false;
        std::cout << "Exiting the program..." << std::endl;
        break;
        default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
      }
  }
  
  marsLibrary.saveToFile("library.txt");
  
  std::ofstream userOutputFile(userFilename);
  if (userOutputFile.is_open()) {
    userOutputFile << users.size() << std::endl;
    for (User* user : users) {
      user->saveToFile(userFilename + "." + std::to_string(user->getID()));
    }
    userOutputFile.close();
  }

  admin.saveToFile("admin.txt");

  for (User* user : users) {
    delete user;
  }

    return 0;
}
}