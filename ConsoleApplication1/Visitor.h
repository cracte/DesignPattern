#include <iostream>
using namespace std;

class ConcreteElementA;
class ConcreteElementB;

class Visitor //访问者
{
    public:
    virtual void visitConcreteElementA(ConcreteElementA* elementA) = 0;  //对元素A进行访问的方法
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

class Element //被访问的元素
{
    public:
    virtual void accept(Visitor* visitor) = 0; //收到访问者的访问
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

class ObjectStructure //管理访问者访问每个元素
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
    visitor->visitConcreteElementA(this); //接受访问者的访问，调用访问者访问后的结果
}

void ConcreteElementB::accept(Visitor* visitor)
{
    visitor->visitConcreteElementB(this);
}