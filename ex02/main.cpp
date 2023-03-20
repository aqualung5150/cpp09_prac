#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, char** argv)
{
    if (argc < 2) //err
        return 1;

    PmergeMe a(argv);

    std::vector<unsigned long>::iterator v_first = a.getV().begin();
    std::vector<unsigned long>::iterator v_last = a.getV().end();

    std::deque<unsigned long>::iterator d_first = a.getD().begin();
    std::deque<unsigned long>::iterator d_last = a.getD().end();

    a.mysort(v_first, v_last);
    a.mysort(d_first, d_last);

    std::cout << "vector:" << std::endl;
    print(a.getV());
    std::cout << "deque:" << std::endl;
    print(a.getD());

    return 0;
}