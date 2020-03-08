#include "header.h"

int main()
{
    sion::vector<std::string> v;
    for(int i = 0; i < 100000; i += 1)
    {
        v.push_back("hello");
    }
    for(int i = 0; i < v.length(); i += 1)
    {
        cout << v[i] << endl;
    }
    return 0;
}
