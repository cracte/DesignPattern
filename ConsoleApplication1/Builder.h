#include <iostream>

class Manufacture //��Ʒ
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
    virtual void createPartA() = 0; //������Ʒ�������
    virtual void createPartB() = 0;
    virtual void createPartC() = 0;
    virtual Manufacture* output() = 0; //�����Ʒ
};

class ConcreteBuilder1 :public Builder //���������Ʒ��������ģʽ��һ������������һ����Ʒ������ģʽ���Դ��������Ʒ
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
    void Construct(Builder* bulder) //ָ�������߾��崴������
    {
        bulder->createPartB();
        bulder->createPartC();
        bulder->createPartA();
    }
};