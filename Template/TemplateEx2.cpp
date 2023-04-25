#include <iostream>

using namespace std;

class CaffeinBeverage{
    public:
        void templateMethods(){
            boilWater();
            brew();
            pourInCup();
            if(customWantCondiment()){
                addCondiment();
            }
        }
        
        void boilWater() { cout << "\nBoiling Water - "; }
        void pourInCup() { cout << "\nPouring Water In Cup - "; }
        
        virtual void brew() const = 0;
        virtual void addCondiment() const = 0;
        
        //hook
        virtual bool customWantCondiment(){ return false; };
};


class TeaHook: public CaffeinBeverage{
    public:
        virtual void brew() const { cout << "Dropping tea through filter."; }
        virtual void addCondiment() const { cout << "\nAdding bubble and milk."; }
};

class CaffeHook: public CaffeinBeverage{
    public:
        virtual void brew() const { cout << "Dropping coffee through filter."; }
        virtual void addCondiment() const { cout << "\nAdding milk."; }
        
        virtual bool customWantCondiment(){ return true; }
};

int main()
{
    TeaHook tea;
    CaffeHook coffee;
    
    coffee.customWantCondiment();
    coffee.templateMethods();
    cout << endl;
    tea.templateMethods();

    return 0;
}
