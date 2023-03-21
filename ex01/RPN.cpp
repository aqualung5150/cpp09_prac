#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& r)
{
    _stack = r._stack;
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN& r)
{
    if(this == &r)
        return *this;

    _stack = r._stack;

    return *this;
}

static bool isOperator(std::string str)
{
    if (str.length() == 1 && (str[0] == '*' || str[0] == '/' || \
    str[0] == '+' || str[0] == '-'))
        return true;
    return false;
}

static bool isNumber(std::string str)
{
    if (isOperator(str))
        return false;

    if (str[0] != '+' && str[0] != '-' && !std::isdigit(str[0]))
        return false;
    
    for(unsigned long i = 1; i < str.length(); ++i)
    {
        if(!std::isdigit(str[i]))
            return false;
    }

    return true;
}

static bool invalidInput(std::string input)
{
    std::stringstream inputStream;
    std::string line;
    int flag;

    inputStream.str(input);
    line = "";

    // First two integer && isEmpty
    for(int i = 0; i < 2;)
    {
        if (!std::getline(inputStream, line, ' '))
            return true;
        // skip space
        if (line.length() == 0)
            continue;
        else
            ++i;
        if (!isNumber(line))
            return true;
    }

    flag = 1;
    while(std::getline(inputStream, line, ' '))
    {
        // skip space
        if (line.length() == 0)
            continue;
        if(!isOperator(line) && !isNumber(line))
            return true;

        if(isNumber(line))
            ++flag;
        else
            --flag;
        // To prevent three occurrences in a row
        if(flag > 2 || flag < 0)
            return true;
    }
    if(flag != 0)
        return true;
    return false;
}

long RPN::calc(const std::string& input)
{
    std::stringstream inputStream;
    std::string line;
    long a;
    long b;

    inputStream.str(input);
    line = "";
    if(invalidInput(input))
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    while(std::getline(inputStream, line, ' '))
    {
        // skip empty
        if(line.length() == 0)
            continue;
        // number
        else if(isNumber(line))
            _stack.push(std::strtol(line.c_str(), NULL, 10));
        // operator
        else
        {
            b = _stack.top();
            _stack.pop();
            a = _stack.top();
            _stack.pop();

            if(line[0] == '+')
                _stack.push(a + b);
            else if(line[0] == '-')
                _stack.push(a - b);
            else if(line[0] == '*')
                _stack.push(a * b);
            else if(line[0] == '/')
            {
                if (b != 0)
                    _stack.push(a / b);
                else
                {
                    std::cout << "Error" << std::endl;
                    exit(1);
                }
            }
        }
    }
    return _stack.top();
}