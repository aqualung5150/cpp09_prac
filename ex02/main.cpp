#include "PmergeMe.hpp"
#include <vector>
#include <deque>


int main(int argc, char** argv)
{
    if (argc < 2) //err
        return 1;

    PmergeMe< std::vector<long> > v(argv);
    std::vector<long>::iterator v_first = v.getArray().begin();
    std::vector<long>::iterator v_last = v.getArray().end();

    PmergeMe< std::deque<long> > d(argv);
    std::deque<long>::iterator d_first = d.getArray().begin();
    std::deque<long>::iterator d_last = d.getArray().end();

    v.mysort(v_first, v_last);
    d.mysort(d_first, d_last);

    std::cout << "Vector:" << std::endl;
    v.print();

    std::cout << std::endl;

    std::cout << "Deque:" << std::endl;
    d.print();


    return 0;
}