CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
SOURCES := $(wildcard src/*.cpp)
HEADERS := $(wildcard src/*.h)
TARGET := build/example

.PHONY: all run check clean
all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

check: $(TARGET)
	python3 tests/smoke.py

clean:
	rm -rf build
