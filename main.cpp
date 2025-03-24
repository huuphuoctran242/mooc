#include "CLI.h"
#include "Manager.h"

int main(){
    Manager manager;
    CLI CLI;
    Customer* ptr_customer = nullptr;
    manager.load_from_file("Data.json"); // Load dữ liệu từ file ngay khi bắt đầu
    vector<Customer>* ptr_ = manager.list_customers_getter();
    while (true) {
        CLI.display_menu();
        int choice = CLI.get_user_input();

        switch (choice) {
            case 1: { // Add new Customer
                int car_type = Unknown;
                int repair_status = STAT_ARNORMAL;
                std::string name, phone, ID;
            
                std::cout << "Enter name: ";
                std::cin >> std::ws;  // Loại bỏ khoảng trắng trước khi nhập chuỗi
                std::getline(std::cin, name);
            
                std::cout << "Enter ID: ";
                std::getline(std::cin, ID);
            
                std::cout << "Enter phone: ";
                std::getline(std::cin, phone);

                std::cout << "Enter car type: ";
                std::cin >> car_type;
                std::cin.ignore();  // Đọc bỏ dấu newline còn lại trong input buffer
                std::cout << "Enter repair status: ";
                std::cin >> repair_status;
                std::cin.ignore(); 

                Customer customer(name, car_type, ID, phone, repair_status);
                bool exists = false;

                // Kiểm tra trùng lặp
                for (auto& customer_ : *ptr_) {
                    ComparisonResult result = (customer_ == customer);  // So sánh khách hàng
                    switch (result) {
                        case SAME_ALL_INFORMATION:
                            std::cout << "Customer has already existed" << std::endl;
                            exists = true;
                            break;
                        case SAME_ID:
                            std::cout << "ID is used" << std::endl;
                            exists = true;
                            break;
                        case SAME_PHONE_NUMBER:
                            std::cout << "Phone number is used" << std::endl;
                            exists = true;
                            break;
                        case NOT_EXIST:
                            break;
                    }
                    if (exists) break;  // Dừng kiểm tra nếu tìm thấy khách hàng trùng lặp
                }

                if (!exists) {
                    manager.add_customer(customer);
                    manager.save_to_file("Data.json");  // Lưu danh sách cập nhật vào tệp
                    std::cout << "Add new customer successfully" << std::endl;
                }
                break;
            }

            case 2: { // See all customers
                std::cout << "=====================================" << std::endl;
                std::cout << "======= SHOW ALL CUSTOMERS ==========" << std::endl;
                std::cout << "=====================================\n" << std::endl;
                for (auto& cus_ : *ptr_) {
                    std::cout << "=====================================" << std::endl;
                    std::cout << "Name         :" << cus_.name_getter() << std::endl;
                    std::cout << "ID           :" << cus_.ID_getter() << std::endl;
                    std::cout << "Type of car  :" << cus_.Car_type_getter() << std::endl;
                    std::cout << "Phone number :" << cus_.Phone_getter() << std::endl;
                    std::cout << "Repair status:" << cus_.Repair_status_getter() << std::endl;
                }
                std::cout << "=====================================\n" << std::endl;
                break;
            }           
            case 3:{
                std::string ID_;
                std::cout << "Enter ID: ";
                std::cin >> std::ws;
                std::getline(std::cin, ID_);
                ptr_customer = manager.find_customer_with_ID(ID_);
                if(ptr_customer ==nullptr){
                    std::cout << "NO DATA FOUND !" << std::endl;
                    break;
                }else {
                    std::cout << "=====================================" << std::endl;
                    std::cout << "Name         :" << ptr_customer->name_getter() << std::endl;
                    std::cout << "ID           :" << ptr_customer->ID_getter() << std::endl;
                    std::cout << "Type of car  :" << ptr_customer->Car_type_getter() << std::endl;
                    std::cout << "Phone number :" << ptr_customer->Phone_getter() << std::endl;
                    std::cout << "Repair status:" << ptr_customer->Repair_status_getter() << std::endl;
                    std::cout << "=====================================\n" << std::endl;
                } break;                              
            }
            case 4:{
                std::string name_;
                std::cout << "Enter your name: ";
                std::cin >> std::ws;
                std::getline(std::cin, name_);
                ptr_customer = manager.find_customer_with_name(name_);
                if(ptr_customer ==nullptr){
                    std::cout << "NO DATA FOUND !" << std::endl;
                    break;
                }else {
                    std::cout << "=====================================" << std::endl;
                    std::cout << "Name         :" << ptr_customer->name_getter() << std::endl;
                    std::cout << "ID           :" << ptr_customer->ID_getter() << std::endl;
                    std::cout << "Type of car  :" << ptr_customer->Car_type_getter() << std::endl;
                    std::cout << "Phone number :" << ptr_customer->Phone_getter() << std::endl;
                    std::cout << "Repair status:" << ptr_customer->Repair_status_getter() << std::endl;
                    std::cout << "=====================================\n" << std::endl;
                } break;                              
            }
            case 5:{
                std::string phone_;
                std::cout << "Enter your phone number: ";
                std::cin >> std::ws;
                std::getline(std::cin, phone_);
                ptr_customer = manager.find_customer_with_name(phone_);
                if(ptr_customer ==nullptr){
                    std::cout << "NO DATA FOUND !" << std::endl;
                    break;
                }else {
                    std::cout << "=====================================" << std::endl;
                    std::cout << "Name         :" << ptr_customer->name_getter() << std::endl;
                    std::cout << "ID           :" << ptr_customer->ID_getter() << std::endl;
                    std::cout << "Type of car  :" << ptr_customer->Car_type_getter() << std::endl;
                    std::cout << "Phone number :" << ptr_customer->Phone_getter() << std::endl;
                    std::cout << "Repair status:" << ptr_customer->Repair_status_getter() << std::endl;
                    std::cout << "=====================================\n" << std::endl;
                } break;                              
            }
            case 9: { // Exit application
                std::cout << "Exited the Application!" << std::endl;
                return 0;  // Thoát khỏi ứng dụng
            }

            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
        }
    }
}
