#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<int val>
void setValue(int& elem)
{
	elem = val;
}

template <typename T>
class PrintElements
{
public:
		void operator()(T& elm) const {cout << elm << ' ';}
};

int main() 
{

		int size = 5;
		vector<int> v(size);
		PrintElements<int> print_it;

		for_each(v.begin(), v.end(), print_it);
		for_each(v.begin(), v.end(), setValue<10>);
		for_each(v.begin(), v.end(), print_it);

		return 0;		
}