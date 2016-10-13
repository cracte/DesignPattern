#include "Strategy.h"
#include "Decorate.h"
#include "Proxy.h"
#include "Factory.h"
#include "Prototype.h"
#include "Template.h"
#include "Facade.h"
#include "Builder.h"
#include "Observer.h"
#include "AbstractFactory.h"
#include "State.h"
#include "Adapter.h"
#include "Memento.h"
#include "Composite.h"
#include "Singleton.h"
#include "Bridge.h"
#include "Command.h"
#include "Chain.h"

void main()
{
    //StrategyA* strategy = new StrategyA(); //现在使用的策略
    //Context::instacne().print(strategy);

    //ConcreteEntity* entity = new ConcreteEntity(); //需要装饰的实体
    //ConcreteDecorateA* decorateA = new ConcreteDecorateA(); //依次添加装饰
    //ConcreteDecorateB* decorateB = new ConcreteDecorateB();
    //decorateA->SetComponent(entity);
    //decorateB->SetComponent(decorateA);
    //decorateB->Operation();

    //Proxy* proxy = new Proxy();
    //proxy->operation();

    //Creator* creator = new ProductBCreator; //选择工厂
    //ProductBase* product = creator->create();
    //product->function();

    //ConcretePrototype* entity1 = new ConcretePrototype();
    //entity1->setIndex(12);
    //ConcretePrototype* entity2 = entity1->clone();
    //entity1->print();
    //entity2->print();

    //ConcreteClass* instance = new ConcreteClass();
    //instance->function();

    //Facade* facade = new Facade();
    //facade->Method3();

    //Director* diector = new Director();
    //ConcreteBuilder2* builder = new ConcreteBuilder2(); //具体创建者
    //diector->Construct(builder); //知道创建者创建步骤
    //Manufacture* manu = builder->output();
    //manu->print();

    //ConcertObserver1* obs1 = new ConcertObserver1("obs1");
    //ConcertObserver2* obs2 = new ConcertObserver2("obs2A");
    //ConcertInform1* inform = new ConcertInform1();
    //inform->addObserver(obs1);
    //inform->addObserver(obs2);
    //inform->delObserver(obs2);
    //inform->addObserver(obs2);
    //inform->Notify();

    //ConcreteFactory1* factory1 = new ConcreteFactory1();
    //ConcreteFactory2* factory2 = new ConcreteFactory2();
    //AbstractProductA* producta2 = factory2->createProductA();
    //AbstractProductB* productB1 = factory1->createProductB();
    //producta2->print();
    //productB1->output();

    //State* m_state = new ConcreteState2();
    //m_state->Handle();

    //Adapter* adapter = new Adapter();
    //adapter->print();

    //Originator* orig = new Originator(1, 2);
    //orig->print();
    //Caretaker* taker = new Caretaker();
    //taker->setMemento(orig->createMemento());
    //orig->setState(4);
    //orig->print();
    //orig->recoverMemento(taker->getMemento());
    //orig->print();

    //Composite* root = new Composite("root");
    //Composite* com1 = new Composite("a");
    //root->addNode(com1);
    //Composite* com2 = new Composite("f");
    //com1->addNode(com2);
    //Composite* com3 = new Composite("d");
    //Composite* com4 = new Composite("r");
    //com1->addNode(com3);
    //Leaf* leaf1 = new Leaf("L1");
    //com3->addNode(com4);
    //com3->addNode(leaf1);
    //Leaf* leaf2 = new Leaf("L2");
    //com4->addNode(leaf2);
    //root->display(2);

    //Singleton::instance()->print();
    //Singleton::instance()->print();

    //ConcreteImplementor2* implementor = new ConcreteImplementor2();
    //RefinedAbstraction* refined = new RefinedAbstraction();
    //refined->setImplementor(implementor);
    //refined->operation();

    //Receiver* receiver = new Receiver();
    //ConcreteCommand2* command1 = new ConcreteCommand2(receiver);
    //ConcreteCommand1* command2 = new ConcreteCommand1(receiver);
    //ConcreteCommand1* command3 = new ConcreteCommand1(receiver);
    //Invoker* invoker = new Invoker();
    //invoker->addCommand(command1);
    //invoker->addCommand(command2);
    //invoker->addCommand(command3);
    //invoker->executeCommand();

    ConcreteHandler1* handler1 = new ConcreteHandler1();
    ConcreteHandler2* handler2 = new ConcreteHandler2();
    ConcreteHandler3* handler3 = new ConcreteHandler3();
    handler1->setSuccessor(handler2);
    handler2->setSuccessor(handler3);
    handler1->handleRequest(3);
    handler1->handleRequest(14);
    handler1->handleRequest(25);

    char a;
    scanf_s("%s",&a);
}