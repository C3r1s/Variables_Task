#ifndef GIT_HOMEWORK1_FUNCTIONS_H
#define GIT_HOMEWORK1_FUNCTIONS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int GetNumberOfLinesInFile(string path) {
    int count = 0;

    string str;

    ifstream file;
    file.open(path);

    while (getline(file, str)) {
        ++count;
    }

    file.close();
    return count;
}

string* FillArrayLinesFromFile(string path, int *size) {
    *size = GetNumberOfLinesInFile(path);
    string *result = new string[*size];

    ifstream file;
    file.open(path);

    string str;
    int i = 0;

    while (getline(file, str)) {
        result[i++] = str;
    }

    file.close();
    return result;
}

string Parser(string* str, char delimiter) {
    auto position = str->find(delimiter);
    auto result = str->substr(0, position);
    *str = str->substr(position + 1);

    return result;
}

void WriteArrayToFile(string path, string *array, int size) {
    ofstream file;
    file.open(path, ios_base::trunc);

    for (int i = 0; i < size; ++i) {
        file << array[i] << endl;
    }

    file.close();
}

void Write(string &source, string &str) {
    ofstream file;
    file.open(source);
    file << str;
    file.close();
}

void PrintArray(string* array, int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << "]" << endl << endl;
}

#endif //GIT_HOMEWORK1_FUNCTIONS_H
