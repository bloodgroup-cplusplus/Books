#include<iostream>
#include<string>

class Employee
{
	public:
		Employee( std::string name, std::string id);
		std::string  getName() const;
		std::string getId() const;

	private:
		std::string m_name;
		std::string m_id;

};

