/*
 * Adding behavior without altering 
 * Motivation
 * 	We want to augment an object with additional functionality
 * 	Don want to rewrite or alter existing code (OCP)
 * 	Want to keep new functionality seperate (SRp)
 * 	Need to able to interact with existing structures
 * 	Two options:
 * 		Agregate the decorated object ( dynamic decorator)
 * 		Inherit form the decorated object( mixing inhertence)
 * Decorator- pattern that facilitates the addition of behaviours to individual objects.
 *
 *
 */


#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<ostream>

#include<sstream>
//let's have a base class called as shape.

struct Shape
{
	// single pure virtual member
	virtual std::string str() const=0;
};



struct Circle :Shape
{
	float radius;
	Circle (float radius): radius(radius){}
	Circle () {}

	void resize(float factor)
	{
		radius *= factor;
	}

	std::string str() const override
	{
		std::ostringstream oss;
		oss<<"A circle of radius"<<radius;
		return oss.str();
	}
	
};


struct Square: Shape
{
	float side;
	Square(float side) :side(side){}
	Square(){};

	std::string str() const override
	{
		std::	ostringstream oss;
		oss<<"A square with side" <<side;
		return oss.str();
	}
};

// now we have a hierarchy of two different shapes and what we want to do is to enhance this hierarchy
// now what we want to do is to add color to it.
// now we are certainly not going to create two other classes.
// we are not going to create colored circle and colored square
// instead we are going to create a new struct called colored shape
// 
struct ColoredShape: Shape
{
	//take refrence to shape we are decorating
	Shape & shape;
	std::string color;
	ColoredShape(Shape & shape, const std::string & color) :shape(shape), color(color){}
	std::string str() const override
	{
		std::ostringstream oss;
		oss<<shape.str() <<"  "<<"Has the color  "<<color;
		return oss.str();
	}
};



int main()
{
	Square square{5};
	ColoredShape red_square{square, "red"};
	//print square and the red square
	std::cout<<red_square.str()<<std::endl;
	return 0;
}

