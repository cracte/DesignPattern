#include <iostream>

class Manufacture //产品
{
    private:
    int partA;
    int partB;
    int partC;
    public:
    void setPartA(int value)
    {
        partA = value;
    }
    void setPartB(int value)
    {
        partB = value;
    }
    void setPartC(int value)
    {
        partC = value;
    }
    void print()
    {
        printf("%d,%d,%d\n", partA, partB, partC);
    }
};

class Builder
{
    public:
    virtual void createPartA() = 0; //创建产品各个零件
    virtual void createPartB() = 0;
    virtual void createPartC() = 0;
    virtual Manufacture* output() = 0; //输出产品
};

class ConcreteBuilder1 :public Builder //创建具体产品，生成器模式是一个生成器生成一个产品，工厂模式可以创建多个产品
{
    private:
    Manufacture* m_manufacture;
    public:
    ConcreteBuilder1()
    {
        m_manufacture = new Manufacture();
    }
    void createPartA()
    {
        m_manufacture->setPartA( 1);
    }

    void createPartB()
    {
        m_manufacture->setPartB(1);
    }

    void createPartC()
    {
        m_manufacture->setPartC(1);
    }
    Manufacture* output()
    {
        return m_manufacture;
    }
};

class ConcreteBuilder2 :public Builder
{
    private:
    Manufacture* m_manufacture;
    public:
    ConcreteBuilder2()
    {
        m_manufacture = new Manufacture();
    }
    void createPartA()
    {
        m_manufacture->setPartA(2);
    }

    void createPartB()
    {
        m_manufacture->setPartB(3);
    }

    void createPartC()
    {
        m_manufacture->setPartC(2);
    }
    Manufacture* output()
    {
        return m_manufacture;
    }
};

class Director
{
    public:
    void Construct(Builder* bulder) //指导创建者具体创建步骤
    {
        bulder->createPartB();
        bulder->createPartC();
        bulder->createPartA();
    }
};