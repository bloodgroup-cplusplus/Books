// multition is variation of singletion
// singletion prevents you from having addition instances.
// we can optionally restrict the number of elements


#include<map>
#include<memory>

#include<iostream>

enum class Importance
{
	// ranged importance of subsystems within ranged mechanisms.
	primary,
	secondary,
	tertiary
};

//build a construct which is a singleton for each of the


template<typename T, typename Key =std::string > // define a default 

class Multition
{
	// singleton but many instances.
	
	public:
		static std::shared_ptr<T> get(const Key & key)
		{
			
			if( instances.find(key) != instances.end())
			{
				return it->second;
			}

		auto instance= std::make_shared<T> ();
		instances[key] = instance;
		return instance;

		}

	protected:
		Multition() =default;
		virtual ~Multition() =default;
		//multiton isn't meant to be instantiated it is to be used bail meechanism

	private:
		static std::map <Key, std::shared_ptr<T>> instances;

};


template<typename T, typename Key>

std::map<Key, std::shared_ptr<T>> Multition <T,Key>::instances;


class Printer
{
	public:

		Printer()
		{

	
			++Printer::totalInstanceCount;
			std::cout<<"A total of "<< 
				Printer::totalInstanceCount<<
				"instances created so far \n";
		}
	// track the number of counts printer has been initialized
	private:	
		static int totalInstanceCount;


};

int Printer::totalInstanceCount=0;


int main()
{
	// we don't instantiate multition we just create it.
	
	typedef Multition< Printer, Importance > mt;

	auto main = mt::get(Importance::primary);
	auto aux= mt::get(Importance::secondary);
	auto aux2= mt::get(Importance::tertiary);
	return 0;
}

