#include<iostream>
#include<vector>
#include<ostream>

//simiulate bank account
// starting balance and overdraft limit
//


struct BankAccount
{
		int balance {0};
		int overdraft_limit {-500};


		void deposit( int amount)
		{
			balance+= amount;

			std::cout<<"Deposited" <<amount <<" balance is now " <<balance <<std::endl;
		}


		void withdraw( int amount)
		{
			if(balance-amount >= overdraft_limit)
			{
				balance-=amount;

				std::cout<<" withdrawn  amount = " << amount << " balance is now " << balance << std::endl;
			}

		}
		friend std::ostream & operator << (std::ostream & os, const BankAccount & account) {
			os <<"balance: " <<account.balance;
			return os;
	}


};

// we should also have an audit log 
//

struct Command
{
	virtual void call ()=0;
	// when we call the function an audit is attached
	
};


struct BankAccountCommand: Command
{
	BankAccount & account;
	enum Action {deposit, withdraw } action;
	int amount;
	BankAccountCommand ( BankAccount & account, Action action, int amount) : account(account), action(action), amount(amount) {}

	void call () override
	{
		switch(action)
		{
			case deposit:
				account.deposit(amount);
				break;
			case withdraw:
				account.withdraw(amount);
				break;
		}
	}
};


int main()
{
	BankAccount ba;
	std::vector<BankAccountCommand> commands;
	{
		BankAccountCommand{ba, BankAccountCommand::deposit, 100};
		BankAccountCommand{ba, BankAccountCommand::withdraw,200};
	};
	std::cout<<ba<<std::endl;
	for(auto & cmd:commands)
	{
		cmd.call();
	}

	std::cout<<ba<<std::endl;

	return 0;
}




