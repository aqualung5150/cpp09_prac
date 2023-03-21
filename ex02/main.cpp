#include "PmergeMe.hpp"
#include <deque>
#include <ctime>
#include <sys/time.h>


int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    long v_elapsed;
    long d_elapsed;

    // argv to  std::string
    std::vector<std::string> input;
    input.assign(argv + 1, argv + argc);

    // std::vector sort
    {
        struct timeval start, end;
        gettimeofday(&start, NULL);

        PmergeMe< std::vector<long> > v(input);
        std::vector<long>::iterator v_first = v.getArray().begin();
        std::vector<long>::iterator v_last = v.getArray().end();

        v.mysort(v_first, v_last);

        gettimeofday(&end, NULL);
        v_elapsed = end.tv_usec - start.tv_usec;
    }

    // std::deque sort
    {
        struct timeval start, end;
        gettimeofday(&start, NULL);

        PmergeMe< std::deque<long> > d(input);
        std::deque<long>::iterator d_first = d.getArray().begin();
        std::deque<long>::iterator d_last = d.getArray().end();

        d.mysort(d_first, d_last);

        gettimeofday(&end, NULL);
        d_elapsed = end.tv_usec - start.tv_usec;

        std::cout << "Before:\t";
        print(input);
        std::cout << "After:\t";
        print(d.getArray());
    }

    std::cout << "Time to process a range of "<< argc - 1 <<" elements with std::vector\t: " << v_elapsed << " microsec" << std::endl;
    std::cout << "Time to process a range of "<< argc - 1 <<" elements with std::deque\t: " << d_elapsed << " microsec" << std::endl;

    return 0;
}