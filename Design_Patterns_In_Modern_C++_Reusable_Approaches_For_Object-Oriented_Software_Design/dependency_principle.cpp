#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<fstream>
#include<tuple>
#include<boost/lexical_cast.hpp>

// A. High-level modules should not depend on low-level modules.
// Both should depend on abstractions.
//
//B. Abstractions should not depend on details Details should depend on abstractions
//
//instead of depending on concrete type we need to 
//
//let's  model relationship between different people
//parent child sibling so let's model this using an enum class


enum class Relationship
{
	parent,
	child,
	sibling
};

// be as general as possible don't depend on the concrete type
// if some class has vector and take the vector and start iterating it to change the underlying implemntation
// person a might be 

struct Person
{
	std::string name;
};
//low level constructs for actually storing the relationships
//

struct RelationshipBrowser
{
	virtual std::vector<Person> find_all_children_of(const std::string& name)=0;
};
struct Relationships:RelationshipBrowser // low -level modules or low level construct in our design as it provides functionalites for storeage
{
	std::vector<std::tuple<Person,Relationship,Person>> relations;
	//we can provide api for adding relationship
	
	void add_parent_and_child(const Person & parent, const Person & child)
	{
		relations.push_back({parent,Relationship::parent, child});
		relations.push_back({child,Relationship::child, parent});
	}
	// now we can use this api
	//implemnt the pure virutal funtion
	std::vector<Person> find_all_children_of( const std::string & name) override
	{
		std::vector<Person> result;
		for(auto && [first, rel,second]:relations)
		{
			if(first.name==name && rel == Relationship::parent)
			{
				result.push_back(second);
			}
		}
		return result;
	}
};


//struct Research // high-level
/*
{
	Research(Relationships & relationships)
	{
		//access the details this should be avoided as high level module is depending on low level module 
		//we are going to anyway illustrate this just to show how much of a bad idea this is.
		
		auto & relations= relationships.relations; // high level module is directly dependend on the implmentation details as we know that 
		for (auto &&[first, rel, second]: relations)
		{
			// i want to find the children of john 
			if( first.name== "John" && rel == Relationship::parent)
			{
				std::cout<<"john has a child "<< second.name<<std::endl;
			}
		}
	}
};
*/
struct Research
{
	//depend just on a relationship browser
	Research( RelationshipBrowser &browser)
	{
		for(auto & child:browser.find_all_children_of("John"))
		{
			std::cout<<"John has a child called"<<child.name<<std::endl;
		}
	}
};

// if the low level struct i.e.,Relationships tries to make the datamember (i.e., relations) private 
// it tries to hide it completely. so in this case, the high level code is completely broken 
// it protects you from changing in implementation details
// so instead of directly depending on the low level model, you would depend on the interface.
// that abstraction is called as the relationship browser so we will add the code on the top
int main()
{
	Person parent{"John"};
	Person child1{"Chris"} , child2{"Matt"};
	Relationships relationships;
	relationships.add_parent_and_child(parent, child1);
	relationships.add_parent_and_child(parent, child2);

	Research _(relationships);
	return 0;
}




// speaking of dependency injectible. It allows you to specify certain defaults.
// so for example dependency injectible whenever someone wants a dependency browser
// dependency injectible would allow you to specify that whenever someone wants a relationship
// browser they should be provided to a copy or a  refrence to relationship class
// dependency injection plays on top of dependency inversion.
//





















