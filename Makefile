# Name of target app
TARGET = Read_file

# Compiler
CXX = g++

# Debbug flag
CXXFLAGS = -g

# Source
SRC = Read_file.cpp

# Comlile 
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean app
clean:
	rm -f $(TARGET)