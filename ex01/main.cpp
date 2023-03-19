#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    RPN a;

    if(argc != 2)
        return 1;

    std::cout << a.calc(argv[1]) << std::endl;

    return 0;
}