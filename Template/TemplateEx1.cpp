#include <iostream>

using namespace std;

class AbstractClass{
    public:
        void templateMethod(){
            baseOperation();
            concreteOperation();
            hook();
        }
        
        void baseOperation(){ cout<< "\nBase operation invoked!"; }; 
        virtual void concreteOperation() const  = 0;
        virtual void hook() {};
};

class ConcreteClassA: public AbstractClass{
    public:
        virtual void concreteOperation() const { cout << "\nConcreteClassA operated!"; };    
};
class ConcreteClassB: public AbstractClass{
    public:
        virtual void concreteOperation() const { cout << "\nConcreteClassB operated!"; };    
        void hook(){
            cout << "\nClass B is more special!";
        }
};

int main()
{
    ConcreteClassA ca;
    ConcreteClassB cb;
    ca.templateMethod();
    cout << endl;
    cb.templateMethod();

    return 0;
}
