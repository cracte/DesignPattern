#include <iostream>

class SubSystem1 //子系统
{
    public:
    void MethodA()
    {
        printf("SubSystem1 MethodA\n");
    }

    void MehtodB()
    {
        printf("SubSystem1 MethodB\n");
    }
};

class SubSystem2
{
    public:
    void MethodA()
    {
        printf("SubSystem2 MethodA\n");
    }

    void MethodB()
    {
        printf("SubSystem2 MethodB\n");
    }
};

class SubSystem3
{
    public:
    void MethodA()
    {
        printf("SubSystem3 MethodA\n");
    }

    void MethodB()
    {
        printf("SubSystem3 MethodB\n");
    }
};
class Facade 
{
    private:
    SubSystem1 system1; //子系统是外观的成员变量
    SubSystem2 system2;
    SubSystem3 system3;

    public:
    void Method1()
    {
        system3.MethodB();
        system2.MethodA();
    }

    void Method2()
    {
        system1.MehtodB();
    }

    void Method3()
    {
        system1.MethodA();
        system2.MethodB();
        system3.MethodA();
    }
};