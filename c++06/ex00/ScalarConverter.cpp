#include  "ScalarConverter.hpp"

int  ScalarConverter::m_integer = 0;
char ScalarConverter::m_character;
float ScalarConverter::m_floater = 0.0f;
double ScalarConverter::m_doubler = 0.0;
int ScalarConverter::m_sum = 0;

int ScalarConverter::convert(const std::string &str)
{
        bool dot = false;
        int len = str.length();
        if (str.compare("nan") == 0 || str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nanf") == 0 || str.compare("-inff") == 0 || str.compare("+inff") == 0 )
        {
            std::cout << "str.comp " << str.compare("nan")<< std::endl;
            checkstr(str);
        }  
        else if( len == 1 && !isdigit(str[0]))
        {
            std::cout << "checkChar "<<std::endl;
            checkChar(str);
        }
        else if ((str[0] == '-' || isdigit(str[0])) && str[len - 1] == 'f')
        {
            int countF = 0;
            int i = 1;
            while (i < len)
            {
                if(str[i] == 'f')
                    countF++;  
                i++;  
            }

            if (isdigit(str[1]) || str[1] == '.')
            {
                int j = 1; 
                int count = 0;
                int h = len-2;
                while((isdigit(str[j]) || str[j] == '.') && j < len)
                {                   
                    if (str[j]=='.' && str[j + 1] == 'f')
                    {
                        std::cout << " wrong number " <<std::endl;    
                        return 1;
                    }
                    if(str[j] == '.')
                    {
                        while(str[h] != str[j])
                        {
                            if (str[h]== '0')
                                m_sum++;
                            else
                            {
                                break;                               
                            }
                            h-- ;
                        }
                        if (str[h]== '.')
                            dot = true;
                        count++;
                    }
                    j++;                
                }
                if(count == 1 && countF == 1)
                {
                    
                    checkFloat(str, dot); 
                }
                else
                {
                    std::cout << " wrong argument " <<std::endl;    
                    return -1;
                }
            }
            else
                {
                    std::cout << " wrong argument " <<std::endl;    
                    return -1;
                }
        }
        else if ((str[0] == '-' || isdigit(str[0])) && isdigit(str[len - 1]) != 0)
        {
            if (isdigit(str[1]) || str[1] == '.')
            {
                int j = 1; 
                int count = 0;
                int h = len-1;
                
                while((isdigit(str[j]) || str[j] == '.') && j < len)
                {                   
                    if(str[j] == '.')
                    {
                        while(str[h] != str[j])
                        {
                            if (str[h]== '0')
                                m_sum++; 
                            else
                                break;                              
                            h-- ;
                        }
                        if (str[h]== '.')
                            dot = true;
                        count++;
                    }
                    j++;                
                }               
                if(count == 1 )
                {
                    checkDoubl(str, dot); 
                }
                else if(count == 0)
                {
                    checkInt(str); 
                }
                else
                {
                    std::cout << " wrong argument " <<std::endl;    
                    return -1;
                }
            }
            else
            {
                int j = 1; 
                while( j < len)
                {                   
                    if (!isdigit(str[j]))
                    {
                        std::cout << " wrong argument " <<std::endl;    
                        return -1;
                    }
                    j++;                
                }               
                checkInt(str); 
            }
        }
        else
        {
            std::cout << " wrong argument " <<std::endl;    
            return -1;
        }
        return 1;
}

void ScalarConverter::checkChar(std::string str)
{
    std::cout << "checkChar()" << std::endl; 
    m_character = str[0]; 
    std::cout << "m_character = " << "'" << m_character << "'" << std::endl;
    m_integer = static_cast<int>(m_character);
    std::cout << "m_integer = " << m_integer << std::endl;
    m_floater = static_cast<float>(m_character);
    std::cout << "m_floater = " << m_floater << ".0f" << std::endl;
    m_doubler = static_cast<double>(m_character); 
    std::cout << "m_doubler = " << m_doubler << ".0" << std::endl;

    
    
}

void ScalarConverter::checkFloat(std::string str, bool dot)
{
    char *lastPtr;
    std::cout << "checkFloat()" << std::endl;
    m_doubler = strtod(str.c_str(), &lastPtr);
    if (m_sum == 0)
    {
        m_floater = static_cast<float>(m_doubler);
        std::cout << "m_floater = " << m_floater << lastPtr << std::endl;
        std::cout << "m_doubler = " << m_doubler << std::endl;       
    }
    else
    {
        std::cout << "m_doubler = " << m_doubler;
        if (dot == true)
            std::cout << "." ;
        int tmp = m_sum;
        while(tmp != 0)
        {
            std::cout << "0" ;
                tmp--;
        }
        tmp = m_sum;
        std::cout << std::endl;

        m_floater = static_cast<float>(m_doubler);
        std::cout << "m_floater = " << m_floater ;
        if (dot == true)
            std::cout << "." ;
        while(tmp != 0)
        {
            std::cout << "0" ;
                tmp--;
        }
        tmp = m_sum;
        std::cout  << lastPtr << std::endl;
    }
    if (m_floater < std::numeric_limits<int>::min() || m_floater > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible " << std::endl;
    }
    else
    {
        m_integer = static_cast<int>(m_floater);
        std::cout << "m_integer = " << m_integer << std::endl;
        
    }
    if (m_floater < CHAR_MIN || m_floater > CHAR_MAX)
    {
        std::cout << "char: impossible " << std::endl;
    }
    else
    {
        m_character = static_cast<char>(m_floater);
        if (!isprint(m_character))
            std::cout << "char:  Non displayable " << std::endl;
        else
            std::cout << "m_character = " << m_character << std::endl;
        
    }
}
void ScalarConverter::checkDoubl(std::string str, bool dot)
{
   
    char *lastPtr;
    std::cout << "checkDoubl()" << std::endl;
    m_doubler = strtod(str.c_str(), &lastPtr);
    if (m_sum == 0)
    {

        std::cout << "m_doubler = " << m_doubler << std::endl;
        if (m_doubler < -std::numeric_limits<float>::max() || m_doubler > std::numeric_limits<float>::max())
        {
            std::cout << "float: impossible " << std::endl;
        }
        else
        {
           
            m_floater = static_cast<float>(m_doubler);
            std::cout << "m_floater = " << m_floater << "f"<< std::endl;
            
        }  
    }
    else
    {
        std::cout << "m_doubler = " << m_doubler; 
        if (dot == true)
            std::cout << ".";
        int tmp = m_sum;
        while(tmp != 0)
        {
            std::cout << "0" ;
                tmp--;
        }
        tmp = m_sum;
        std::cout << std::endl;
        if (m_doubler < -std::numeric_limits<float>::max() || m_doubler > std::numeric_limits<float>::max())
        {
            std::cout << "float: impossible " << std::endl;
        }
        else
        {
            m_floater = static_cast<float>(m_doubler);
            std::cout << "m_floater = " << m_floater ;    
            if (dot == true)
                std::cout << ".";
            while(tmp != 0)
            {
                std::cout << "0" ;
                    tmp--;
            }
            tmp = m_sum;
            std::cout<< "f" << std::endl;
        }        
    }
    if (m_doubler < std::numeric_limits<int>::min() || m_doubler > std::numeric_limits<int>::max())
    {
        std::cout << "int: impossible " << std::endl;
    }
    else
    {
        m_integer = static_cast<int>(m_doubler);
        std::cout << "m_integer = " << m_integer << std::endl;           
    }
    if (m_doubler < CHAR_MIN || m_doubler > CHAR_MAX)
    {
        std::cout << "char: impossible " << std::endl;
    }
    else
    {
        if (!isprint(m_character))
            std::cout << "m_character = " << "Non displayable" << std::endl;
        else
        {
            m_character = static_cast<char>(m_doubler);
            std::cout << "m_character = " << m_character << std::endl;
        }        
    }        
}
void ScalarConverter::checkInt(std::string str)
{
    std::cout << "checkInt()" << std::endl;
    char *lastPtr;
    m_doubler = strtod(str.c_str(), &lastPtr);
    if (m_doubler < std::numeric_limits<int>::min() || m_doubler > std::numeric_limits<int>::max()  )
    {
        std::cout << "int: impossible " << std::endl;
	} 
    else 
    {
		m_integer = (static_cast<int>(m_doubler));  
        std::cout << "m_integer = " << m_integer << std::endl;
	}
    
    if (m_doubler < CHAR_MIN || m_doubler > CHAR_MAX)
    {
        std::cout << "char: impossible " << std::endl;
    }
    else
    {
        m_character = static_cast<char>(m_doubler);
        if (!isprint(m_character))
            std::cout << "m_character = " << "Non displayable" << std::endl;
        else
        {
            std::cout << "m_character = " <<  "'" <<m_character << "'"<< std::endl;
        }
    }  
    std::cout << "m_doubler = " << m_doubler << ".0" << std::endl;
    if (m_doubler < -std::numeric_limits<float>::max() || m_doubler > std::numeric_limits<float>::max()  )
    {
        std::cout << "float: impossible " << std::endl;
	} 
    else
    {
        m_floater = static_cast<float>(m_doubler);
        std::cout << "m_floater = " << m_floater << ".0f" << std::endl;
		
	}
}

void ScalarConverter::checkstr(std::string str)
{
    char *lastPtr;
    std::cout << "checkstr()" << std::endl;
    m_doubler = strtod(str.c_str(), &lastPtr);
    std::cout << "char: impossible" << std::endl;
    m_integer = static_cast<int>(m_doubler);
    std::cout << "int: impossible" << std::endl;
    m_floater = static_cast<float>(m_doubler);
    std::cout << "float: " << m_floater << "f" << std::endl;
    std::cout << "double: " << m_doubler << std::endl;
}