#include<iostream>
#include<ostream>
#include<vector>
#include<string>

template<typename Self> struct SomeNeurons;
struct Neuron: SomeNeurons<Neuron>;
//struct Neuron;
// we are going to use a CRTP
// curiously recurring Template pattern

template<typename Self>
struct SomeNeurons
{
	template<typename T> void connect_to( T& other)
	{
		for (Neuron &from : *static_cast<Self*>(this))
		{
			for(Neuron & to:other)
			{
				from.out.push_back(&to);
				to.in.push_back(&from);
			}
		}
	}
};
struct Neuron : SomeNeurons<Neuron>
{
	std::vector<Neuron*> in, out;
	// for incoming and outgoing neuron;
	//
	//let's have a neuron id.
	//we want our neuron to act as a collection that returns to itself.
	//because that's the only element
	//it's a scalar element
	
	unsigned int id;

	Neuron()
	{
		static int id{1};
		this->id = id++;
	}

	Neuron * begin() {return this;}
	Neuron * end() { return this+1;}


	friend std::ostream & operator<<(std::ostream & os, const Neuron &obj)
	{
		for(Neuron * n : obj.in)
		{
			os<<n->id<< " \t--->\t " << obj.id<<std::endl;
		}

		for( Neuron * n: obj.out)
		{
			os<< "[" << obj.id<< "]\t-->\t" << n-> id << std::endl;
		}


		return os;
	}

};


//let's decide to make a neuron layer... 
//A neuron layer is basically like a collection 
// Instead of making one neuron, we make a pack of collection of neurons.
// we could keep it in something like a vector.
// typically we are not supposed to inherit from stl types as they don't have
// virtual destructors and they might run into trouble.
// but in this case we can do that.

struct NeuronLayer: std::vector<Neuron>, SomeNeurons<NeuronLayer>
{
	NeuronLayer( int count)
	{
		while(count -- >0)
			emplace_back(Neuron{});
	}

	friend std::ostream & operator <<(std::ostream & os, const NeuronLayer & obj)
	{
		for(auto &n: obj) os<<n;
		return os;
	}
	// essentially we want to connect single layer to another layer.
	//

};
int main()
{
	Neuron n1,n2;
        n1.connect_to(n2);
	std::cout<<n1<<n2<<std::endl;
	// now we might want to connect a neuron to a layer
	NeuronLayer layer1{2}, layer2{3};
	n1.connect_to(layer1);
	// now we might want to connect a layer to neuron
	layer2.connect_to(n2);
	// now we might also want to connect a layer to layer
	layer1.connect_to(layer2);
	// we want to do this using a common functionality using a single interface
	return 0;
}

