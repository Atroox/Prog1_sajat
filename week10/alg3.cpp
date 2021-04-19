#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main()
{
	int ar[6] = {1, 2, 3, 4, 5, -6};

	all_of(ar, ar+6, [](int x) { return x>0; }) ? cout << "All elements are positive" : cout << "Not all elements are positive";
	cout << endl;

	any_of(ar, ar+6, [](int x) { return x>0; }) ? cout << "There are positive elements" : cout << "All elements aren't positive";
	cout << endl;

	none_of(ar, ar+6, [](int x) { return x>0; }) ? cout << "There are no positive elements" : cout << "There are positive elements";
	cout << endl;

	int ar1[6];
	copy_n(ar, 6, ar1);

	cout << "The new array after copying is: ";
	for(int i = 0; i<6; i++)
		cout << ar1[i] << " ";
	cout << endl;

	int ar2[6] = {0};

	iota(ar2, ar2+6, 20);

	for(int i = 0; i<6; i++)
		cout << ar2[i] << " ";
	cout << endl;

 
	return 0;
}