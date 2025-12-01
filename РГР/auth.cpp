#include "auth.h"
#include <fstream>

using namespace std;

bool userExists(const string &username) {
	ifstream f("users.txt");
	if (!f) return false;
	string line;
	while (getline(f, line)) {
		size_t pos = line.find(':');
		if (pos != string::npos) {
			string u = line.substr(0, pos);
			if (u == username) return true;
		}
	}
	return false;
}


bool registerUser(const string &username, const string &password) {
	if (username.empty() || password.empty()) return false;
	if (userExists(username)) return false;
	ofstream f("users.txt", ios::app);
	if (!f) return false;
	f << username << ":" << password << "\n";
	return true;
}


bool checkCredentials(const string &username, const string &password) {
	ifstream f("users.txt");
	if (!f) return false;
	string line;
	while (getline(f, line)) {
		size_t pos = line.find(':');
		if (pos == string::npos) continue;
		string u = line.substr(0, pos);
		string p = line.substr(pos + 1);
		if (u == username && p == password) return true;
	}
	return false;
}
