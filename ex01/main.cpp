#include "RPN.hpp"

int main(int argc, char** argv)
{
    RPN a;

    if(argc != 2)
    {
        std::cout << "Error: invalid argument." << std::endl;
        return 1;
    }

    std::cout << a.calc(argv[1]) << std::endl;

    return 0;
}