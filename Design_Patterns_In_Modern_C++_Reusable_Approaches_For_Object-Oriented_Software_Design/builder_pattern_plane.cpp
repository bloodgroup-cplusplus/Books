//Question :Why builder Design pattern
//Answer : Because we want to buld and object (plane) and it is composed of complex objects( body,engine) step by step
//
//

#include<iostream>
using namespace std;

class Plane
{
	std::string _plane;
	std::string _body;
	std::string _engine;

	public:
		Plane(std::string planeType): _plane{planeType}{}
		void setEngine(std::string type) 
		{
			_engine=type;
		}

		void setBody(std::string body)
		{
			_body=body;
		}


		std::string getEngine()
		{
			return _engine;
		}
		std::string getBody()
		{
			return _body;
		}


	void show()
	{
		std::cout<<"Plane type:"<<_plane<<std::endl;
		std::cout<<"Body type:"<<_body<<std::endl;
		std::cout<<"Engine type"<<_engine<<std::endl;
	}



};

class PlaneBuilder
{
	protected:
		Plane * _plane;
	public:
		virtual void getPartsDone()=0;
		virtual void buildBody()=0;
		virtual void buildEngine()=0;
		Plane * getPlane() {return _plane;}

};



class PropellerBuilder:public PlaneBuilder
{
	public:
		void getPartsDone() {_plane= new Plane("Propeller Plane");}
		void buildEngine() {_plane->setEngine("Propeller Engine");}
		void buildBody() {_plane->setBody("Propeller Body");}

};

//Plane Builder Concrete Class
//Knows only how to build Jet Plane

class JetBuilder:public PlaneBuilder
{
	void getPartsDone() {_plane= new Plane("Jet Plane");}
	void buildEngine () {_plane->setEngine("Jet Engine");}
	void buildBody() {_plane->setBody("Jet Body");}
};

//Defines steps and tells to the builder that build in given order
class Director
{
	public:
		Plane * createPlane(PlaneBuilder *builder)
		{
			builder->getPartsDone();
			builder->buildBody();
			builder->buildEngine();
			return builder->getPlane();
		}
};

int main()
{
	Director dir;
	JetBuilder jb;
	PropellerBuilder pb;
	Plane *jet= dir.createPlane(&jb);
	Plane *pro= dir.createPlane(&pb);
	jet->show();
	pro->show();
	delete jet;
	delete pro;
	return 0;
}

