// where is builder used
// let's suppose we are working on backend web
// it serves some html over the wire
// let's return a string
//

#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include<tuple>
#include<sstream>
#include<memory>

// this approach of taking a string and adding elelments to string it doesn't scale
// we have a bunch of word and we have a word hello world.
// we probably wouldn't go for string concatinator
// this is illustrated in the main
//

int main()
{
	auto text="hello";
	std::string output;
	output+= "<p>";
	output+= text;
	output+= "</p>";
	std::cout<<output<<std::endl;
	std::string words[]= {"hello","world"};
	std::ostringstream oss;
	oss<<"<ul>";
	for(auto w:words)
		oss<< "  <li>" << w<< "</li>";
	oss<<"</ul>";

	std::cout<<oss.str()<<std::endl;
	return 0;
}
// since html has list paragarahhs and not of the above is shown here
// the idea of builder pattern is instead of building out string out of small concatinations we just define some object oriented structure we create a builder 
