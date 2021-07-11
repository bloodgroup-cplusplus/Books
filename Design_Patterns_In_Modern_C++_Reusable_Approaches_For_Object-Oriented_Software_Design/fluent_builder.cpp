#include<iostream>
#include<vector>
#include<cstdio>
#include<sstream>
#include<memory>
#include<string>


struct HtmlElement
{
	std::string name, text;
	std::vector<HtmlElement> elements;
	const size_t indent_size=4;
	HtmlElement() {}
	HtmlElement (const std::string &name, const std::string text):name(name), text(text){}
	std::string str(int indent=0) const
	{
		std::ostringstream oss;
		std::string i (indent_size * indent, ' ');
		oss << i<< "<"<< name << ">" <<std::endl;
		if(text.size())
		{
			oss<<std::string(indent_size*(indent+1), ' ')<< text<<std::endl;
		}

		for(const auto & e:elements)
		{
			oss<<e.str(indent+1);
		}
		oss<< i<<" </ " <<name << ">" <<std::endl;
		return oss.str();
	}
	static HtmlBuilder build (std::string root_name)
	{
		return {root_name}; // constructed to the name
		// if you also want the start of the invocation call the main function
		// HtmlElement elem = HtmlElement::build("ul")->add_child("","")->add_child("","");
		// if you want this to change to HtmlElement->build("ul")->add_child("","")->add_child("","");
		// then you could change the above function into a unique pointer instead of a function call
		// 		
	}
	// we could return a static unique ptr of html builder where you could simply return make unique
//	static std::unique_ptr<HtmlBuilder> build (std::string root_name)
//	{
		//return std::make_unique<root_name>;
//	}

};

struct HtmlBuilder
{
	HtmlElement root;
	HtmlBuilder (std::string root_name)
	{
		root.name=root_name;
	}
	HtmlBuilder & add_child( std::string child_name, std::string child_text)
	{
		HtmlElement e{child_name,child_text};
		root.elements.emplace_back(e);
		// we can return a refrence to html builder itself by returning star *this
		// and this way what happens is after the first add child call the end result is 
		// html builder
		return *this;
	}
	std::string str() const {return root.str();}
	operator HtmlElement const {return root;}
	// now instead you know that certain operation is the last operation and you need to move the root out
	// then what you can do is move the root out using the move operator
	// operator HtmlElement() const
	// {
	// 	return std::move(root);
	// }
	// in this case it doesn't matter
	// this makes sense if we are building the factor
	// we are returing the copy of operator 
	// we can also ensure that the entire operations works on pointer instead of working on references
	// for doing that what we can do is.we can crate another add child but this time it is only going to 
	// work in case of pointers
	
	HtmlBuilder * add_child_2( std::string child_name,std::string child_text)
	{
		HtmlElement e{child_name,child_text};
		root.elements.emplace_back(e);
		return this;
	
	}
	// now the entire things are made up of pointers
	// so when we would be calling it from the main function we could simply do this
	// HtmlElement elem =HtmlElement::build("ul")->add_child("","");
	// and certainly if you want the start 
	
};


int main()
{
	auto text= "hello";
	std::string output;
	output+= "<p>";
	output+= text;
	output+= "</p>";
	std::cout<<output<<std::endl;
	std::string words[] ={"hello","world"};
	std::ostringstream oss;
	oss<<"<ul>";
	for(auto w: words)
	{
		oss<<" <li> " << w<< "</li>";
	}
	oss<< "</ul>";
	std::cout<<oss.str()<<std::endl;
	HtmlBuilder builder {"ul"};
	// now since we see there are two add child call one after another but what if we could do it this way
	// this is actually quite commmon in design pattern builder and this is called the fluent interface.
	// to make a fluent interface
	// change the return type from void to the type you are currently in 
	builder.add_child("li","hello").add_child("li","world");
//	builder.add_child("li","world");
//	this is convinient in builders and specify how the change of build commands can be constructed using
//	fluent interface
//	you can give hint to a client that's using api they should really be using teh builder so to do this
//	we can give a static function inside the html element we are building up
//	we can make a static function called build which will take the root name.
//	once we make the static function inside the builder class we can use  it to build
	HtmlElement elem= HtmlElement::build("ul").add_child("", "");
	// this is a valid way for putting various things to single basket
	// instead of making a builder let's suppose you want to get an html element here
	// let's suppose we have html elemnt call elem
	// right hand side builds the html builder 
	// cause we've called HtmlElemnt::build("ul").add_child("","");
	// to convert one to another we
	std::cout<<builder.str()<<std::endl;
	return 0;
}

