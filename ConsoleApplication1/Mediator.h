#include <iostream>

using namespace std;

class ConcreteColleague1;
class ConcreteColleague2;

class Mediator
{
    private:
    ConcreteColleague1* colleague1;
    ConcreteColleague2* colleague2;
    public:
    void setColleague1(ConcreteColleague1* colleague);
    void setColleague2(ConcreteColleague2* colleague);
    void send(string msg);
};

class Colleague
{
    protected:
    Mediator* m_mediator;
    public:
    virtual void send( string msg) = 0;
    virtual void operation() = 0;
};

class ConcreteColleague1 :public Colleague
{
    public:
    ConcreteColleague1(Mediator* mediator);
    void send(string msg);
    void operation();
};

class ConcreteColleague2 :public Colleague
{
    public:
    ConcreteColleague2(Mediator* mediator);
    void send(string msg);
    void operation();
};

ConcreteColleague1::ConcreteColleague1(Mediator* mediator)
{
    m_mediator = mediator;
}
void ConcreteColleague1::send(string msg)
{
    m_mediator->send(msg);
}
void ConcreteColleague1::operation()
{
    printf("ConcreteColleague1 receiver msg\n");
}

ConcreteColleague2::ConcreteColleague2(Mediator* mediator)
{
    m_mediator = mediator;
}
void ConcreteColleague2::send(string msg)
{
    m_mediator->send(msg);
}
void ConcreteColleague2::operation()
{
    printf("ConcreteColleague2 receiver msg\n");
}

void Mediator::setColleague1(ConcreteColleague1* colleague)
{
    colleague1 = colleague;
}
void Mediator::setColleague2(ConcreteColleague2* colleague)
{
    colleague2 = colleague;
}
void Mediator::send(string msg)
{
    if (msg == "a")
    {
        colleague1->operation();
    }
    else if (msg == "b")
    {
        colleague2->operation();
    }
}