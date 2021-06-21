/* creational design patterns are design pattersn that deal with
object creation mechansims, trying to create objects in a manner suitable to the situtation.
The basic form of object creatino could result in deisgn problems or added complexity to the
design. Creational design patterns solve this problem by somehow controlling this object creation

Builder: The builder creational pattern is used to seperate the construction of complex object fro
its representation so that the same construction process can create different objects
Problem: 
We wan't to consturct a complex object, however we do not want to have a complex consturctor
member or one tha would need many arguments.
Define an intermediate object whose member functions define the desired object part by
part before the object is available to the client. Builder Pattern lets us defer the
construction ob the object untill all the options for creation have been specifited

*/

#include <iostream>
#include <memory>
class Pizza{
public:
    void setDough(const std::string& dough){
        m_dough = dough;
    }
    void setSauce(const std::string& sauce){
        m_sauce = sauce;
    }
    void setTopping(const std::string& topping){
        m_topping = topping;
    }
    void open() const {
        std::cout<<"The Pizza have "<<
        m_dough<<" dough, "<<
        m_sauce<<" sauce, "<<
        m_topping<<" topping."<<
        std::endl;
    }
private:
    std::string m_dough;
    std::string m_sauce;
    std::string m_topping;
};

class PizzaBuilder{
public:
    virtual ~PizzaBuilder() = default;
    void createNewPizza(){
        m_pizza = std::make_unique<Pizza>();
    }
    Pizza* getPizza() {
        return m_pizza.release();
    }
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
protected:
    std::unique_ptr<Pizza> m_pizza;
};

class HawaiianPizzaBuilder:public PizzaBuilder{
public:
    ~HawaiianPizzaBuilder() override = default;
    void buildDough() override {
        m_pizza->setDough("Hawaiian dough");
    }
    void buildSauce() override {
        m_pizza->setSauce("Hawaiian sauce");
    }
    void buildTopping() override {
        m_pizza->setTopping("Hawaiian topping");
    }
};

class SpicyPizzaBuilder:public PizzaBuilder{
public:
    ~SpicyPizzaBuilder() override = default;
    void buildDough() override {
        m_pizza->setDough("Spicy dough");
    }
    void buildSauce() override {
        m_pizza->setSauce("Spicy sauce");
    }
    void buildTopping() override {
        m_pizza->setTopping("Spicy topping");
    }
};

class Cook{
public:
    void openPizza() const {
        m_pizzaBuilder->getPizza()->open();
    }
    void createPizza(PizzaBuilder* pizzaBuilder){
        m_pizzaBuilder = pizzaBuilder;
        m_pizzaBuilder->createNewPizza();
        m_pizzaBuilder->buildDough();
        m_pizzaBuilder->buildSauce();
        m_pizzaBuilder->buildTopping();
    }
private:
    PizzaBuilder* m_pizzaBuilder;
};

int main(){
    Cook cook{};
    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    cook.createPizza(&hawaiianPizzaBuilder);
    cook.openPizza();

    SpicyPizzaBuilder spicyPizzaBuilder;
    cook.createPizza(&spicyPizzaBuilder);
    cook.openPizza();
}
//console output
//The Pizza have Hawaiian dough dough, Hawaiian sauce sauce, Hawaiian topping topping.
//The Pizza have Spicy dough dough, Spicy sauce sauce, Spicy topping topping.

























