// we are going to evaluate numeric expressions
// we are going to support addition operation
// we are going to be doing it using visiotr
//
//

#include<iostream>
#include<vector>
#include<string>

#include<sstream>
#include<ostream>



struct Expression
{
	virtual ~Expression () =default;
	virtual void print (std::ostringstream & oss) =0;

};


struct DoubleExpression : Expression
{
	double value;
	DoubleExpression (double value) :value(value) {}
	void print (std::ostringstream & oss) override
	{
		// stringstream is the visitor element of the given tree
		oss<<value;
	}
};


struct AdditionExpression : Expression
{
	// we can have 1+2 + 3
	//    +
	//   /  \
	//
	//   1   +
	//   	/ \
	//   	2  3
	
	Expression *left, *right;

	AdditionExpression (Expression *left, Expression *right): left(left), right(right){}
	~AdditionExpression()
	{
		delete left;
		delete right;
	}
	void print(std::ostringstream &oss) override
	{
		oss <<"(";
		left->print(oss);
		oss<<"+";
		right->print(oss);
		oss<<")";
	}
};


int main( int ac, char *av[])
{
	auto e= new AdditionExpression {
		new DoubleExpression{1}, 
		new AdditionExpression
		{
			new DoubleExpression {2},
			new DoubleExpression {3}
		}
	};

	// 1+2+3
	std::ostringstream oss;
	e->print(oss);
	std::cout<<oss.str()<<std::endl;
	//it's 
	delete e;

	return 0;
}
