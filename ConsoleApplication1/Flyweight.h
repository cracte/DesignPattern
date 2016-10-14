#include <iostream>
#include <map>

using namespace std;
class Flyweight
{
    public:
    virtual void operation(int id) = 0;
};

class ConcreteFlyweight1 :public Flyweight
{
    public:
    void operation(int id)
    {
        printf("ConcreteFlyweight1 Operation:%d\n", id);
    }
};

class ConcreteFlyweight2 :public Flyweight
{
    public:
    void operation(int id)
    {
        printf("ConcreteFlyweight2 Operation:%d\n", id);
    }
};

class ConcreteFlyweight3 :public Flyweight
{
    public:
    void operation(int id)
    {
        printf("ConcreteFlyweight3 Operation:%d\n", id);
    }
};

class FlyweightFactory
{
    private:
    map<int, Flyweight*> m_flyweightVec;
    public:
    Flyweight* getFlyweight(int key)
    {
        if (m_flyweightVec[key] != nullptr)
            return m_flyweightVec[key];
        else
        {
            if (key == 1)
            {
                ConcreteFlyweight1* flyweight = new ConcreteFlyweight1();
                m_flyweightVec[key] = flyweight;
                return flyweight;
            }
            else if (key == 2)
            {
                ConcreteFlyweight2* flyweight = new ConcreteFlyweight2();
                m_flyweightVec[key] = flyweight;
                return flyweight;
            }
            else if (key == 3)
            {
                ConcreteFlyweight3* flyweight = new ConcreteFlyweight3();
                m_flyweightVec[key] = flyweight;
                return flyweight;
            }
        }
        return nullptr;
    }
};