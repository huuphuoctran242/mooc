#include <iostream>
#include <fstream>
using namespace std;

void Read_file(string& file_name){
    ifstream in_file(file_name);
    if(!in_file){
        cerr<<"Can not open file"<<file_name<<"to read"<<endl;
        return;
    }
    string line;
    while(getline(in_file,line)){
        cout<<line<<endl;
    }
    in_file.close();
}
void Write_to_file(string& file_name){
    ofstream out_file(file_name,ios::app);
    /*Mo tep che do append de ghi vao cuoi tep*/
    if(!out_file){
        cerr<<"Can no open file: "<<file_name<< "to write"<<endl; 
        return;
    }
    cout<<"Enter content to file - enter 'Exit' to finish "<<endl;
    string input;
    while(true){
        getline(cin,input);
        if(input == "Exit") break; // Nhap Exit thi thoat vong lap
        out_file<<input<<endl;    
    }
    out_file.close();
    cout<<"Write data successfully"<<endl;
    

}

int main(){
    string file_name ="test.txt";
    Write_to_file(file_name);
    Read_file(file_name);
    return 0;
}