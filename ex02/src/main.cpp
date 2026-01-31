#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    // ===== MutantStack test =====
    MutantStack<int> mstack;

    mstack.push(5); // [5]
    mstack.push(17); // [5, 17]

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop(); // [5]

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3); // [5, 3]
    mstack.push(5); // [5, 3, 5]
    mstack.push(737); // [5, 3, 5, 737]
    mstack.push(0); // [5, 3, 5, 737, 0]

    // Iterate through the stack
    std::cout << "MutantStack contents:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    // ===== Compare with list =====
    std::list<int> lst;

    lst.push_back(5); // [5]
    lst.push_back(17); // [5, 17]
    lst.pop_back(); // [5]
    lst.push_back(3); // [5, 3]
    lst.push_back(5); // [5, 3, 5]
    lst.push_back(737); // [5, 3, 5, 737]
    lst.push_back(0); // [5, 3, 5, 737, 0]

    std::cout << "\nList contents:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}
