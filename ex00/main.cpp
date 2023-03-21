#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    BitcoinExchange db("data.csv");
    std::ifstream input;
    std::string line;

    if (argc != 2) // Invalid argument
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    input.open(argv[1]); // Open input file
    if(input.fail())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::getline(input, line); // Skip first line "date | value"
    if(line.compare("date | value"))
    {
        std::cerr << "Error: invalid file." << std::endl;
    }
    while(std::getline(input, line))
    {
        if(line.length() != 1)
            db.exchange(line);
    }

    input.close();

    return 0;
}