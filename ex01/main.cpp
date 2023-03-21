#include "RPN.hpp"

int main(int argc, char** argv)
{
    RPN calculator;

    if(argc != 2)
    {
        std::cout << "Error: invalid argument." << std::endl;
        return 1;
    }

    std::cout << calculator.calc(argv[1]) << std::endl;

    return 0;
}