CXX = g++
CXXFLAGS = -Wall -std=c++17
INCLUDES = -I.
SRCS = main.cpp Tree.cpp ConcreteTrees.cpp TreeFactory.cpp ForestManager.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = forest_sim

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)