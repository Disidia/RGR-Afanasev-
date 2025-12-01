#include "vigenere.h"
#include <string>

using namespace std;

string vigenereEncrypt(const string &text, const string &key) {
    if (key.empty()) return text;

    string result;
    result.reserve(text.size());

    for (size_t i = 0, j = 0; i < text.size(); ++i) {
        unsigned char c = (unsigned char)text[i];
        unsigned char k = (unsigned char)key[j % key.size()];

        unsigned char encrypted = (c + k) % 256;
        result.push_back((char)encrypted);

        j++;
    }

    return result;
}

string vigenereDecrypt(const string &text, const string &key) {
    if (key.empty()) return text;

    string result;
    result.reserve(text.size());

    for (size_t i = 0, j = 0; i < text.size(); ++i) {
        unsigned char c = (unsigned char)text[i];
        unsigned char k = (unsigned char)key[j % key.size()];

        unsigned char decrypted = (c - k + 256) % 256;
        result.push_back((char)decrypted);

        j++;
    }

    return result;
}

