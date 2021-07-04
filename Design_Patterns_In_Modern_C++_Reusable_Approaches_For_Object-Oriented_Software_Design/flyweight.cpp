/* A flyweight is a temporary component that acts as a "smart refrence" to something
 * Flyweights are used in situations where you have a very large number of very
 * similar objects, and you want to minimize the amount of memory that is dedicated to storing all these values
 * let's see the scenario when this is useful
 * Imagine a massively multiplayer online game. there is more than one person
 * or user called John Smith as it is popular
 * So if we wer to store the name over and over we would be spending 11 bytes
 * for every such user. Instead, we could stoer the name once and store
 * a pointer to every user with that name ( which is only 8 bytes)
 *
 *
 */

#include<sstream>
#include<sstream>
#include<iostream>
#include<string>
#include<boost/bimap/bimap.hpp>
struct User
{
	User(const std::string & first_name, const std::string &last_name): first_name{add(first_name)},last_name{add(last_name)}{}


	protected:
		uint32_t first_name,last_name;
		static bimap<uint32_t, std::string> names;
		static uint32_t seed;
		static uint32_t add(const std::string &s); 
		const std::string & get_first_name() ;

		const std::string & get_last_name();
};

// Constructor initializes the members first_name and last_name with the result of calling the add() function.
// this function inserts the key-value pairs into the names structure as necessary.
// boost::bimap( a bidirectional map) makes it easier to search for duplicates if the first name is already in the index we jsut
// return an index to it.
//


static uint32_t add( const std::string &s)
{
	auto it= names.right.find(s);
	if(it==names.right.end())
	{
		names.insert({++seed,s});
		return seed;
	
	}

	return it->second;

}
const std::string & get_first_name() const
{
	return names.left.find(last_name)->second;
}

const std::string & get_last_name() const
{
	return names.left.find(last_name)->second;

}

friend ostream & operator <<(std::ostream & os, const User &obj)
{
	return os<<"first_name:"<<obj.get_first_name() <<"last_name:"<<obj.get_last_name();<<std::endl;
}

int main()
{
	User john_doe{"John","Doe"};
	User jane_doe{"Jane","Doe"};
}


