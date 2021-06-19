/* If expr is an lvalue, both T and paramtype are deduced to be lavalue refrences.
	That's doubly unusual. First, it's the only situation in template type deduction
	where T is deduced to be a refrence. Secon, although ParamType is declared using the syntax
	for an rvalue refrence, its deduced type is an lvalue refrence.
	
	If expr is an rvalue, the "normal"(i.e Case1) rules applies.
	
*/

#include<iostream>
template<typename T>

void f( T&&param)
{
	std::cout<<param<<std::endl;
}

int main()
{
	int x=27; // x is an int
	const int cx=x; // cx is a const int
	const int& rx=x; // rx is a refrence to x as a const int;
	f(x); // x is lvalue so T is int & param is also const int &
	f(rx); // rx is lvalue, so T is const int & param type is also const int &
	f(27); // 27 is rvalue, so T is int, param's type is therefore int &&
	return 0;
}

	
