#include <iostream>

class ProductBase //产品抽象类
{
    public:
    virtual void function() = 0;
};

class ProductA :public ProductBase //具体产品
{
    public:
    void function()
    {
        printf("ProductA function\n");
    }
};

class ProductB :public ProductBase
{
    public:
    void function()
    {
        printf("ProductB function\n");
    }
};

class ProductACreator;
class ProductBCreator;

class Creator //工厂抽象类，简单工厂模式使用一个工厂生产多个产品，工厂方法一个产品对应一个方法
{
    public:
    Creator()
    {

    }
    virtual ProductBase* create() = 0;
    //{
    //    if (rand() % 2 == 0)
    //    {
    //        ProductACreator* creator = new ProductACreator();
    //        return creator->create();
    //    }
    //    else
    //    {
    //        ProductBCreator* creator = new ProductBCreator();
    //        return creator->create();
    //    }
    //}
};

class ProductACreator :public Creator //产品A的工厂，
{
    public:
    ProductACreator()
    {

    }
    ProductA* create()
    {
        return new ProductA();
    }
};

class ProductBCreator :public Creator
{
    public:
    ProductBCreator()
    {

    }
    ProductB* create()
    {
        return new ProductB;
    }
};