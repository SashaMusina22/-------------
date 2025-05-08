#include "vector.hpp"
#include <iostream>

int main() {
    my_vector<int> v;

    std::cout << "Пустой? " << v.empty() << "\n";
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Пустой? " << v.empty() << "\n";
    std::cout << "Размер: " << v.get_len() << "\n";
    std::cout << "Первый элемент: " << v.front() << "\n";
    std::cout << "Последний элемент: " << v.back() << "\n";

    v.pop_back();
    std::cout << "После pop_back, последний элемент: " << v.back() << "\n";

    my_vector<int> copy = v;
    std::cout << "Копия — первый элемент: " << copy.front() << "\n";

    return 0;
}
