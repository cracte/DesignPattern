#include <iostream>

class State
{
    public:
    virtual void Handle() = 0;
};

class ConcreteState1;
class ConcreteState2;
class ConcreteState3;

class ConcreteState1 :public State
{
    private:
    State* m_state;
    public:
    void Handle()
    {
        printf("State1 Handle\n");
        m_state = this;
    }
};

class ConcreteState2 :public State
{
    private:
    State* m_state;
    public:
    void Handle()
    {
        printf("State2 Handle\n");
        m_state = new ConcreteState1();
        m_state->Handle();
    }
};

class ConcreteState3 :public State
{
    private:
    State* m_state;
    public:
    void Handle()
    {
        printf("State3 Handle\n");
        m_state = new ConcreteState2();
        m_state->Handle();
    }
};