#include "gronsfeld.h"
#include <cctype>

using namespace std;

string gronsfeldEncrypt(const string &text, const string &key) {
	string result;
	if (key.empty()) return text;
	for (size_t i = 0; i < text.size(); ++i) {
		char kch = key[i % key.size()];
		if (!isdigit(static_cast<unsigned char>(kch))) kch = '0';
		int shift = (kch - '0');
		result.push_back(static_cast<char>((unsigned char)text[i] + shift));
	}
	return result;
}


string gronsfeldDecrypt(const string &text, const string &key) {
	string result;
	if (key.empty()) return text;
	for (size_t i = 0; i < text.size(); ++i) {
		char kch = key[i % key.size()];
		if (!isdigit(static_cast<unsigned char>(kch))) kch = '0';
		int shift = (kch - '0');
		result.push_back(static_cast<char>((unsigned char)text[i] - shift));
	}
	return result;
}
