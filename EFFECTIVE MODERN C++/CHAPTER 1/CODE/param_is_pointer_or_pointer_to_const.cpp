#include<iostream>
template<typename T>
void f( T *param) //param is now a pointer
{
	std::cout<<param<<std::endl;
}


int main()
{
	int x=27;
	const int *px=&x;
	f(&x); //T is const int
	f(px); //T is const int, param's type is const int *
	return 0;
}

