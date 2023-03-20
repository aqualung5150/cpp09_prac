#include "PmergeMe.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

// Function to print the array
void print(std::vector<unsigned long> vec)
{
    for (std::vector<unsigned long>::iterator it = vec.begin(); it != vec.end(); it++) 
        std::cout << *it << " ";
    std::cout << '\n';
}

// void insertionSort(std::vector<int> &vec)
// {
//     for (std::vector<int>::iterator it = vec.begin() + 1; it != vec.end(); it++)
//     {        
//         // Searching the upper bound, i.e., first 
//         // element greater than *it from beginning
//         std::vector<int>::iterator const insertion_point = 
//                 std::upper_bound(vec.begin(), it, *it);
          
//         // Shifting the unsorted part
//         std::rotate(insertion_point, it, it+1);
//     }
// }
  

  
// Driver code
// int main()
// {
//     std::vector<int> arr;
//     // 2 1 5 3 7 5 4 6
//     arr.push_back(2);
//     arr.push_back(1);
//     arr.push_back(5);
//     arr.push_back(3);
//     arr.push_back(7);
//     arr.push_back(5);
//     arr.push_back(4);
//     arr.push_back(6);

//     std::cout << "before:\t";
//     print(arr);


//     insertionSort(arr);
//     std::cout << "after:\t";
//     print(arr);
// }

int main(int argc, char** argv)
{
    if (argc < 2) //err
        return 1;

    PmergeMe a(argv);

    std::vector<unsigned long>::iterator first = a.getV().begin();
    std::vector<unsigned long>::iterator last = a.getV().end();

    a.insertionSort(first, last);
    print(a.getV());

    return 0;
}