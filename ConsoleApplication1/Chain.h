#include <iostream>

class Handler
{
    protected:
    Handler* m_successor;
    public:
    virtual void setSuccessor(Handler* successor)
    {
        m_successor = successor;
    }
    virtual void handleRequest(int request) = 0;
};

class ConcreteHandler1:public Handler
{
    public:
    void handleRequest(int request)
    {
        if (request >= 0 && request < 10)
        {
            printf("ConcreteHandler1 finish request = %d\n", request);
        }
        else if ( m_successor != nullptr)
        {
            m_successor->handleRequest(request);
        }
    }
};

class ConcreteHandler2 :public Handler
{
    public:
    void handleRequest(int request)
    {
        if (request >= 10 && request < 20)
        {
            printf("ConcreteHandler2 finish request = %d\n", request);
        }
        else if ( m_successor != nullptr)
        {
            m_successor->handleRequest(request);
        }
    }
};

class ConcreteHandler3 :public Handler
{
    public:
    void handleRequest(int request)
    {
        if (request >= 20 && request < 30)
        {
            printf("ConcreteHandler3 finish request = %d\n", request);
        }
        else if (m_successor != nullptr)
        {
            m_successor->handleRequest(request);
        }
    }
};