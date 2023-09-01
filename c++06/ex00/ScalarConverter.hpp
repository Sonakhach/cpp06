#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <sstream>
#include <limits> 
#include <climits>  


class ScalarConverter
{
    
    public:
        static int convert(const std::string &str);
        
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter & operator=(const ScalarConverter&);
        ~ScalarConverter();
        static int m_integer;
        static char m_character;
        static float m_floater;
        static double m_doubler;
        static int m_sum;
        

        static void checkChar(std::string str);
        static void checkFloat(std::string num, bool dot);
        static void checkDoubl(std::string num, bool dot);
        static void checkInt(std::string num);
        static void checkstr(std::string str);
};



#endif