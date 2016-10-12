#include<iostream>

class Prototype
{
    virtual Prototype* clone() = 0;
};

class ConcretePrototype :public Prototype
{
    private:
    int m_data;
    int index;

    public:
    void setIndex(int i)
    {
        index = i;
    }
    void print()
    {
        printf("then index is %d\n", index);
    }
    ConcretePrototype* clone() //ԭ��ģ����ǿ�¡����
    {
        ConcretePrototype* newData = new ConcretePrototype();
        newData->index = index; //��Ȼ����ֱ�ӷ���˽�б���
        newData->m_data = m_data;

        return newData;
    }
};