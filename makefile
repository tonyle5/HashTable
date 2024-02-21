#The executable file is in the build directory. The source files are in the src directory.

SRC_DIR = src
BUILD_DIR = build

CXX = g++
CXXFLAGS = -g -Wall -std=c++17

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/myUtil/*.cpp) $(wildcard $(SRC_DIR)/table/*.cpp) $(wildcard $(SRC_DIR)/website/*.cpp)

# Generate a list of object files by replacing .cpp with .o
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean copyData

# The default target
all: program copyData

# Rule to build the final executable
program: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/program

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to copy *.txt file(s) to build directory
copyData: $(SRC_DIR)/websites.txt
	cp $< $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
