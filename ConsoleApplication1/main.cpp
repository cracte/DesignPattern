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

    Originator* orig = new Originator(1, 2);
    orig->print();
    Caretaker* taker = new Caretaker();
    taker->setMemento(orig->createMemento());
    orig->setState(4);
    orig->print();
    orig->recoverMemento(taker->getMemento());
    orig->print();

    char a;
    scanf_s("%s",&a);
}