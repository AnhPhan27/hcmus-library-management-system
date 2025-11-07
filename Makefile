# Makefile for Library Management System

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Target executable
TARGET = library_manager

# Source files
SOURCES = main.cpp docgia.cpp sach.cpp muontra.cpp thongke.cpp utils.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Build target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CXXFLAGS += -DDEBUG -g3
debug: clean $(TARGET)

# Release build
release: CXXFLAGS += -O2 -DNDEBUG
release: clean $(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  clean    - Remove build files"
	@echo "  run      - Build and run the program"
	@echo "  debug    - Build with debug flags"
	@echo "  release  - Build optimized release version"
	@echo "  help     - Show this help message"

# Phony targets
.PHONY: all clean run debug release help

# Dependencies
main.o: main.cpp docgia.h sach.h muontra.h thongke.h
docgia.o: docgia.cpp docgia.h
sach.o: sach.cpp sach.h
muontra.o: muontra.cpp muontra.h docgia.h sach.h
thongke.o: thongke.cpp thongke.h docgia.h sach.h muontra.h utils.h
utils.o: utils.cpp utils.h