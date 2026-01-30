#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    //containers to test easyfind
    std::vector<int> v;
    std::list<int>   l;

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);      // v = [0,1,2,3,4]
        l.push_back(i * 10); // l = [0,10,20,30,40]
    }

    try
    {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found in vector: " << *it << std::endl;

        std::list<int>::iterator it2 = easyfind(l, 42);
        std::cout << "Found in list: " << *it2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
