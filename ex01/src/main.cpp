#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib> // for rand()
#include <ctime>

int main()
{
    try
    {
        // ======= SMALL EXAMPLE =======
        std::cout << "=== Small example ===" << std::endl;
        Span sp(5); // Span can hold 5 numbers

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.print();

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Add multiple numbers at once
        std::vector<int> extra = {20, 25};
        Span sp2(10);
        sp2.addNumber(1);
        sp2.addNumber(5);
        sp2.addNumber(extra.begin(), extra.end());

        sp2.print();
        std::cout << "Shortest span in sp2: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span in sp2: " << sp2.longestSpan() << std::endl;

        // ======= STRESS TEST WITH 50,000 NUMBERS =======
        std::cout << "\n=== Stress test with 50,000 numbers ===" << std::endl;
        std::srand(std::time(nullptr));

        const unsigned int N = 50000;
        Span bigSpan(N);

        for (unsigned int i = 0; i < N; ++i)
            bigSpan.addNumber(std::rand());

        std::cout << "Span filled with " << N << " random numbers." << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
