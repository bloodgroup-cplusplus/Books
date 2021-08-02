// mANY ALGORITHMS  can be decomposed into higher- and lower level parts
// Making tea can be decomposed into
// 	The process of making a hot beverage ( boil water, pour into cup) ; and
// 	Tea-specific things ( put teabag into water)
// 	The high-level algorithm can then be reused for making coffee or hot chocolate.
// 		Supported by beverage-specific strategies.
//
//
// Strategy : Enables the exact behaviour of a system to be selected either at run-time( dynamic)
//or compile-time(static)
//
//
//Also known as policy in C++ language
//

#include <iostream>
#include<vector>
#include<ostream>
#include<sstream>
#include<memory>
#include<string>
#include<vector>
enum class OutputFormat
{
	markdown,
	html
};

struct ListStrategy
{
	virtual void start(std::ostringstream & oss) {}
	virtual void add_list_item( std::ostringstream & oss, const std::string & item) =0;
	virtual void end(std::ostringstream & oss) {}
};

struct MarkdownListStrategy:ListStrategy
{
	void add_list_item( std::ostringstream & oss, const std::string & item) override
	{
		oss<< "* " << item <<"\n";


	}

};


struct HtmlListsStrategy: ListStrategy
{
	void start( std::ostringstream & oss) override
	{
		oss<< "<ul>\n";
	}


	void add_list_item(std::ostringstream & oss, const std::string & item ) override
	{
		oss << "  <li> " << item << "</li> " << std::endl;
	}

};




struct TextProcessor
{
	void clear()
	{
		oss.str("");
		oss.clear();
	}
	void append_list( const std::vector<std::string> & items)
	{
		list_strategy->start(oss);
		for(auto & item:items)
		{
			list_strategy->add_list_item(oss,item);
		}
	}
	void set_output_format( const OutputFormat & format)
	{
		switch( format)
		{
			case OutputFormat::markdown;
			list_strategy= std::make_unique<MarkdownListStrategy>();
			break;

			case OutputFormat::html;
			list_strategy= std::make_unique<HtmlListStrategy>();
			break;
		}
	}
	void append_list( const std::vector<std::string> & items)
	{
		list_strategy->st
	}
	std::string str() const {return oss.str();}
	private:
		std::ostringstream oss;
		std::unique_ptr<ListStrategy> list_strategy;
		

};


// * hdajks
// * hdjask
// <ul>
// <li> dasjkdh </li>
//</ul>
//
//
int main(int ac, char * av[])
{
	std::vector<std::string> items { "foo","bar","baz"};
	TextProcessor tp;
	tp.set_output_format( OutputFormat::markdown);
	tp.append_list(items);
	std::cout<<tp.str()<<std::endl;
	return 0;
}


