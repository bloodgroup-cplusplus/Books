#include<iostream>
#include<string>
#include<vector>
#include<sstream>

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"



int main__()
{
	Person p= Person::create().lives.at("123 London Road").with_postcode("SW1 1GB").in("London").works().at("pragmaSoft").as_a("consultant").earning(10e6);
	std::cout<<p<<std::endl;
	getchar();
	return 0;
}


