#ifndef FILEUTILS_H
#define FILEUTILS_H


#include <string>

using namespace std;

string readFile(const string &filename);
bool writeFile(const string &filename, const string &data);


#endif // FILEUTILS_H
