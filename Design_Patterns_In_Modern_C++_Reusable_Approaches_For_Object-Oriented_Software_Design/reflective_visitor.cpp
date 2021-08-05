// we decide to split to the single responsiblity principle for printing the expression
//

#include<iostream>
#include<sstream>
#include<ostream>
#include<memory>

struct Expression
{
	virtual ~Expression () = default;

};

struct DoubleExpression : Expression
{
	double value;
	DoubleExpression ( double value) :value(value) {}



};


struct AdditionExpression : Expression
{
	Expression *left, *right;

	AdditionExpression (Expression *left, Expression *right ) :left(left),right(right){}
	~AdditionExpression()
	{
		delete left;
		delete right;
	}



};

struct ExpressionPrinter
{
	/*void print(DoubleExpression *de, std::ostringstream & oss) const
	{
		oss<<de->value;
	}

	// however we will be unable to write print for addition expression
	
	void print( AdditionExpression * ae, std::ostringstream & oss) const
	{
		oss << "(";
		print(ae->left, oss);
		// this is not going to work
		// we do not have overload of print which takes the expression.
		// dispatch happens in compile time.
		// it's not going to work in c++
		// we are going to write generaal print expression.
	*/

	//let's write a general  print implementation 
	
	std::ostringstream oss;
	void print( Expression *e)
	{
		if (auto de = dynamic_cast<DoubleExpression *> (e)) // if it is double expression )
		{
			oss<<de->value;
		}

		else if (auto ae= dynamic_cast<AdditionExpression *> (e))
		{
			oss<<"(";
			print(ae->left);
			oss<<"+";
			print(ae->right);
			oss<<")";
		}

	}
	std::string str() const {return oss.str();}

	
};

int main( int ac, char *av[])
{
	auto e= new AdditionExpression
	{
		new DoubleExpression {1},
		new AdditionExpression 
		{
			new DoubleExpression {2},
			new DoubleExpression {3}
		}
	};

//	std::ostringstream oss;
//	e->print(oss);
//	std::cout<<oss.str()<<std::endl;
	ExpressionPrinter ep;
	std::cout<<ep.str()<<std::endl;

	delete e;
	return 0;
}

