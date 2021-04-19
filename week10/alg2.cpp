#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int arr[] = {10, 20, 20, 5, 21, 23, 42, 42, 42, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vect(arr, arr+n);

	cout << "Occurences of 20 in vector: ";
	cout << count(vect.begin(),vect.end(), 20) << endl;

	find(vect.begin(),vect.end(), 5) != vect.end() ? cout << "Element found" : cout << "Element not found";
	cout << endl;

	sort(vect.begin(),vect.end());

	auto q = lower_bound(vect.begin(),vect.end(), 20);

	auto p = upper_bound(vect.begin(),vect.end(), 20);

	cout << "The lower bound is at position: " << q-vect.begin() << endl;
	cout << "The upper bound is at position: " << p-vect.begin() << endl;

	cout << "vector is: ";
	for(int i = 0; i<n; i++)
		cout << vect[i] << " ";
	cout << endl;

	vect.erase(vect.begin()+1);

	cout << "vector is: ";
	for(int i = 0; i<n-1; i++)
		cout << vect[i] << " ";
	cout << endl;

	vect.erase(unique(vect.begin(),vect.end()), vect.end());

	cout << "vector is: ";
	for(int i = 0; i<n; i++)
		cout << vect[i] << " ";
	cout << endl;

	next_permutation(vect.begin(), vect.end());
	cout << "vector is: ";
	for(int i = 0; i<n; i++)
		cout << vect[i] << " ";
	cout << endl;

	next_permutation(vect.begin(), vect.end());
	cout << "vector is: ";
	for(int i = 0; i<n; i++)
		cout << vect[i] << " ";
	cout << endl;

	next_permutation(vect.begin(), vect.end());
	cout << "vector is: ";
	for(int i = 0; i<n; i++)
		cout << vect[i] << " ";
	cout << endl;

	next_permutation(vect.begin(), vect.end());
	cout << "vector is: ";
	for(int i = 0; i<n; i++)
		cout << vect[i] << " ";
	cout << endl;

	prev_permutation(vect.begin(), vect.end());
	cout << "vector is: ";
	for(int i = 0; i<n; i++)
		cout << vect[i] << " ";
	cout << endl;

	cout << "Dictance between first and last element: ";
	cout << distance(vect.begin(), max_element(vect.begin(), vect.end())) << endl;

	return 0;
}