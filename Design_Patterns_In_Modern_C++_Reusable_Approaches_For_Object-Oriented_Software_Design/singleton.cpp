#include<iostream>

class Singleton
{
	public:
		Singleton( const Singleton&) =delete;
	
		static Singleton & Get()
		{
			return s_Instance;
		}
	
	
	private:
		Singleton() {}
	
		static Singleton s_Instance;
	
};



int main()
{
	Singleton & instance= Singleton::Get();
	
	return 0;
}
