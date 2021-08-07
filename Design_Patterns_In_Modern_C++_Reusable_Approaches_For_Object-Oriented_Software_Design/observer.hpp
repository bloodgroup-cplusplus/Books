# pragma once

template<typename T>
class Observer
{
	virtual void field_changed(
	
		// we will get infromation about whose field is changed.

		T & source;
		const std::string & field_name

		)=0;

};

