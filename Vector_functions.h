#ifndef GIT_HOMEWORK1_VECTOR_FUNCTIONS_H
#define GIT_HOMEWORK1_VECTOR_FUNCTIONS_H

#include <fstream>
#include <string>
#include <vector>
#include "Functions.h"

using namespace std;

vector<string> GetConfig(string path = "data.cfg") {
    vector<string> result;

    ifstream file;
    file.open(path);

    string str;
    while (getline(file, str)) {
        result.push_back(str);
    }

    return result;
}

string FindValue(vector<string> input, string key) {
    char delimiter = '=';
    for (string item : input) {
        string k = Parser(&item, delimiter);
        string v = item;

        if (k == key) {
            return v;
        }
    }

    return "";
}

vector<string> GetText(string path) {
    vector<string> text;

    ifstream file;
    file.open(path);

    while (!file.eof()) {
        string str;
        getline(file, str);
        text.push_back(str);
    }

    file.close();

    return text;
}

vector<string> TextReplacement(vector<string> input){
    string str;

    for (int i = 0; i < input.size(); ++i) {
        str = input[i];
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == '-' || str[j] == ' '){
                str[j] = '_';
            }
        }

        input[i] = str;
        str.clear();
    }
    return input;
}

void CopyTextToFile(vector<string> input, string output_path){
    ofstream file;
    file.open(output_path, ios_base::trunc);

    for (int i = 0; i < input.size(); ++i) {
        file << input[i] << endl;
    }


    file.close();
}



#endif //GIT_HOMEWORK1_VECTOR_FUNCTIONS_H
