#include<iostream>
#include<cstdio>
// write html inside c++
#include<vector>
// we can approach it a domain specific  language which helps constructing domain specific
// language using valid c++ using uniform initializations
#include<utility>
#include<fstream>
#include<tuple>
#include<sstream>
#include<memory>


struct Tag
{
	std::string name,text;
	std::vector<Tag> children;
	std::vector<std::pair<std::string,std::string>> attributes;
	// how to use this tag as the base class which allows the users to write html
	//
	//let's add the output operator (overloading output operator)
	friend std::ostream & operator <<(std::ostream& os, const Tag & tag)
	{
		os<<"<"<<tag.name;
		for(const auto& att: tag.attributes)
			os<<" "<<att.first<<"=\""<<att.second<<"\"";
		if(tag.children.size()==0 && tag.text.length()==0)
		{
			os<<"/>"<<std::endl;
		}

		else
		{
			os<<">"<<std::endl;
			if (tag.text.length())
			{
				os<<tag.text<<std::endl;
			}
			for(const auto & child:tag.children) 
				os<<child;
			os<<"</"<<tag.name<<">"<<std::endl;
		}

		return os;
	}
	protected:
	// tag initilizer
	Tag(const std::string & name, const std::string & text) :name(name), text(text){}
	// tag which gets initialized by its name
	Tag(const std::string & name, const std::vector<Tag> &children):name(name),children(children){}

};

struct P: Tag
{
	// constructor which initiialzes the tag
	//
	// instead of the name here we are going to put the P tag here
	P(const std::string & text) :Tag("p",text){}
	// a paragraph can also have a children of it's own
	//let's add that
	//the way we can do this is we can initialize paragrph with 	    //
	
	P(std::initializer_list<Tag> children):Tag{"p",children}{}
};

struct IMG :Tag
{
	//specifies the url of image you want to show
	explicit IMG (const std::string & url):Tag{"img",""}
	{
		// what we put it here is
		attributes.emplace_back(std::make_pair("src",url));
	}
	//why did we do all of this cause we've build the domain speicific language
};
// image cannot contain another tag
// smaller side to builder
// we are using or abusing uniform to define structure in more natural way
//

int main()
{
	std::cout<<
		P
		{
			IMG {
				"http://pokemon.com/pikachu.png"}
		}

	<<std::endl;

	return 0;
}


