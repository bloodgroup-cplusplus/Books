/* why we discussing state design pattern
 * state of a system controls the way it operates.
 * MOTIVATION
 *	Consider an ordinary telephone
 *	What tou do with it depends on the state of the phone/line
 *		If it's ringing or you want to make a call, you can pick it up
 *		Phone must be off the hook to talk/make a call
 *		If you try calling someone, and it's busy you put the handset down.
 *Changes in state can be explicit or in response to event( observer pattern)
 * Some state machines will have explicit control. i.e., we query the user about what we want to do and thereby they transition from one state to another.
 * 
 *
 * STATE: A pattern in which the object's behavior is determined by its state. An object transitions from one state to another (soemthing needs to trigger a transition).
 * A formalized construct which manages state and transitions is called a state machine.
 * transitions are triggered by some event.
 * Formalized construct is called a state machine.
 */

#include<iostream>
#include<sstream>
#include<string>
//switching the light on and off


struct State
{
	virtual void on (LightSwitch * ls)
	{
	
		std::cout<<"Light is already on \n";
	}


	virtual void off( LightSwitch *ls)
	{

		std::cout<<"Light is already off\n";

	}
	// if you are in ON state override the OFF function and if you are in OFF state override ON funtion.

};



struct OnState: State
{
	OnState()
	{
		std::cout<"Light is turned on \n";
	}

	void off ( LightSwitch *lhs) override;
};


struct OffState: State
{

	OffState()
	{
		std::cout<<"Light is turned off\n";
	}
	void on (LightSwitch * lhs) override;
};

class LightSwitch
{
	State *state;
	public:
		LightSwitch()
		{
			state= new OffState();
		}

		void set_state( State *state)
		{
			this->state=state;
		}

		void on() {
			state->on(this);

		}
		void off() {
			state->off(this);
		}
};

void OnState::off(LightSwitch *ls)
{
	std::cout<<"Switching light off ...\n"
	ls->set_state(new OffState());
	delete this; // red flag
}


void OffState::on(LightSwitch *ls)
{

	std::cout<<"Switching light on ...\n";
	ls->set_state(new OnState());
	delete this;
}


int main(int ac, char *av[])
{
	LightSwtich ls;
	ls.on();
	ls.off();
	ls.off();

	return 0;
}

