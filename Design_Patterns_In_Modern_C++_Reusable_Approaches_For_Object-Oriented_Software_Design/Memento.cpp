/*Memento pattern stores the state of the system and returns is as a dedicated
 * read-only object with no behaviour of its own. This "token" if you will, 
 * can be used for feeding it back into the system to restore it to the state
 * it represents
 *
 *
 */

#include<iostream>
using namespace std;

class BankAccount
{
	int balance=0;

	public:
		explicit BankAccount(const int balance):balance(balance)

		{}



