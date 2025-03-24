# Đường dẫn đến thư mục chứa các file header
INC_DIR = ./  # Thêm đường dẫn tới thư mục chứa các file header của bạn nếu cần

# Biến chứa các file nguồn của chương trình
SRC = Customer.cpp Manager.cpp main.cpp

# Biến chứa các file header
HEADERS = Customer.h Manager.h CLI.h Common_Inc.h

# Biến chứa thư viện nlohmann/json
JSON_LIB = /path/to/nlohmann/json.hpp  # Đảm bảo bạn chỉ định đúng đường dẫn đến json.hpp

# Tên file thực thi cuối cùng
TARGET = program

# Cờ biên dịch cho GCC
CXXFLAGS = -std=c++11 -I$(INC_DIR)  # Đảm bảo thêm flag để bao gồm thư mục header

# Cờ liên kết (link) thư viện nlohmann/json
LDFLAGS = 

# Các file đối tượng (.o)
OBJ = $(SRC:.cpp=.o)

# Mục tiêu mặc định: biên dịch và liên kết
all: $(TARGET)

# Quy tắc để biên dịch file .cpp thành file .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Quy tắc liên kết các file đối tượng thành file thực thi
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Quy tắc để làm sạch các file biên dịch
clean:
	rm -f $(OBJ) $(TARGET)

# Quy tắc để chạy chương trình (nếu cần)
run: $(TARGET)
	./$(TARGET)

