#include<iostream>
#include<vector>
#include<string>

#include<sstream>
#include<ostream>
#include "observable.hpp"



class Person: public Observable <Person>
{
	int age;
	// getters and setters
	
	public:
		Person (int age) : age(age) {}
	int get_age() const
	{
		return age;

	}

	void set_age(int age)
	{
	
		// we will say if 
		if(this->age == age) return;
		this->age= age;
		notify (*this, "age");
	}

};

//observer and observable
//

struct ConsolePersonObserver:public Observer<Person>
{
	private:
		void field_changed(Person &source, const std::string & field_name) override
		{
			std::cout<<"Person's"<<field_name<<"has changed to ":
			if(field_name== "age") 
			{
				std::cout<<source.get_age();
				std::cout<<endl;
			}
		}
};


// observer and the observable are the two components
// observer is the one which wants to monitor.


int main()
{
	Person person {10};
	ConsolePersonObserver cpo;
	person.subscribe(cpo);
	person.set_age(11);
	person.set_age(12);
	person.unsubscribe(cpo);
	person.set_age(13);
	return 0;
}


