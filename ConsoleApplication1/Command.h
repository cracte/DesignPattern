#include <iostream>
#include <vector>

using namespace std;
class Receiver //命令执行者
{
    public:
    void function1()
    {
        printf("receiver function1\n");
    }
    void function2()
    {
        printf("receiver function2\n");
    }
};

class Command
{
    public:
    virtual void execute() = 0;
};

class ConcreteCommand1 :public Command
{
    private:
    Receiver* m_receiver;
    public:
    ConcreteCommand1(Receiver* receiver)
    {
        m_receiver = receiver;
    }
    void execute()
    {
        m_receiver->function1();
    }
};

class ConcreteCommand2:public Command
{
    private:
    Receiver* m_receiver;
    public:
    ConcreteCommand2(Receiver* receiver)
    {
        m_receiver = receiver;
    }
    void execute()
    {
        m_receiver->function2();
    }
};

class Invoker //命令发布者
{
    private:
    vector<Command*> m_commandVec;
    public:
    void addCommand(Command* command)
    {
        m_commandVec.push_back(command);
    }
    void removeCommand(Command* command)
    {
        vector<Command*>::iterator it = find(m_commandVec.begin(), m_commandVec.end(), command);
        if (it != m_commandVec.end())
        {
            m_commandVec.erase(it);
        }
    }
    void executeCommand()
    {
        vector<Command*>::iterator it = m_commandVec.begin();
        for (; it != m_commandVec.end(); ++it)
        {
            (*it)->execute();
        }
    }
};