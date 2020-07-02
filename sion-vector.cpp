#include "sion-vector"

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
----------------CONSTRUCTORS-------------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
sion::Vector<Type>::Vector() {
    max_length = 10;
    length = 0;
    elements = (Type*)(std::malloc(max_length * sizeof(Type)));
}

template<typename Type>
sion::Vector<Type>::Vector(const sion::Vector<Type>& that) {
    this->max_length = that.max_length;
    this->length = that.length;
    this->elements = (Type*)(std::malloc(max_length * sizeof(Type)));
    for(size_t i = 0; i < length; i += 1) {
        this->elements[i] = that.elements[i];
    }
}

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
----------------DESTRUCTOR---------------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
sion::Vector<Type>::~Vector() {
    std::free(elements);
}

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
----------------ITERATORS----------------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
typename sion::Vector<Type>::iterator sion::Vector<Type>::begin() noexcept {
    return elements;
}

template<typename Type>
typename sion::Vector<Type>::iterator sion::Vector<Type>::end() noexcept {
    return elements + length;
}

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
--------------CONST ITERATORS------------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
typename sion::Vector<Type>::const_iterator sion::Vector<Type>::begin() const noexcept{
    return elements;
}

template<typename Type>
typename sion::Vector<Type>::const_iterator sion::Vector<Type>::cbegin() const noexcept {
    return elements;
}

template<typename Type>
typename sion::Vector<Type>::const_iterator sion::Vector<Type>::end() const noexcept {
    return elements + length;
}

template<typename Type>
typename sion::Vector<Type>::const_iterator sion::Vector<Type>::cend() const noexcept {
    return elements + length;
}

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
-------------REVERSE ITERATORS-----------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
typename sion::Vector<Type>::reverse_iterator sion::Vector<Type>::rbegin() noexcept {
    return std::make_reverse_iterator(elements + length);
}

template<typename Type>
typename sion::Vector<Type>::reverse_iterator sion::Vector<Type>::rend() noexcept {
    return std::make_reverse_iterator(elements);
}

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
-----------CONST REVERSE ITERATORS-------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
typename sion::Vector<Type>::const_reverse_iterator sion::Vector<Type>::rbegin() const noexcept {
    return std::make_reverse_iterator(elements + length);
}

template<typename Type>
typename sion::Vector<Type>::const_reverse_iterator sion::Vector<Type>::crbegin() const noexcept {
    return std::make_reverse_iterator(elements + length);
}

template<typename Type>
typename sion::Vector<Type>::const_reverse_iterator sion::Vector<Type>::rend() const noexcept {
    return std::make_reverse_iterator(elements);
}

template<typename Type>
typename sion::Vector<Type>::const_reverse_iterator sion::Vector<Type>::crend() const noexcept {
    return std::make_reverse_iterator(elements);
}

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
----------------CAPACITY-----------------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
size_t sion::Vector<Type>::size() const noexcept {
    return length;
}

template<typename Type>
bool sion::Vector<Type>::is_empty() const noexcept {
    return (length == 0);
}

template<typename Type>
size_t sion::Vector<Type>::capacity() const noexcept {
    return max_length;
}

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
------------ADDING AND REMOVING----------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
int sion::Vector<Type>::push_back(Type item) {
    try {
        if(length == max_length) {
            max_length *= 2;
            elements = (Type*)(std::realloc(elements, max_length * sizeof(Type)));
            elements[length] = item;
            length += 1;
            return 0;
        }
        else {
            elements[length] = item;
            length += 1;
            return 0;
        }
    }
    catch(...) {
        return 1;
    }
}

template<typename Type>
Type sion::Vector<Type>::pop_back() {
    if(length == 0) {
        Type t;
        return t;
    }
    else {
        Type t = elements[length - 1];
        length -= 1;
        return t;
    }
}

template<typename Type>
int sion::Vector<Type>::clear() {
    try {
        std::free(elements);
        max_length = 10;
        length = 0;
        elements = (Type*)(std::malloc(max_length * sizeof(Type)));
        return 0;
    }
    catch(...) {
        return 1;
    }
}

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
----------------SORTING-----------------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
sion::Vector<Type>& sion::Vector<Type>::sort(char order) {
    if((typeid(Type) == typeid(int)) ||
       (typeid(Type) == typeid(long)) || 
       (typeid(Type) == typeid(long long)) || 
       (typeid(Type) == typeid(float)) || 
       (typeid(Type) == typeid(double)) ||
       (typeid(Type) == typeid(long double)) ||
       (typeid(Type) == typeid(char)) ||
       (typeid(Type) == typeid(std::string))) {
        if(order == 'a') {
            std::sort(begin(), end());
        }
        else if(order == 'd') {
            std::sort(begin(), end(), std::greater<Type>());
        }
        else {
            throw std::invalid_argument("\"order\" parameter needs to be either 'a' or 'd'.");
        }
        return *this;
    }
    else {
        throw std::invalid_argument("The Vector must hold either a number, std::string, or char type for the .sort() function to be used.");
    }
}

template<typename Type>
sion::Vector<Type> sion::Vector<Type>::sorted(char order) const {
    Vector<Type> v = *this;
    if((typeid(Type) == typeid(int)) ||
       (typeid(Type) == typeid(long)) ||
       (typeid(Type) == typeid(long long)) ||
       (typeid(Type) == typeid(float)) ||
       (typeid(Type) == typeid(double)) ||
       (typeid(Type) == typeid(long double)) ||
       (typeid(Type) == typeid(char)) ||
       (typeid(Type) == typeid(std::string))) {
        if(order == 'a') {
            std::sort(v.begin(), v.end());
        }
        else if(order == 'd') {
            std::sort(v.begin(), v.end(), std::greater<Type>());
        }
        else {
            throw std::invalid_argument("\"order\" parameter needs to be either 'a' or 'd'.");
        }
        return v;
    }
    else {
        throw std::invalid_argument("The Vector must hold either a number, std::string, or char type for the .sorted() function to be used.");
    }
}

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
----------------REVERSING-----------------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
sion::Vector<Type>& sion::Vector<Type>::reverse() {
    std::reverse(begin(), end());
    return *this;
}

template<typename Type>
sion::Vector<Type> sion::Vector<Type>::reversed() const {
    Vector<Type> v = *this;
    std::reverse(v.begin(), v.end());
    return v;
}

/* \/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
----------------OPERATORS----------------------
\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/ */
template<typename Type>
sion::Vector<Type>& sion::Vector<Type>::operator =(const sion::Vector<Type>& that) {
    if(this != &that) {
        std::free(this->elements);
        this->max_length = that.max_length;
        this->length = that.length;
        this->elements = (Type*)(std::malloc(max_length * sizeof(Type)));
        for(size_t i = 0; i < length; i += 1) {
            this->elements[i] = that.elements[i];
        }
    }
    return *this;
}

template<typename Type>
typename sion::Vector<Type>::reference sion::Vector<Type>::operator [](size_t index) {
    if((index >= length) || (index < 0)) {
        throw std::out_of_range("Index out of bounds.");
    }
    else {
        return elements[index];
    }
}

template<typename Type>
typename sion::Vector<Type>::const_reference sion::Vector<Type>::operator [](size_t index) const {
    if((index >= length) || (index < 0)) {
        throw std::out_of_range("Index out of bounds.");
    }
    else {
        return elements[index];
    }
}

template<typename Type>
sion::Vector<Type> sion::Vector<Type>::operator +(const sion::Vector<Type>& that) const {
    Vector<Type> v = *this;
    size_t _size = that.size();
    for(size_t i = 0; i < _size; i += 1) {
        v.push_back(that[i]);
    }
    return v;
}

template<typename Type>
sion::Vector<Type>& sion::Vector<Type>::operator +=(const sion::Vector<Type>& that) {
    size_t _size = that.size();
    for(size_t i = 0; i < _size; i += 1) {
        this->push_back(that[i]);
    }
    return *this;
}

