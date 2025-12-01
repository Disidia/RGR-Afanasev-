#include "fileutils.h"
#include <fstream>
#include <iterator>
#include <iostream>

using namespace std;

string readFile(const string &filename) {
	ifstream f(filename.c_str(), ios::binary);
	if (!f) {
		return "";
	}
	return string((std::istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
}


bool writeFile(const string &filename, const string &data) {
	ofstream f(filename.c_str(), ios::binary);
	if (!f) {
		cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
		return false;
	}
	f << data;
	return true;
}
