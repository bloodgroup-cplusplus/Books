#include<iostream>
template<typename T>

void f( T& param)
{
		std::cout<<param<<std::endl;
		//param is a refrence
}

int main()
{
	int x=27;// x is an int
	const int cx=x; // cx is a const int 
	const int &rx=x; // rx is a refrence to x as a const int
	f(x); // T is int, param's type is int &
	f(cx);// T is const int, param's types are again both int
	f(rx);// T's and param's types are still both int
	return 0;
}
