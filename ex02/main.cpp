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

    long vectorExecutionTime;
    long dequeExecutionTime;

    // argv to  std::string
    std::vector<std::string> inputNumbers;
    inputNumbers.assign(argv + 1, argv + argc);

    // std::vector sort
    {
        struct timeval start, end;
        gettimeofday(&start, NULL);

        PmergeMe< std::vector<long> > vectorArray(inputNumbers);
        std::vector<long>::iterator first = vectorArray.getArray().begin();
        std::vector<long>::iterator last = vectorArray.getArray().end();

        vectorArray.mergeInsertionSort(first, last);

        gettimeofday(&end, NULL);
        vectorExecutionTime = end.tv_usec - start.tv_usec;
    }

    // std::deque sort
    {
        struct timeval start, end;
        gettimeofday(&start, NULL);

        PmergeMe< std::deque<long> > dequeArray(inputNumbers);
        std::deque<long>::iterator first = dequeArray.getArray().begin();
        std::deque<long>::iterator last = dequeArray.getArray().end();

        dequeArray.mergeInsertionSort(first, last);

        gettimeofday(&end, NULL);
        dequeExecutionTime = end.tv_usec - start.tv_usec;

        std::cout << "Before:\t";
        printElements(inputNumbers);
        std::cout << "After:\t";
        printElements(dequeArray.getArray());
    }

    std::cout << "Time to process a range of "<< argc - 1 <<" elements with std::vector\t: " << vectorExecutionTime << " microsec" << std::endl;
    std::cout << "Time to process a range of "<< argc - 1 <<" elements with std::deque\t: " << dequeExecutionTime << " microsec" << std::endl;

    return 0;
}