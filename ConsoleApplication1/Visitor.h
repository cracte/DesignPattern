#include <iostream>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor //������
{
    public:
    virtual void visitConcreteElementA(ConcreteElementA* elementA) = 0;  //��Ԫ��A���з��ʵķ���
    virtual void visitConcreteElementB(ConcreteElementB* elementB) = 0;
};

class ConcreteVisitor1 :public Visitor
{
    public:
    void visitConcreteElementA(ConcreteElementA* elementA);
    void visitConcreteElementB(ConcreteElementB* elementB);
};

class ConcreteVisitor2 :public Visitor
{
    public:
    void visitConcreteElementA(ConcreteElementA* elementA);
    void visitConcreteElementB(ConcreteElementB* elementB);
};

class Element //�����ʵ�Ԫ��
{
    public:
    virtual void accept(Visitor* visitor) = 0; //�յ������ߵķ���
};

class ConcreteElementA :public Element
{
    public:
    void accept(Visitor* visitor);
};

class ConcreteElementB :public Element
{
    public:
    void accept(Visitor* visitor);
};

class ObjectStructure //��������߷���ÿ��Ԫ��
{
    private:
    vector<Element*> m_elementVec;
    public:
    void addElement(Element* element)
    {
        m_elementVec.push_back(element);
    }
    void accept(Visitor* vistor)
    {
        vector<Element*>::iterator it = m_elementVec.begin();
        for (; it != m_elementVec.end(); ++it)
        {
            (*it)->accept(vistor);
        }
    }
};

void ConcreteVisitor1::visitConcreteElementA(ConcreteElementA* elementA)
{
    printf("1 visit A \n");
}

void ConcreteVisitor1::visitConcreteElementB(ConcreteElementB* elementB)
{
    printf("1 visit B\n");
}

void ConcreteVisitor2::visitConcreteElementA(ConcreteElementA* elementA)
{
    printf("2 visit A\n");
}

void ConcreteVisitor2::visitConcreteElementB(ConcreteElementB* elementB)
{
    printf("2 visit B\n");
}

void ConcreteElementA::accept(Visitor* visitor)
{
    visitor->visitConcreteElementA(this); //���ܷ����ߵķ��ʣ����÷����߷��ʺ�Ľ��
}

void ConcreteElementB::accept(Visitor* visitor)
{
    visitor->visitConcreteElementB(this);
}