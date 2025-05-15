#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <string>  

enum class Color { red, green, orange };
enum class Fruit { apple, orange, pear };

template <typename T>
class Traits;

template<>
class Traits<Color> {
public:
    static std::string name(int index) {
        if(index == 0) return "red";
        else if(index == 1) return "green";
        else if(index == 2) return "orange";
        else return "unknown";
    }
};

template<>
class Traits<Fruit> {
public:
    static std::string name(int index) {
        if(index == 0) return "apple";
        else if(index == 1) return "orange";
        else if(index == 2) return "pear";
        else return "unknown";
    }
};

#endif