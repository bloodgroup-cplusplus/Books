
/*
 * software constructs taht attempt to mimic the way neuronos work in our brains
*/
#include<vector>
#include<iostream>

struct Neuron
{
	std::vector<Neuron *> in, out;
	unsigned int id;


	Neuron()
	{
		static int id=1;
		this->id=id++;
	}

};;





template<typename T, typename T1>


{
	out.push_back(&other);
	other.in.push_back(this);
}


struct NeuronLayer:std::vector<Neuron>

{
	NeuronLayer(int count)
	{
		while(count -->0)
		{
			emplace_back(Neuron{});
		}
	}
};


int main()
{
	Neuron n1,n2;
	return 0;
}

