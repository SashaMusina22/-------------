#include <iostream>
using namespace std;

class Car {
    protected:
        int horsepower;
        int year;
        string color;
        int mileage;

    public:
    Car() = default;
    virtual ~Car() = default;

    Car(int a, int b, string c, int d) : horsepower(a), year(b), color(c), mileage(d) {};

    void set_horsepower(int a){
        horsepower = a;
    }

    void set_year(int b){
        year = b;
    }

    void set_color(string c){
        color = c;
    }
    

    void set_mileage(int d){
        mileage = d;
    }

    int get_horsepower() const {
        return horsepower;
    }

    int get_year() const {
        return year;
    }

    string get_color() const {
        return color;
    }

    int get_mileage() const {
        return mileage;
    } 

    virtual void print() const = 0;

};

class PassengerCar : public Car{
    private:
    int doors_number;

    public:
    PassengerCar(int a, int b, string c, int d, int e) : Car(a, b, c, d), doors_number(e){};
    void print() const override {
        cout << "Мощность легкового автомобиля: " << horsepower << endl << "Год: " << year << endl << "Цвет: " << color << endl << "Пробег: " << mileage << endl << "Количество дверей: " << doors_number << endl;
    }

    ~PassengerCar() override = default;

};

class Truck : public Car{
    private:
    int capacity;

    public:
    Truck(int a, int b, string c, int d, int e) : Car(a, b, c, d), capacity(e){};
    void print() const override {
        cout << "Мощность легкового автомобиля: " << horsepower << endl << "Год: " << year << endl << "Цвет: " << color << endl << "Пробег: " << mileage << endl << "Вместимость: " << capacity << endl;
    }
    
    ~Truck() override = default;

};

class Bus : public Car{
    private:
    int numberofpassenger;

    public:
    Bus(int a, int b, string c, int d, int e) : Car(a, b, c, d), numberofpassenger(e){};
    void print() const override {
        cout << "Мощность легкового автомобиля: " << horsepower << endl << "Год: " << year << endl << "Цвет: " << color << endl << "Пробег: " << mileage << endl << "Количество пассажиров: " << numberofpassenger << endl;
    }
    
    ~Bus() override = default;

};
