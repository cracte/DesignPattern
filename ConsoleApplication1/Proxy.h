#include <iostream>

class Subject //代理与实体的抽象类
{
    public:
    virtual void operation() = 0;
};

class RealSubject:public Subject
{
    public:
    void operation()
    {
        printf("Do the Operation\n");
    }
};

class Proxy:public Subject
{
    public:
    void operation()
    {
        if (m_realSubject == nullptr)
        {
            m_realSubject = new RealSubject;
        }
        m_realSubject->operation();
    }
    private:
    RealSubject* m_realSubject;
};