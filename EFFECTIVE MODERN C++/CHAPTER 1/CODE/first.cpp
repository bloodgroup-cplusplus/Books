#include<iostream>
template<typename T>
void f( const T & param)
{
    std::cout<<param<<std::endl;
}


int main()
{
  int x=0;
  f(x);
  return 0;
}

//Param type is const T & 
//T is deduced to be int, but ParamType is deduced to be const int&.
// param type often contains adorments e.g., const or refrence qualifiers.
/*It’s natural to expect that the type deduced for T is the same as the type of the argu‐
ment passed to the function, i.e., that T is the type of expr. In the above example,
that’s the case: x is an int, and T is deduced to be int. But it doesn’t always work that
way. The type deduced for T is dependent not just on the type of expr, but also on the
form of ParamType/

