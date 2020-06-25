#include "sion-Vector"

template<typename Type>
sion::Vector<Type>::Vector() {
    max_length = 10;
    length = 0;
    elements = (Type*)(std::malloc(max_length * sizeof(Type)));
}

template<typename Type>
sion::Vector<Type>::Vector(const sion::Vector<Type>& that) {
    this.max_length = that.max_length;
    this.length = that.length;
    this.elements = (Type*)(std::malloc(max_length * sizeof(Type)));
    for(size_t i = 0; i < length; i += 1) {
        this.elements[i] = that.elements[i];
    }
}

template<typename Type>
sion::Vector<Type>::~Vector() {
    std::free(elements);
}

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
size_t sion::Vector<Type>::size() {
    return length;
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

template<typename Type>
void sion::Vector<Type>::sort(char order) {
    if(order == 'a') {
        std::sort(begin(), end());
    }
    else if(order == 'd') {
        std::sort(begin(), end(), std::greater<Type>());
    }
    else {
        throw std::invalid_argument("\"order\" parameter needs to be either 'a' or 'd'.");
    }
}

template<typename Type>
sion::Vector<Type> sion::Vector<Type>::sorted(char order) {
    Vector<Type> v = *this;
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

template<typename Type>
void sion::Vector<Type>::reverse() {
    std::reverse(begin(), end());
}

template<typename Type>
sion::Vector<Type> sion::Vector<Type>::reversed() {
    Vector<Type> v = *this;
    std::reverse(v.begin(), v.end());
    return v;
}

template<typename Type>
Type* sion::Vector<Type>::begin() {
    return elements;
}

template<typename Type>
Type* sion::Vector<Type>::end() {
    return elements + length;
}

/*
 template<typename Type>
 Type* sion::Vector<Type>::rbegin()
 {
    return elements + length;
 }
 */

/*
 template<typename Type>
 Type* sion::Vector<Type>::rend()
 {
    return elements;
 }
 */

template<typename Type>
sion::Vector<Type>& sion::Vector<Type>::operator =(const sion::Vector<Type>& that) {
    if(this != &that) {
        std::free(this.elements);
        this.max_length = that.max_length;
        this.length = that.length;
        this.elements = (Type*)(std::malloc(max_length * sizeof(Type)));
        for(size_t i = 0; i < length; i += 1) {
            this.elements[i] = that.elements[i];
        }
    }
    return *this;
}

template<typename Type>
Type& sion::Vector<Type>::operator [](size_t index) {
    if((index >= length) || (index < 0)) {
        throw std::out_of_range("Index out of bounds.");
    }
    else {
        return elements[index];
    }
}

