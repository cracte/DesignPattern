#include <iostream>

class Implementor
{
    public:
    virtual void operation() = 0;
};

class Abstraction
{
    protected:
    Implementor* implementor;
    public:
    void setImplementor(Implementor* imp)
    {
        implementor = imp;
    }

    virtual void operation()
    {
        printf("base class Operation\n");
        implementor->operation();
    }
};

class ConcreteImplementor1 :public Implementor
{
    public:
    void operation()
    {
        printf("ConcreteImplementor1 operation \n");
    }
};

class ConcreteImplementor2 :public Implementor
{
    public:
    void operation()
    {
        printf("ConcreteImplementor2 operation\n");
    }
};

class RefinedAbstraction :public Abstraction
{
    public:
    void operation()
    {
        printf("RefinedAbstraction Operation\n");
        implementor->operation();
    }
};