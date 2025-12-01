#ifndef AUTH_H
#define AUTH_H

using namespace std;

#include <string>


bool userExists(const string &username);
bool registerUser(const string &username, const string &password);
bool checkCredentials(const string &username, const string &password);


#endif // AUTH_H
