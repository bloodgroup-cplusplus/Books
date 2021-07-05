#include<boost/flyweight/flyweight.hpp>
#include<iostream>
#include<string>
struct User2
{
	flyweight<std::string> first_name,last_name;
	User2(const std::string & first_name, const std::string & last_name):first_name{first_name},last_name{last_name}{}
	protected:
		uint32_t first_name,last_name;

};


int main()
{
	User2 john_doe{"John","Doe"};
	User2 jane_doe{"Jane","Doe"};
	std::cout<<std::boolalpha<<(&jane_doe.last_name.get()==&john_doe.last_name.get());	
	return 0;
}

