#include <iostream>

class Singleton
{
    private:
    Singleton()
    {

    }
    public:
    static Singleton* instance()
    {
        static Singleton* m_instance = new Singleton();
        return m_instance;
    }

    void print()
    {
        printf("singleton print\n");
    }
};