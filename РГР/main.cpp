#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <cctype>
#include <iterator>
#include <sstream>
#include <limits>
#include <windows.h>

#include "fileutils.h"
#include "binary.h"
#include "gronsfeld.h"
#include "vigenere.h"
#include "auth.h"
#include "menu.h"

using namespace std;

int main() {
	SetConsoleCP(1251);  // Входная кодировка
    SetConsoleOutputCP(1251);  // Выходная кодировка
    cout << "=== Система шифрования (C++) ===\n";

    while (true) {
        cout << "\n1 - Вход\n2 - Регистрация\n0 - Выход\nВыберите действие: ";
        int act;
        if (!(cin >> act)) break;
        cin.ignore();

        if (act == 0) return 0;

        if (act == 2) {
            string uname, pwd;
            cout << "Регистрация. Имя пользователя: ";
            getline(cin, uname);
            cout << "Пароль: ";
            getline(cin, pwd);
            if (registerUser(uname, pwd))
                cout << "Пользователь зарегистрирован.\n";
            else
                cout << "Ошибка: пользователь существует или неверные данные.\n";
            continue;
        }

        if (act == 1) {
            string uname, pwd;
            cout << "Вход. Имя пользователя: ";
            getline(cin, uname);
            cout << "Пароль: ";
            getline(cin, pwd);

            if (checkCredentials(uname, pwd)) {
                cout << "Вход успешен. Добро пожаловать, " << uname << "!\n";

                bool running = true;
                while (running) {
                    showMenu();
                    int choice;
                    if (!(cin >> choice)) break;
                    cin.ignore();

                    if (choice == 0) { running = false; break; }

                    else if (choice == 1) {
                        cout << "1 - Ручной ввод\n2 - Загрузить из файла\nВыберите: ";
                        int sub;
                        if (!(cin >> sub)) { cin.clear(); cin.ignore(); continue; }
                        cin.ignore();

                        if (sub == 1) {
                            string text, line;
                            cout << "Введите текст (пустая строка - завершить):\n";
                            while (true) {
                                getline(cin, line);
                                if (line.empty()) break;
                                text += line + "\n";
                            }
                            if (text.size() > 0 && text[text.size()-1] == '\n')
                                text = text.substr(0, text.size()-1);
                            writeFile("input.txt", text);
                            cout << "Текст сохранён в input.txt\n";
                        } else if (sub == 2) {
                            string fname;
                            cout << "Введите путь к файлу: ";
                            getline(cin, fname);
                            string content = readFile(fname);
                            if (content.empty())
                                cout << "Не удалось прочитать файл.\n";
                            else {
                                writeFile("input.txt", content);
                                cout << "Содержимое скопировано в input.txt\n";
                            }
                        }
                    }

                    else if (choice == 2) {
                        int method = chooseMethodPrompt();
                        if (method == -1) continue;
                        string key;
                        if (method != 1) {
                            cout << "Введите пароль/ключ: ";
                            getline(cin, key);
                        }

                        string text = readFile("input.txt");
                        if (text.empty()) { cout << "input.txt пуст или не найден.\n"; continue; }

                        string encoded;
                        if (method == 1) encoded = encodeBinary(text);
                        else if (method == 2) encoded = gronsfeldEncrypt(text, key);
                        else if (method == 3) encoded = vigenereEncrypt(text, key);
                        else { cout << "Неверный метод!\n"; continue; }

                        writeFile("encoded.txt", encoded);
                        cout << "Файл зашифрован и записан в encoded.txt\n";
                        cout << "--- Результат ---\n";
                        if (encoded.size() > 1000)
                            cout << encoded.substr(0,1000) << "\n...(всего " << encoded.size() << " символов)\n";
                        else
                            cout << encoded << "\n";
                    }

                    else if (choice == 3) {
                        int method = chooseMethodPrompt();
                        if (method == -1) continue;
                        string key;
                        if (method != 1) {
                            cout << "Введите пароль/ключ: ";
                            getline(cin, key);
                        }

                        string text = readFile("encoded.txt");
                        if (text.empty()) { cout << "encoded.txt пуст или не найден.\n"; continue; }

                        string decoded;
                        if (method == 1) decoded = decodeBinary(text);
                        else if (method == 2) decoded = gronsfeldDecrypt(text, key);
                        else if (method == 3) decoded = vigenereDecrypt(text, key);
                        else { cout << "Неверный метод!\n"; continue; }

                        writeFile("decoded.txt", decoded);
                        cout << "Файл расшифрован и записан в decoded.txt\n";
                        cout << "--- Результат ---\n";
                        if (decoded.size() > 1000)
                            cout << decoded.substr(0,1000) << "\n...(всего " << decoded.size() << " символов)\n";
                        else
                            cout << decoded << "\n";
                    }

                    else if (choice == 4) {
                        string filename;
                        cout << "Введите имя файла: ";
                        getline(cin, filename);
                        string content = readFile(filename);
                        if (content.empty()) cout << "Файл пуст или не найден.\n";
                        else cout << "\nСодержимое файла:\n" << content << "\n";
                    }

                    else if (choice == 5) {
                        string uname2, pwd2;
                        cout << "Имя нового пользователя: ";
                        getline(cin, uname2);
                        cout << "Пароль: ";
                        getline(cin, pwd2);
                        if (registerUser(uname2, pwd2))
                            cout << "Пользователь зарегистрирован.\n";
                        else
                            cout << "Ошибка регистрации.\n";
                    }
                }
            } else {
                cout << "Неверное имя пользователя или пароль.\n";
            }
        }
    }

    return 0;
}

