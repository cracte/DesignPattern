#include <iostream>
#include <vector>
#include <algorithm>

class Observer //抽象观察者 
{
    public:
    virtual void update() = 0;
};

class Inform //抽象通知者
{
    private:
    std::vector<Observer*> m_ObserverVec;
    public:
    void addObserver(Observer* observer)
    {
        m_ObserverVec.push_back(observer);
    }

    void delObserver(Observer* observer)
    {
        std::vector<Observer*>::iterator it = std::find(m_ObserverVec.begin(), m_ObserverVec.end(), observer);
        if (it != m_ObserverVec.end())
        {
            m_ObserverVec.erase(it);
        }
    }

    void Notify()
    {
        std::vector<Observer*>::iterator it = m_ObserverVec.begin();
        for (; it != m_ObserverVec.end(); ++it)
        {
            (*it)->update();
        }
    }
};

class ConcertObserver1 : public Observer
{
    private:
    std::string m_name;
    public:
    ConcertObserver1(std::string name)
    {
        m_name = name;
    }
    void update()
    {
        printf("%s:update 1\n", m_name.c_str());
    }
};

class ConcertObserver2 :public Observer
{
    private:
    std::string m_name;
    public:
    ConcertObserver2(std::string name)
    {
        m_name = name;
    }
    void update()
    {
        printf("%s:update 2\n", m_name.c_str());
    }
};

class ConcertInform1 :public Inform //具体通知类
{
    private:
    int m_state;
    public:
    int getState()
    {
        return m_state;
    }
};

