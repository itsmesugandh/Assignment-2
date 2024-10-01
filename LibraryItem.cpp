#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <cstring>
#include <cctype>
#include <limits>
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;

static int ID = 1;          // Added a global variable for ID
const int MAX_ITEMS = 500; // Added a global variable for max number of items in the library

class LibraryItem
{
public:
    virtual void printDetails() const = 0;
    virtual ~LibraryItem() {}
};
#endif


