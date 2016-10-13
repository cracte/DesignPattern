#include <iostream>

class Node
{
    protected:
    std::string m_name;
    public:
    virtual void addNode(Node* node) = 0;
    virtual void removeNode(Node* node) = 0;
    virtual void display(int deep) = 0;
};

class Leaf :public Node
{
    public:
    Leaf(std::string name)
    {
        m_name = name;
    }
    void addNode(Node* node)
    {
        return;
    }
    void removeNode(Node* node)
    {
        return;
    }
    void display(int deep)
    {
        for (int i = 0; i < deep; i++)
            printf("-");
        printf("%s\n", m_name.c_str());
    }
};

class Composite :public Node
{
    private:
    std::vector<Node*> m_nodeVec;
    public:
    Composite(std::string name)
    {
        m_name = name;
    }
    void addNode(Node* node)
    {
        m_nodeVec.push_back(node);
    }
    void removeNode(Node* node)
    {
        std::vector<Node*>::iterator it = std::find(m_nodeVec.begin(), m_nodeVec.end(), node);
        if ( it != m_nodeVec.end())
        {
            m_nodeVec.erase(it);
        }
    }
    void display(int deep)
    {
        for (int i = 0; i < deep; i++)
            printf("-");
        printf("%s\n", m_name.c_str());
        
        std::vector<Node*>::iterator it = m_nodeVec.begin();
        for (; it != m_nodeVec.end(); ++it)
        {
            (*it)->display(deep + 2);
        }
    }
};