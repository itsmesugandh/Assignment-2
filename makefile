# Define the compiler

CXX = g++


# Define the flags

CXXFLAGS = -std=c++11 -Wall -Wextra


# Define the source and object files

SRC = mycode3.cpp

OBJ = $(SRC:.cpp=.o)


# Define the executable

EXEC = hierarchy


# Default target

all: $(EXEC)


# Compile the source code

$(OBJ): $(SRC)

	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(OBJ)


# Link the object code

$(EXEC): $(OBJ)

	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)


# Clean up

clean:

	rm -f $(OBJ) $(EXEC)


# Run the executable

run: $(EXEC)

	./$(EXEC)


# Dependencies

depend: .depend


.depend: $(SRC)

	rm -f ./.depend

	$(CXX) $(CXXFLAGS) -MM $^ >> ./.depend


include .depend
