#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include "Common_Inc.h"
using namespace std;

class Customer{
private:
    string name;
    int Car_type;
    string ID;
    string Phone_number;
    int Repair_status;
public:
    Customer(string name_ ,int Car_type_ , string ID_,string Phone_number_,int Repair_status_);
    ~Customer();
    ComparisonResult operator==(const Customer& other) const;
    void name_setter(string name);
    void Car_type_setter(int Car_type);
    void ID_setter(int ID);
    void Phone_setter(string phone_number);
    void Repair_status_setter(int repr_status);
    string name_getter() const;
    int Car_type_getter()const;
    string ID_getter()const;
    string Phone_getter()const;
    int Repair_status_getter() const;
    Customer get_all_customer_infor()const;

    /* 2 Function to work with json file*/
    /*Convert object to json file's format */
    nlohmann::json to_json();
    /*Convert json format to Object*/
    static Customer from_json(const nlohmann::json& json_);
};

#endif 