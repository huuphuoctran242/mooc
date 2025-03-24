#include "Manager.h"
/*To do:
    - Them 1 object Customer moi
*/
void Manager::add_customer(const Customer& customer_){
    customers.push_back(customer_);
}
/*Save the all customer in vector to file */
// void Manager::save_to_file(const string file_name){
//     nlohmann::json json;
//     for(int index =0; index<customers.size();index++){
//         json.push_back(customers[index].to_json());
//     }
//     //Create a object of ofstream
//     std::ofstream file(file_name,ios::app);
//     if(file.is_open()){
//         file<<json.dump(4);// 4 is a mode
//     }else cout<<"Error: Can not open file"<<endl;
// }
void Manager::save_to_file(const string& file_name) {
    nlohmann::json json; // object cua json
    std::ifstream file_in(file_name);
    if (file_in.is_open()) {
        nlohmann::json json_existing;
        file_in >> json_existing; // Đọc dữ liệu cũ vào
        json = json_existing;  // Giữ lại dữ liệu cũ
        file_in.close();  // Đóng file sau khi đọc
    }

    // Thêm khách hàng mới vào json
    for (auto& customer : customers) {
        json.push_back(customer.to_json());
    }
    std::ofstream file_out(file_name);
    if (file_out.is_open()) {
        file_out << json.dump(4);  // Ghi dữ liệu với định dạng JSON (4 là số lượng khoảng trắng)
        file_out.close();  
    } else {
        std::cout << "Error: Cannot open file for writing" << std::endl;
    }
}

/**/
void Manager::load_from_file(const string& file_name){
    /*To do:
    - Tao object cua ifstream de doc file
    - tao object file json
    - Luu gia tri sau khi convert vao customer*/
    std::ifstream file(file_name);
    if(file.is_open()){
        nlohmann::json json;
        file >> json; //Doc tu file dua vao json
        customers.clear();   
        for(const auto& item : json){
            customers.push_back(Customer::from_json(item));
        }
    }
    else {
        std::cout << "Error: Cannot open file for reading" << std::endl;
    }
}

Customer* Manager::find_customer_with_name(const string& name_){
    for(auto& customer : customers){
        if(customer.name_getter()== name_){
            return &customer;
        }      
    }
    return nullptr;
}
Customer* Manager::find_customer_with_ID(const string& ID){
    for(auto& customer: customers){
        if(customer.ID_getter() == ID){
            return &customer;
        }
    }
    return nullptr;
}
Customer* Manager::find_customer_with_phone_number(const string& number){
    for(auto& customer : customers){
        if(customer.Phone_getter()==number){
            return &customer;
        }
    }
    return nullptr;
}

/*Delete a member of vector customers  */
//using std::remove() and erase()

bool Manager::delete_customer_by_ID(const string& ID_){
/*Todo:
    - Quet cac phan tu trong vector, dung std::remove_if de tim cac 
    object co ID can tim, sau do di chuyen cac object khong can xoa len 
    dau vector, tra ve 1 iterator den vi tri bat dau cua phan tu bi xoa
    - Xoa ca phan tu vi tri iterator tra ve o tren bang erase()*/
    auto it = remove_if(customers.begin(),customers.end(),[ID_](const Customer& obj){
        return obj.ID_getter() == ID_;
    });
    if(it !=customers.end()){ //Tim thay phan tu can xoa
        customers.erase(it,customers.end());
        return true;
    }
    return false; 
}
void Manager::delete_all_customer(){
    customers.erase(customers.begin(),customers.end());
}
vector<Customer>* Manager::list_customers_getter(){
    return &customers;
}