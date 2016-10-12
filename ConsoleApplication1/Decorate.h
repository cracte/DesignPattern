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
    void SetComponent(Component* component) //���װ�����
    {
        m_compoent = component;
    }
    void Operation() //ִ��װ�β���
    {
        if (m_compoent != nullptr)
            m_compoent->Operation();
    }
};

class ConcreteDecorateA :public Decorate //����װ����
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

class ConcreteEntity :public Component //��Ҫ���װ�ε�ʵ��
{
    void Operation()
    {
        printf("The Decorate is:\n");
    }
};