#include "sion-vector.h"

int main()
{
    sion::vector<std::string> v;
    for(int i = 0; i < 100000; i += 1)
    {
        v.push_back("hello");
    }
    for(int i = 0; i < v.size(); i += 1)
    {
        cout << v[i] << endl;
    }
    
    std::string array[5] = { "4", "5", "6", "7", "8" };
    v = array;
    for(int i = 0; i < v.size(); i += 1)
    {
        cout << v[i] << endl;
    }
    
    return 0;
}
