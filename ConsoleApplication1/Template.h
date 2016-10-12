#include <iostream>

class Template
{
    public:
    virtual void operation1() = 0;
    virtual void operation2() = 0;
    virtual void operation3() = 0;

    void function() //定义模版的公共方法
    {
        operation3();
        operation1();
        operation2();
    }
};

class ConcreteClass :public Template
{
    public:
    void operation1() //具体类有差别的方法
    {
        printf("ConcreteClass Operation 1\n");
    }

    void operation2()
    {
        printf("ConcreteClass Operation 2\n");
    }

    void operation3()
    {
        printf("ConcreteClass Operation 3\n");
    }
};