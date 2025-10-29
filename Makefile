CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build

TARGET = $(BUILD_DIR)/main.o
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/utils/logger.cpp $(SRC_DIR)/core/http_server.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(SRCS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
