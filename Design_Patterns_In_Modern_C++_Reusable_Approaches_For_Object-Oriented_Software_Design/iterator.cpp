/*facilitates traversal of data structures
 * Iterator is a core functionality of various data structures
 * An iterator is a class that facilitates the traversal
 	* keeps a reference to the current element
	* Knows how to move to a different element
	*
	*/


#include<vector>
#include<iostream>
#include<string>
int main()
{
	std::vector<std::string> names {"john","jane","jill", "jack"};

	std::vector<std::string>::iterator it= names.begin();


	// iterator is like a pointer which allows derefrence and iteration
	
	std::cout<<"first name is"<< * it <<std::endl;
	++it;
	it->append(std::string("goodall")); // appending usiing an iterator.
	std::cout<<" second names is " << *it <<std::endl;

	while (++it != names.end())
	{
		std::cout<<"another name : " << *it <<std::endl;
	}

	for(auto ri = rbegin(names);ri != rend(names); ++ri)
	{
		// rebegin is the begin equivalent of reverse iterators.
		// 1 2 3 // rbegin points to the last element
		// r end points to the element before the beginning element.
	

		//++ri because it is advancing in reverse ( iterating in the backward order)

		std::cout<< *ri;
		if(ri+1 != rend(names))
		{
			std::cout<<",";
		}
		std::cout<<std::endl;
	}

	
	
	std::vector<std::string>::const_reverse_iterator jack= crbegin(names);
//this is not allowed as it is a constant iterator	*jack+= std::string("reacher");
	// this is the good way to iterate the elements
	for(auto & name: names)
	{
		std::cout<<"name =  " << name <<std::endl;
	}

	return 0;
}
	

