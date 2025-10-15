CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17 -O2

TARGET = SearchNewBooks
SRCS = SearchNewBooks.cpp book.cpp search.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) found.dat

tests: test.o book.o search.o
	$(CXX) $(CXXFLAGS) -o $@ $^

test.o: test.cpp book.h search.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o