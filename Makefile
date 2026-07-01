CXX = g++
TARGET = js
SRCS = main.cpp JSONlang.cpp

$(TARGET): $(SRCS)
	$(CXX) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)
