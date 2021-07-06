[1] when you program you create a concrete representation of the ideas in your solution to some problem. Let the structure of the problem
reflect those ideas as directly as possible

[a] If you can think of "it" as a seperate idea, make it a class.
[b] If you can think of "it" as a seperate entity,make it an object of some class
[c] If two classes have a common interface, make that interface an abstract class
[d] If the implementation of two classes have something significant in common, make that commonality a base class
[e] If a class is a container of objects, make it a template
[f] If a function implments an algorithm for a container, make it a template function implementing the algorithm for a family of containers
[g] If a set of classes, templates, etc, aree logically related place them in a common namespace


[2] When you define either a class that does not implement a mathematical entity like a matrix or a
complex number or a low-level type such as linked list

[a] Do not use global data(use members).
[b] Don't use global functions.
[c] don't use  public data members
[d] Don't use friends, except to avoid [a] or [c].
[e] Don't put a 'type field' in a class; use a virtual functions
[f] Don't use inline function, except as a significant optimization.
