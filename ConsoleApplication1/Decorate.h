#include <iostream>
class Component
{
public:
    virtual void Operation()=0;
};

class Decorate :public Component
{
protected:
    Component* m_compoent;

public:
    void SetComponent(Component* component) //添加装饰组件
    {
        m_compoent = component;
    }
    void Operation() //执行装饰操作
    {
        if (m_compoent != nullptr)
            m_compoent->Operation();
    }
};

class ConcreteDecorateA :public Decorate //具体装饰类
{
    public:
    void Operation()
    {
        Decorate::Operation();
        printf("do ConcreteDecorateA\n");
    }
};

class ConcreteDecorateB :public Decorate
{
    public:
    void Operation()
    {
        Decorate::Operation();
        printf("do ConcreteDecorateB\n");
    }
};

class ConcreteEntity :public Component //需要添加装饰的实体
{
    void Operation()
    {
        printf("The Decorate is:\n");
    }
};