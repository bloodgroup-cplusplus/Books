#include<iostream>
#include<vector>
#include<string>
#include<ostream>
#include<sstream>


//let's build a pointer chain or singly link list full of pointers
//let's imagine we have a computer game
//and it has creature roming around



struct Creature
{
	std::string name;
	int attack, defense;

	Creature(const std::string & name, int attack, int defense) :name(name), attack(attack), defense(defense){}
	friend std::ostream & operator <<(std::ostream & os, const Creature & creature)
	{
		os << "name : " <<creature.name << " attack : " <<creature.attack << " defense  " << creature.defense;
		return os;
	}


};


//let's say creatuer picks up magic sword and creature has boost to it's abiliites
//in the classic implementtaion of chain of responsibilites it will have a chain of modifiers
//we can have several modifiers

class CreatureModifier
{
	// this would be a singly linked list which is a class having pointer to the class itself.
	// the whole point is to inherit and say what kind of  modifications you want to do on the 
	// creature.
	
	CreatureModifier * next {nullptr};
	//we will have refrence to creature
	protected:
		Creature & creature;
	public:
		CreatureModifier( Creature & creature) : creature(creature) {}
	// add allows to enlist new modifier in the chain
	
	void add( CreatureModifier * cm)
	{
		if(next) next-> add(cm);
		else next= cm;
	}

	virtual void handle()
	{
		// default behaviour is to preserve the chain
		if (next) next->handle();
	}

};

// take creature and double it's attack value
class DoubleAttackModifier: public CreatureModifier
{
	public:
		DoubleAttackModifier( Creature & creature) : CreatureModifier(creature) {}
	void handle() override
	{
		creature.attack*=2;
		CreatureModifier::handle();
		//checks next pointer and goes to next
	}
};



class IncreaseDefenseModifier: public CreatureModifier
{
	public:
		IncreaseDefenseModifier(Creature & creature): CreatureModifier(creature) {}
	void handle() override
	{
		if(creature.attack<=2)
			creature.defense++;
		CreatureModifier::handle();
	}
};
class NoBonusesModifier: public CreatureModifier
{
	// a class which overrides or delete the effect of any  any additional modifiers 
	// basically it nullifies the presence of modifiers.
	// if we add nobuses modifier  to prevent the walking of chain of responsibility
	public:
		
		NoBonusesModifier(Creature & creature) : CreatureModifier(creature) {}

		void handle () override
		{
		}
};
int main()
{


	Creature goblin {"Goblin" , 1, 1};
	CreatureModifier root { goblin};
	//let's say we want a doulbe attack modifier 
	// we can do it to add r1 and r2
	DoubleAttackModifier r1 {goblin};
	DoubleAttackModifier r1_2{goblin};
	IncreaseDefenseModifier r2{goblin};
	NoBonusesModifier curse {goblin};
	root.add(&curse);
	root.add(&r1);
	root.add(&r1_2);
	root.add(&r2);
	root.handle();
	std::cout<<goblin<<std::endl;
	return 0;
}

