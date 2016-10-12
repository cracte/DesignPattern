#include <iostream>

class ProductBase //��Ʒ������
{
    public:
    virtual void function() = 0;
};

class ProductA :public ProductBase //�����Ʒ
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

class Creator //���������࣬�򵥹���ģʽʹ��һ���������������Ʒ����������һ����Ʒ��Ӧһ������
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

class ProductACreator :public Creator //��ƷA�Ĺ�����
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