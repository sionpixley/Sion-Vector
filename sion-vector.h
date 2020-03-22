#ifndef SION_VECTOR_H
#define SION_VECTOR_H

#include <string>
#include <algorithm>


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
        // default constructor, copy constructor, and destructor
        vector();
        vector(const vector<type>& obj);
        ~vector();
        
        // class methods
        int push_back(type item);
        type pop_back();
        size_t size();
        int clear();
        void sort();
        void sort(std::string mode);
        vector<type> sorted();
        vector<type> sorted(std::string mode);
        void reverse();
        vector<type> reversed();
        
        // iterator stuff
        using iterator = type*;
        type* begin();
        type* end();
        //type* rbegin();
        //type* rend();
        
        // = and [] operators
        vector<type>& operator =(const vector<type>& obj);
        type& operator [](size_t index);
    };
}

#include "sion-vector.cpp"
#endif // SION_VECTOR_H

