# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -g

# Source files
SOURCES = main.cpp Book.cpp User.cpp Journals.cpp PublicationRank.cpp Library.cpp classFunctions.cpp functions.cpp LibraryItem.cpp
# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
EXECUTABLE = Output

# Default target
all: compile run

# Compile the code
compile: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Run the program
run: compile
	./$(EXECUTABLE)

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

