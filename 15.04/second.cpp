//Дана строка слов, разделенных пробелами. 
//Сформируйте новую строку, удалив пробелы, с которых может начинаться строка, 
//а каждую внутреннюю группу пробелов замените одним пробелом 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string delete_space(string& a) { 
    string result;
    bool n = false;
    for (size_t i = 0; i < a.length(); ++i) {  
        char ch = a[i];
        if (ch == ' ') {
            if (!n && !result.empty()) {
            result += ' ';
            n = true;  // Устанавливаем флаг, что мы в пробеле
        }
        } else {
            result += ch; 
            n = false;  
        }
    }
    return result;
}

int main(){
    string str1 = "           test car     dool  bear doors";

    string a1 = delete_space(str1);  
    std::cout << "Modified string: " << a1 << std::endl;

    return 0;
}



    