#include <iostream>
using namespace std;

class AbstractExpression
{
    public:
    virtual int interpreter(char* ch) = 0;
};

class TerminalExpression :public AbstractExpression
{
    public:
    int interpreter(char* ch)
    {
        int result = 0;
        switch (*ch)
        {
            case 'a':
                result = 1;
                break;
            case 'b':
                result = 2;
                break;
            case 'c':
                result = 3;
                break;
            default:
                result = 9;
        }
        return result;
    }
};

class NonTerminalExpression :public AbstractExpression
{
    public:
    int interpreter(char* ch)
    {
        int result = 0;
        return result;
    }
};

class Context
{
    private:
    string m_string;
    TerminalExpression* expression1;
    NonTerminalExpression* expression2;
    public:
    Context()
    {
        expression1 = new TerminalExpression();
        expression2 = new NonTerminalExpression();
    }
    string getString()
    {
        return m_string;
    }
    void setString(string str)
    {
        m_string = str;
    }
    void interpreter()
    {
        string result = "";
        if (m_string.length() <= 0)
            return;
        for (unsigned int i = 0; i < m_string.length(); i++)
        {
            result += expression1->interpreter(&m_string[i]);
        }
        printf("%s", result.c_str());
    }
};