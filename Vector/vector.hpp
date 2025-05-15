#include <iostream>

using namespace std;

template<typename T>
class my_vector{
    int len;
    int capacity;
    T* data;
public:

    class iterator{
        T* ptr;
    public:

        iterator() : ptr(nullptr) {};
        iterator(T* a) : ptr(a) {};

        T& operator*() {
            return *ptr;
        }
        iterator& operator++() {
            ++ptr;
            return *this;
        }
        bool operator==(const iterator& other) { 
            return ptr == other.ptr; 
        }
        bool operator!=(const iterator& other) { 
            return ptr != other.ptr; 
        }
    };

    iterator begin() {
        return iterator(data);
    }

    iterator end(){
        return iterator(data + len);
    }

    my_vector() : data(nullptr), len(0), capacity(0) {};
    my_vector(int size) : data(new T(size)), len(size), capacity(size) {};

    //конструктор копирования
    my_vector(const my_vector& vector_to_copy) : len(vector_to_copy.len), capacity(vector_to_copy.len), data(new T(len)){
        for(int i=0; i<len; i++ ){
            data[i] = vector_to_copy.data[i];
        }
    }

    //конструктор перемещения????
    my_vector(my_vector&& other)  
        : len(other.len), capacity(other.capacity), data(other.data) {
        other.data = nullptr;
        other.len = 0;
        other.capacity = 0;
    }

    ~my_vector() {
        delete[] data;
    }

    T* get_data() const{
        return data;
    }

    int get_len() const {
        return len;
    }

    int get_capacity() const {
        return capacity;
    }

    void set_capacity(int new_capacity) {
        if(new_capacity < len) {
            cout << "Error";
            return;
        }
        if(new_capacity != capacity) {
            T* new_data = new T[new_capacity];
            for (int i = 0; i < len; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }

    void set_size(int new_len) {
        if (new_len > capacity){
            cout << "error";
        } else {
            len = new_len;
        }
    }

    void push_back(const T& value){
        if (len == capacity){
            capacity++;
            T* new_data = new T[capacity];
            for(int i=0; i<len; i++){
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[len] = value;
        len++;
    }

    void pop_back(){
        if (len != 0){
            len--;
        }
    }

    T back() const{
        if (len == 0){
            throw std::invalid_argument("myVector is empty!");
        }   
        return data[len-1];
    }

    T front() const{
        if (len == 0){
            throw std::invalid_argument("myVector is empty!");
        }   
        return data[0];
    }
    
    bool empty() const {
        return(len == 0);
    }
};