#include "std_lib_facilities.h"

template<class T>
class Base 
{
public:
	Base(){};
	virtual void print() =0;
};

template<typename T>
class List
{
	T val;

public:
	void print(list <T> g)
	{
		List<T> :: iterator it;
		for(it = g.begin(); it != g.end(); ++it)
			cout << '\t' << *it;
		cout << '\n';
	}

	List(const List &li) []{ return x = li; };
};

int main()
{

	return 0;
}