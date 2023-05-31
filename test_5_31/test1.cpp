#include <iostream>
using namespace std;
#include <string>

int main()
{
    string s1;
    size_t size = s1.capacity();
    s1.reserve(100);
    for (int i = 0; i < 100; ++i)
    {
        s1.push_back('x');
        if (size != s1.capacity())
        {
            size = s1.capacity();
            cout << "ÈÝÁ¿:" << s1.capacity() << endl;
        }
    }
}

