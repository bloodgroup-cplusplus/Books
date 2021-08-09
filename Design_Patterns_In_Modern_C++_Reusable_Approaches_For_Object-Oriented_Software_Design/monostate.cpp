//varitation on singelton
//


#include<string>
#include<vector>
#include<ostream>
#include<sstream>


class Printer
{

	// we make the printer appear to be ordinary class 
	// except all of the data storage for printer is static storage
	// we want all class to be singleton.
	
	static int id;
	public:
		int get_id() const{return id;}

		void set_id(int value) {id =value;}

};



int main()
{

	Printer p;

	int id= p.get_id();
	// all of the state is going into static member 
	// both of the printer are working with the same data
	// inheritence is really bad as we have id as non inheritable member
	// the worst issue is that client is not infromed that it is a singleton
	// whatever the latest set opertaion is 
	// only static location where data is kept.
	// it is a viable solution to singletion it is a solution which brings a lot of drawback
	
}

