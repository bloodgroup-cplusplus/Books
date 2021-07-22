#include<string>
#include<iostream>
#include<vector>


struct GraphicObject
{
	virtual void draw() =0;

};


// we can have concrete shapes
//
//
struct Circle : GraphicObject
{
	void draw() override
	{
		std::cout<<"this is a circle"<<std::endl;
	}



};

//let's group a circle into one circle
//


struct Group: GraphicObject
{
	std::string name;
	std::vector<GraphicObject *> objects;
	Group( const std::string & name) :name(name){}
	void draw() override
	{
		std::cout<<"Group"<<name.c_str() <<"contains" <<std::endl;
		for(auto && o :objects)
			o->draw();
	}

};

int main()
{
	Group root("root");
	Circle c1, c2;
	root.objects.push_back(&c1);
	Group subgroup( "sub");
	subgroup.objects.push_back(&c2);
	root.objects.push_back(&subgroup);
	root.draw();
	return 0;
}
