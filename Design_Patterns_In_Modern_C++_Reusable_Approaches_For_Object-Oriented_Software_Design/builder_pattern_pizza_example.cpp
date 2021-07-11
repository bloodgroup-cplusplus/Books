//builder
//allows a client object to construct a complex object by oly specifying its type and content, being shielded from the details
//Related to the object's representation. This way the construction process can be used to create different represetations.

#include<iostream>
#include<memory>
class Pizza
{
	public:
		void setDough(const std::string & dough)
		{
			m_dough= dough;
		}

		void setSauce(const std::string & sauce)
		{
			m_sauce=sauce;
		}

		void setTopping(const std::string & topping)
		{
			m_topping= topping;
		}
		void open() const
		{
			std::cout<<"the pizza have"<<m_dough<<"dough"<<m_sauce<<"sauce"<<m_topping<<"topping."<<std::endl;
		}


	private:
		std::string m_dough;
		std::string m_sauce;
		std::string m_topping;

};


class PizzaBuilder
{
	public:
		virtual ~PizzaBuilder()=default;
		void createNewPizza()
		{
			m_pizza=std::make_unique<Pizza>();
		}

		Pizza *getPizza()
		{
			return m_pizza.release();
		}


		virtual void buildDough()=0;
		virtual void buildSauce()=0;
		virtual void buildTopping()=0;

	protected:
		std::unique_ptr<Pizza> m_pizza;
};


class HawaiianPizzaBuilder:public PizzaBuilder
{
	public:
		~HawaiianPizzaBuilder() override=default;
		void buildDough() override
		{
			m_pizza->setDough("Hawaiian dough");
		}


		void buildSauce() override
		{
			m_pizza->setSauce("Hawaiian Sauce");
		}

		void buildTopping() override
		{
			m_pizza->setTopping("Hawaiian topping");
		}
};




class SpicyPizzaBuilder:public PizzaBuilder
{
	public:
		~SpicyPizzaBuilder() override=default;
		void buildDough() override
		{
			m_pizza->setDough("spicy dough");
		}

		void buildSauce() override
		{
			m_pizza->setSauce("Spicy Sauce");
		}


		void buildTopping() override
		{
			m_pizza->setTopping("Spicy topping");
		}
};


class Cook
{
	public:
		void openPizza() const
		{
			m_pizzaBuilder->getPizza()->open();
		}

		void createPizza(PizzaBuilder * pizzaBuilder)
		{
			m_pizzaBuilder=pizzaBuilder;
			m_pizzaBuilder->createNewPizza();
			m_pizzaBuilder->buildDough();
			m_pizzaBuilder->buildSauce();
			m_pizzaBuilder->buildTopping();
		}

	private:
		PizzaBuilder *m_pizzaBuilder;
};



int main()
{
	return 0;
}

