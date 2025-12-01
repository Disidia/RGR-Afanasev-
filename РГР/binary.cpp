#include "binary.h"
#include <bitset>

using namespace std;

string encodeBinary(const string &text) {
	string bits;
	for (size_t i = 0; i < text.size(); ++i) {
		unsigned long val = static_cast<unsigned char>(text[i]);
		bitset<8> b(val);
		bits += b.to_string();
	}
	return bits;
}

string decodeBinary(const string &bits) {
	string result;
	for (size_t i = 0; i + 7 < bits.size(); i += 8) {
		string byteStr = bits.substr(i, 8);
		bitset<8> b(byteStr);
		unsigned long v = b.to_ulong();
		result.push_back(static_cast<char>(v));
	}
	return result;
}
