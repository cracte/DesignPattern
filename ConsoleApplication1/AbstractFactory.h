#include <iostream>

class AbstractProductA
{
    public:
    virtual void print() = 0;
};

class AbstractProductB
{
    public:
    virtual void output() = 0;
};

class AbstractFactory
{
    public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

class ProductA1:public AbstractProductA
{
    public:
    void print()
    {
        printf("ProductA1\n");
    }
};

class ProudctA2 :public AbstractProductA
{
    public:
    void print()
    {
        printf("ProductA2\n");
    }
};

class ProductB1 :public AbstractProductB
{
    public:
    void output()
    {
        printf("ProductB1\n");
    }
};

class ProductB2 : public AbstractProductB
{
    public:
    void output()
    {
        printf("ProductB2\n");
    }
};

class ConcreteFactory1 :public AbstractFactory
{
    public:
    AbstractProductA* createProductA()
    {
        return new ProductA1;
    }

    AbstractProductB* createProductB()
    {
        return new ProductB1;
    }
};

class ConcreteFactory2 :public AbstractFactory
{
    public:
    AbstractProductA* createProductA()
    {
        return new ProudctA2;
    }

    AbstractProductB* createProductB()
    {
        return new ProductB2;
    }
};