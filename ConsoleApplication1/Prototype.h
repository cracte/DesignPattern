#include<iostream>

class Prototype
{
    virtual Prototype* clone() = 0;
};

class ConcretePrototype :public Prototype
{
    private:
    int m_data;
    int index;

    public:
    void setIndex(int i)
    {
        index = i;
    }
    void print()
    {
        printf("then index is %d\n", index);
    }
    ConcretePrototype* clone() //原型模版就是克隆自身
    {
        ConcretePrototype* newData = new ConcretePrototype();
        newData->index = index; //既然可以直接访问私有变量
        newData->m_data = m_data;

        return newData;
    }
};