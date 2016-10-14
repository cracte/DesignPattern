#include <iostream>
class Strategy
{
public:
virtual void function() = 0;
};

class StrategyA :public Strategy
{
    void function()
    {
        printf("call strategyA");
    }
};

class StrategyB :public Strategy
{
    void function()
    {
        printf("call strategyB");
    }
};

class StrategyC :public Strategy
{
    void function()
    {
        printf("call strategyC");
    }
};

class Market
{
public:
    Market()
    {

    }
    static Market instacne()
    {
        return m_context;
    }

    void print(Strategy* strategy) //根据不同策略执行算法
    {
        strategy->function();
    }

private:
    static Market m_context;
};