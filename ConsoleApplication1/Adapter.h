#include <iostream>

class Adaptee
{
    public:
    void printex(int index)
    {
        printf("index is %d\n", index);
    }
};

class Adapter
{
    private:
    Adaptee* adaptee;
    public:
    Adapter()
    {
        adaptee = new Adaptee();
    }

    void print()
    {
        adaptee->printex(10);
    }
};