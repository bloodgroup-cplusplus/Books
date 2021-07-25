/* c# have the idea of  properties which is simply a field + a getter and setter to a field.
 * let's have properties in c++
 * we can construct a simple template class as if it were to act as a property
 */


#include<iostream>
#include<string>
#include<vector>
#include<ostream>

/* this is a class way of doing it with getters and setters . Now instead of doing all these we could be doing it with proprty proxies. The highlited code is the naive way of doing it.
struct Creature
{
	int strength {10};
	int agility {10};

	int getStrength() const
	{
		return strength;
	}


	void setStrength(int strength)
	{
		Creature::strength=strength;
	}

	int getAgility() const
	{
		return agility;
	}


	void setAgility(int agility)
	{
		Creature::agility=agility;
	}



};







*/

template<typename T > struct Property
{
	T value;
	Property(T value) :value(value) 
	{
		*this=value;
		// what is assigning value in C++ 
		// property as wrapper for integer

	}
	operator T ()
	{
		return value;
	}


	T operator = (T new_value)
	{
		std::cout<<"Assignment\n";
		return value= new_value;
	}
};


// this creature struct implements the given Property
struct Creature
{
	Property<int> strength{10};
	Property<int> agility{5};
};

int main()
{
	Creature c;
	c.strength =15;
	int x = c.agility;
	// let's say we want something which is a property 



	return 0;
}
