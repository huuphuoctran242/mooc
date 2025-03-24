#ifndef _MANAGER_H
#define _MANAGER_H
#include <string>
#include "Common_Inc.h"
#include "Customer.h"
using namespace std;
class Manager{
private: 
    vector<Customer> customers;
public:
    vector<Customer>* list_customers_getter();
    void add_customer(const Customer& cunstomer_);
    void save_to_file(const string& file_name);    
    void load_from_file(const string& file_name);
    Customer* find_customer_with_name(const string& name_);
    Customer* find_customer_with_ID(const string& ID);
    Customer* find_customer_with_phone_number(const string& number);
    bool delete_customer_by_ID(const string& ID); 
    void delete_all_customer();
};


#endif