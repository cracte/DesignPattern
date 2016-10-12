#include <iostream>

class Memento
{
    private:
    int m_state;
    int m_index;
    public:
    Memento(int state, int index)
    {
        m_state = state;
        m_index = index;
    }
    int getState()
    {
        return m_state;
    }
    int getIndex()
    {
        return m_index;
    }
};

class Originator
{
    private:
    int m_state;
    int m_index;
    public:
    Originator(int state, int index)
    {
        m_state = state;
        m_index = index;
    }

    Memento* createMemento()
    {
        return new Memento( m_state, m_index);
    }

    void recoverMemento(Memento* memento)
    {
        m_state = memento->getState();
        m_index = memento->getIndex();
    }

    void setState(int state)
    {
        m_state = state;
    }

    void print()
    {
        printf("The State is %d, the Index is %d \n", m_state, m_index);
    }
};

class Caretaker
{
    private:
    Memento* m_memento;
    public:
    void setMemento(Memento* memento)
    {
        m_memento = memento;
    }

    Memento* getMemento()
    {
        return m_memento;
    }
};