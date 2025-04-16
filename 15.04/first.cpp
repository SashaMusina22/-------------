//Дана строка символов и некоторый символ n. 
//Сформируйте новую строку, вставив после каждого вхождения символа n запятую. 
//Определите самое большое слово в строке.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string insert_comma(string& a, char n) { 
    string result;
    for(char ch : a) {
        result += ch;
        if(ch == n) result +=',';
    }
    return result;
}

string find_word(string& a) {
    istringstream stream(a);
    string word, longest_word;
    size_t maxLength = 0;

    while (stream >> word) {
        if (word.length() > maxLength) {
            maxLength = word.length();
            longest_word = word;
        }
    }
    
    return longest_word;
}

int main(){
    string str1 = "test car  dool  bear doors";
    char n = 'o';

    string a1 = insert_comma(str1, n);  
    std::cout << "Modified string: " << a1 << std::endl;
    
    string a2 = find_word(a1);  
    std::cout << "Longest word: " << a2 << std::endl;

    return 0;


}