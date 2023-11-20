// Мерекин Артём Валерьевич
// В текстовом файле находятся названия переменных. Но названия эти не соответствуют нашему соглашению об именовании. Вам необходимо создать новый файл с правильными названиями переменных.
// Правильный формат имени переменной: имя_переменной
// В файле имена переменных могут быть следующего вида
//- имя-переменной
//- имя переменной
// Итоговую программу выложить у себя в аккаунте GitHub

#include <string>
#include "Functions.h"
#include "Vector_functions.h"

int main() {

    string input_path = "D:\\Programming\\git_homework1\\variables.txt";
    string output_path = "D:\\Programming\\git_homework1\\variables_output.txt";

    vector<string> text;
    text = GetText(input_path);

    text = TextReplacement(text);
    CopyTextToFile(text, output_path);


    return 0;
}