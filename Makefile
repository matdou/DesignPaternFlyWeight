CXX = g++
CXXFLAGS = -Wall -std=c++17
INCLUDES = -Isrc

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source files and object files explicitly listed
SRCS = $(SRCDIR)/main.cpp $(SRCDIR)/Tree.cpp $(SRCDIR)/ConcreteTrees.cpp $(SRCDIR)/TreeFactory.cpp $(SRCDIR)/ForestManager.cpp
OBJS = $(OBJDIR)/main.o $(OBJDIR)/Tree.o $(OBJDIR)/ConcreteTrees.o $(OBJDIR)/TreeFactory.o $(OBJDIR)/ForestManager.o

# Target executable
TARGET = $(BINDIR)/forest_sim

# Phony targets for all, clean, and directories
.PHONY: all clean directories

all: directories $(TARGET)

directories:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)

# Linking the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compiling source files into object files
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Tree.o: $(SRCDIR)/Tree.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRCDIR)/Tree.cpp -o $(OBJDIR)/Tree.o

$(OBJDIR)/ConcreteTrees.o: $(SRCDIR)/ConcreteTrees.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRCDIR)/ConcreteTrees.cpp -o $(OBJDIR)/ConcreteTrees.o

$(OBJDIR)/TreeFactory.o: $(SRCDIR)/TreeFactory.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRCDIR)/TreeFactory.cpp -o $(OBJDIR)/TreeFactory.o

$(OBJDIR)/ForestManager.o: $(SRCDIR)/ForestManager.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(SRCDIR)/ForestManager.cpp -o $(OBJDIR)/ForestManager.o

# Cleaning up
clean:
	@rm -rf $(OBJDIR) $(BINDIR)
