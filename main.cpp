#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange db("data.csv");

    db.testPrint();
    
    return 0;
}