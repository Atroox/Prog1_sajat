#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void showlist(list<int> g)
{
	list<int> :: iterator it;
	for(it = g.begin(); it!= g.end(); ++it)
		cout << " " << *it;
	cout << endl;
}

int main()
{
	list<int> qqlist1, qqlist2;
	for(int i = 0; i<10; ++i)
	{
		qqlist1.push_back(i*2);
		qqlist2.push_front(i*3);
	}
	cout << "List 1 is: ";
	showlist(qqlist1);

	cout << "List 2 is: ";
	showlist(qqlist2);

	cout << "\nqqlist1.front() :" << qqlist1.front();
	cout << "\nqqlist1.back() :" << qqlist1.back();

	cout << "\nqqlist1.pop_front() :";
	qqlist1.pop_front();
	showlist(qqlist1);

	cout << "\nqqlist1.pop_back() :";
	qqlist1.pop_back();
	showlist(qqlist1);

	cout << "\nqqlist1.reverse() :";
	qqlist1.reverse();
	showlist(qqlist1);

	cout << "\nqqlist2.sort() :";
	qqlist2.sort();
	showlist(qqlist2);
}