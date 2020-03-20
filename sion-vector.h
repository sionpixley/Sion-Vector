#ifndef SION_VECTOR_H
#define SION_VECTOR_H

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>


using std::cout;
using std::cin;
using std::endl;

namespace sion
{
    template<class type>
    class vector
    {
    private:
        type* elements;
        size_t max_length;
        size_t length;
        
    public:
        template<class T>
        class vector_iter
        {
        private:
            T* pointee;
            
        public:
            using iterator_category = std::random_access_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;
            
            vector_iter()
            {
                pointee = nullptr;
            }
            
            vector_iter(T* ptr)
            {
                pointee = ptr;
            }
            
            T& operator *()
            {
                return *pointee;
            }
            
            T* operator ->()
            {
                return pointee;
            }
            
            vector_iter<T>& operator ++()
            {
                ++pointee;
                return *this;
            }
            
            vector_iter<T>& operator --()
            {
                --pointee;
                return *this;
            }
            
            vector_iter<T>& operator +(int rhs)
            {
                pointee = pointee + rhs;
                return *this;
            }
            
            vector_iter<T>& operator -(int rhs)
            {
                pointee = pointee - rhs;
                return * this;
            }
            
            bool operator ==(vector_iter<T>& rhs)
            {
                return this.pointee == rhs.pointee;
            }
        };
        
        
        using iterator = vector_iter<type>;
        
        vector()
        {
            max_length = 10;
            length = 0;
            elements = (type*)(std::malloc(max_length * sizeof(type)));
        }
        
        ~vector()
        {
            std::free(elements);
        }
        
        int push_back(type item)
        {
            try
            {
                if(length == max_length)
                {
                    max_length *= 2;
                    elements = (type*)(std::realloc(elements, max_length * sizeof(type)));
                    elements[length] = item;
                    length += 1;
                    return 0;
                }
                else
                {
                    elements[length] = item;
                    length += 1;
                    return 0;
                }
            }
            catch(...)
            {
                return 1;
            }
        }
        
        size_t size()
        {
            return length;
        }
        
        type pop_back()
        {
            if(length == 0)
            {
                type t;
                return t;
            }
            else
            {
                type t = elements[length - 1];
                elements[length - 1] = nullptr;
                length -= 1;
                return t;
            }
        }
        
        int clear()
        {
            try
            {
                std::free(elements);
                max_length = 10;
                length = 0;
                elements = (type*)(std::malloc(max_length * sizeof(type)));
                return 0;
            }
            catch(...)
            {
                return 1;
            }
        }
        
        iterator begin()
        {
            return iterator(&elements[0]);
        }
        
        iterator end()
        {
            return iterator(&elements[length - 1] + 1);
        }
        
        type& operator[](size_t index)
        {
            if(index >= length)
            {
                cout << "Error. Out of bounds." << endl;
                exit(-1);
            }
            else
            {
                return elements[index];
            }
        }
    };
}

#endif // SION_VECTOR_H

