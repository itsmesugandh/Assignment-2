#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>

using namespace std;

bool isNumeric(const string&);
string splitCSVLine(const string&, string*, int);
string splitLine(const string&, string*, int);
string splitString(const string&, string*, int);
bool isValidUserName(const string&);
string getField(const string&, int);

#endif
