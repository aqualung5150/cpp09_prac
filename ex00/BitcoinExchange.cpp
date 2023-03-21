#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string& csvFile)
{
    std::ifstream inputFile;
    std::string line;
    std::string date;
    std::string exchangeRate;
    std::stringstream inputString;
    double stringToDouble;

    inputFile.open(csvFile.c_str());
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
        std::getline(inputString, exchangeRate, '\n');
        stringToDouble = std::strtod(exchangeRate.c_str(), NULL);

        _database.insert(std::pair<std::string, double>(date, stringToDouble));

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

static bool isAllDigit(std::string str)
{
    for(unsigned long i = 0; i < str.length(); ++i)
    {
        if(!std::isdigit(str[i]))
            return false;
    }
    return true;
}

static bool invalidNumber(std::string str)
{
    int dotCount;

    if (str.length() <= 0)
        return true;
    if (str[0] != '+' && str[0] != '-' && str[0] != '.' && !std::isdigit(str[0]))
        return true;
    dotCount = 0;
    if (str[0] == '.')
        ++dotCount;
    for(unsigned long i = 1; i < str.length(); ++i)
    {
        if(!std::isdigit(str[i]) && str[i] != '.')
        {
            std::cerr << "Error: invalid value format => " << str << std::endl;
            return true;
        }
        else if(str[i] == '.')
            ++dotCount;
    }
    if(dotCount > 1)
    {
        std::cerr << "Error: invalid value format => " << str << std::endl;
        return true;
    }
    return false;
}

static bool isLeap(long year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else
        return false;
}

static bool invalidDate(std::string& sub)
{
    if (sub.length() != 10 || !isAllDigit(sub.substr(0, 4)) || \
    !isAllDigit(sub.substr(5, 2)) || !isAllDigit(sub.substr(8, 2)) || \
    sub[4] != '-' || sub[7] != '-')
        return true;
    
    long year = strtol(sub.substr(0, 4).c_str(), NULL, 10);
    long month = strtol(sub.substr(5, 2).c_str(), NULL, 10);
    long day = strtol(sub.substr(8, 2).c_str(), NULL, 10);

    if (month < 1 || month > 12 || day < 1 || day > 31)
        return true;
    
    if (month == 2)
    {
        if (isLeap(year))
            return (day > 29);
        else
            return (day > 28);
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day > 30);
    
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
    if (invalidDate(sub))
    {
        std::cerr << "Error: invalid date format => " << sub << std::endl;
        return 1;
    }
    // Invalid value number
    sub = line.substr(line.find(" | ") + 3);
    if(invalidNumber(sub))
    {
        std::cerr << "Error: invalid value format => " << sub << std::endl;
        return 1;
    }
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
    if (greatest_less(_database, sub) != _database.end())
        std::cout << std::setprecision(std::numeric_limits<double>::digits10) << sub << \
        " => " << value << " = " << greatest_less(_database, sub)->second * value << std::endl;
    else
        std::cerr << "Error: no data => " << sub << std::endl;
    return 0;
}