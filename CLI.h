#ifndef _CLI_H_
#define _CLI_H_
#include "Common_Inc.h"
class CLI{
public:
    void display_menu(){
        std::cout << "1. Add customer\n";
        std::cout << "2. Show all customers\n";
        std::cout << "3. Find customer by ID\n";
        std::cout << "4. Find customer by name\n";
        std::cout << "5. Find customer by phone number\n";
        std::cout << "6. Delete customer\n";
        std::cout << "8. Save data\n";
        std::cout << "9. Exit\n";
    }
    int get_user_input(){
        int choice =0;       
        while (true) {
            std::cout << "Enter your choice (1-9): " << std::endl;
            std::cin >> choice;
            if (choice >= 1 && choice <= 9) {
                break;
            }   
            std::cout << "Invalid Choice! Please enter a number between 1 and 9." << std::endl;
        }
        return choice;
    }
};


#endif