#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& r)
{
    _s = r._s;
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN& r)
{
    if(this == &r)
        return *this;

    _s = r._s;

    return *this;
}

static bool is_operator(std::string str)
{
    if (str.length() == 1 && (str[0] == '*' || str[0] == '/' || \
    str[0] == '+' || str[0] == '-'))
        return true;
    return false;
}

static bool is_number(std::string str)
{
    if (is_operator(str))
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

static bool invalid_input(std::string input)
{
    std::stringstream in;
    std::string line;
    int flag;

    in.str(input);
    line = "";

    // First two integer && isEmpty
    for(int i = 0; i < 2;)
    {
        if (!std::getline(in, line, ' '))
            return true;
        // skip space
        if (line.length() == 0)
            continue;
        else
            ++i;
        if (!is_number(line))
            return true;
    }

    flag = 1;
    while(std::getline(in, line, ' '))
    {
        // skip space
        if (line.length() == 0)
            continue;
        if(!is_operator(line) && !is_number(line))
            return true;

        if(is_number(line))
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
    std::stringstream in;
    std::string line;
    long a;
    long b;

    in.str(input);
    line = "";
    if(invalid_input(input))
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    while(std::getline(in, line, ' '))
    {
        // skip empty
        if(line.length() == 0)
            continue;
        // number
        else if(is_number(line))
            _s.push(std::strtol(line.c_str(), NULL, 10));
        // operator
        else
        {
            b = _s.top();
            _s.pop();
            a = _s.top();
            _s.pop();

            if(line[0] == '+')
                _s.push(a + b);
            else if(line[0] == '-')
                _s.push(a - b);
            else if(line[0] == '*')
                _s.push(a * b);
            else if(line[0] == '/')
            {
                if (b != 0)
                    _s.push(a / b);
                else
                {
                    std::cout << "Error" << std::endl;
                    exit(1);
                }
            }
        }
    }
    return _s.top();
}