#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    fstream file;

    file.open("test.txt", ios::in);

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла при чтении" << endl;
        return 1;
    }

    string str;
    vector<int> name;

    while (getline(file, str)) {
        stringstream str2(str);

        string n;

        while (getline(str2, n, ' ')) {
            int num = stoi(n);
            name.push_back(num);
        }
    }
    file.close();
    sort(name.begin(), name.end());
    ofstream file2("file2.txt");
    for(int i = 0; i < name.size(); i++ ) {
        file2 << name[i] << " ";
    }
    file2.close();
}

