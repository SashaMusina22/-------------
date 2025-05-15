#include "template.hpp"
#include <iostream>
using namespace std;

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i != t; ++i) {
        int index1;
        cin >> index1;
        int index2;
        cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
    return 0;
}