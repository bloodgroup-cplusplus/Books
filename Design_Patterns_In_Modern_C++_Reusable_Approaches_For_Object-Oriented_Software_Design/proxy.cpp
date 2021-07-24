/* an interface for accessing a particular resource.

   MOTIVATION
   	* say you are calling foo.bar()
	* this assumes that foo is in the same process as bar()
	* what if, later on , you want to put all Foo-related operations into a seperate process
	* 	Can you avoid changing your code?
	* This is where proxy is used
	* 	Same interface, entirely different behaviour
	* This is called a communication proxy
	* 	Other types: logging, virtual etc.
	*
	*
PROXY:	A class that functions as an interface to a particular resource. That resource may be remote, expensive to construct, or may require logging or some other added functionality.


smart pointers are proxy.
*/


#include<memory>

#include<iostream>
#include<ostream>
#include<vector>
#include<string>
struct BankAccount
{
	virtual  ~BankAccount()=default;
	virtual void deposit (int amount)=0;
	virtual void withdraw (int amount)=0;
};



struct CurrentAccount: BankAccount
{
	explicit CurrentAccount( int balance) :balance(balance)
	{
	}


	void deposit (int amount) override
	{
		balance+=amount;
	}

	void withdraw(int amount) override
	{
		if(amount <=balance) balance-= amount;
	}



	friend std::ostream & operator <<(std::ostream & os, const CurrentAccount & obj)
	{
		return os<< "balance" <<obj.balance;
	}


	private:
		int balance;
};

int main()
{
	BankAccount * a= new CurrentAccount(123);
	a->deposit(321);
	delete a;
	// when you use a smart pointer instead you will get something that behaves like ordinary pointer
	auto b= std::make_shared<CurrentAccount>(123);
	BankAccount * acutal = b.get() ; // enhancement over the api that we have.
	//enhancement for correct pointer and call something on the pointer or the original object and in this case
	//b acts as an ordinary pointer 
	// smart pointer on b is also valid as it is on a
	// proxy is an object that looks and behaves like shared pointer or unique pointer
	
	return 0;
}

