#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string& csvFile)
{
    std::ifstream inputFile;
    std::string line;
    std::string date;
    std::string exchange_rate;
    std::stringstream inputString;
    double d;

    inputFile.open(csvFile);
    if(inputFile.fail())
    {
        std::cerr << "Error: can not open input file." << std::endl;
        exit(1);
    }
    line = "";
    std::getline(inputFile, line); // Skip to store first line
    while (std::getline(inputFile, line))
    {
        inputString.str(line);

        std::getline(inputString, date, ',');
        std::getline(inputString, exchange_rate, '\n');
        d = std::strtod(exchange_rate.c_str(), NULL);

        _database.insert(std::pair<std::string, double>(date, d));

        inputString.clear();
    }
    inputFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& b)
{
    // Use overloaded assignment operator of std::map (deep copy)
    _database = b._database;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& b)
{
    if(this == &b)
        return *this;
    
    // Use overloaded assignment operator of std::map (deep copy)
    _database = b._database;

    return *this;
}

static std::map<std::string, double>::iterator greatest_less(std::map<std::string, double> &m, std::map<std::string, double>::key_type const &k)
{
    std::map<std::string, double>::iterator it = m.upper_bound(k);
    if(it != m.begin())
        return --it;
    return m.end();
}

static bool is_digit(std::string str)
{
    for(unsigned long i = 0; i < str.length(); ++i)
    {
        if(!std::isdigit(str[i]))
            return false;
    }
    return true;
}

static bool invalid_number(std::string str)
{
    int dot_count;

    dot_count = 0;
    for(unsigned long i = 0; i < str.length(); ++i)
    {
        if(!std::isdigit(str[i]) && str[i] != '-' && \
        str[i] != '+' && str[i] != '.')
        {
            std::cerr << "Error: invalid value format => " << str << std::endl;
            return true;
        }
        else if(str[i] == '.')
            ++dot_count;
    }
    if(dot_count > 1)
    {
        std::cerr << "Error: invalid value format => " << str << std::endl;
        return true;
    }
    return false;
}

int BitcoinExchange::exchange(std::string& line)
{
    std::string sub;
    double value;

    // No delimiter
    if (line.find(" | ") == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return 1;
    }
    // Invalid date format
    sub = line.substr(0, line.find(" | "));
    if (sub.length() != 10 || !is_digit(sub.substr(0, 4)) || \
    !is_digit(sub.substr(5, 2)) || !is_digit(sub.substr(8, 2)))
    {
        std::cerr << "Error: invalid date format => " << sub << std::endl;
        return 1;
    }
    // Invalid value number
    sub = line.substr(line.find(" | ") + 3);
    if(invalid_number(sub))
        return 1;
    value = std::strtod(sub.c_str(), NULL);
    if (value > 1000.0)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return 1;
    }
    else if (value < 0.0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return 1;
    }
    // Exchange valid format
    sub = line.substr(0, line.find(" | "));
    std::cout << sub << " => " << value << " = " << greatest_less(_database, sub)->second * value << std::endl;
    return 0;
}