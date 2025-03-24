
#include "Customer.h"
Customer::Customer(string name_ = "Unknown",int Car_type_ = Unknown, string ID_="Unknown",string Phone_number_ ="Unknown",int Repair_status_= STAT_ARNORMAL)
: name (name_),Car_type(Car_type_),ID(ID_),Phone_number(Phone_number_),Repair_status(Repair_status_){}
Customer::~Customer(){}
void Customer::name_setter(string name){
    this->name = name;
}
void Customer::Car_type_setter(int Car_type){
    this->Car_type = Car_type;
}
void Customer::ID_setter(int ID){
    this->ID = ID;
}
void Customer::Phone_setter(string phone_number){
    this->Phone_number = phone_number;
}
void Customer::Repair_status_setter(int repr_status){
    this->Repair_status = repr_status;
}
string Customer::name_getter()const{
    return name;
}
int Customer::Car_type_getter()const{
    return Car_type;
}
string Customer::ID_getter()const{
    return ID;
}
string Customer::Phone_getter()const{
    return Phone_number;
}
int Customer::Repair_status_getter()const{
    return Repair_status;
}
Customer Customer::get_all_customer_infor()const{
    return *this;
}
    /* 2 Function to work with json file*/
    /*Convert object to json file's format */
nlohmann::json Customer::to_json(){
    return {
        {"Customer's Name",name},
        {"Type of car",Car_type},
        {"ID",ID},
        {"Contact",Phone_number},
        {"Repairing Status",Repair_status}
    };
}
    /*Convert json format to Object*/
    Customer Customer::from_json(const nlohmann::json& json_){
        return Customer(
            json_["Customer's Name"].get<string>(),
            json_["Type of car"].get<int>(),
            json_["ID"].get<string>(),
            json_["Contact"].get<string>(),
            json_["Repairing Status"].get<int>()
        );
    }

    ComparisonResult Customer::operator==(const Customer& other) const{
        if (this->name == other.name &&
            this->ID == other.ID&&
            this->Car_type == other.Car_type&&
            this->Phone_number == other.Phone_number&&
            this->Repair_status == other.Repair_status){
                return SAME_ALL_INFORMATION;
            }
        else if(this->ID == other.ID){
            return SAME_ID;
        }
        else if(this->Phone_number==other.Phone_number){
            return SAME_PHONE_NUMBER;
        }
        return NOT_EXIST;
    }