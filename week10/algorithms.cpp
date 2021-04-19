#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int arr[] = {10, 20, 5, 21, 23, 42, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vect(arr, arr+n);

	cout << "vector is: ";
	for(int i = 0; i<n; i++)
		cout << vect[i] << " ";
	cout << endl;

	sort(vect.begin(),vect.end());

	cout << "vector is: ";
	for(int i = 0; i<n; i++)
		cout << vect[i] << " ";
	cout << endl;

	reverse(vect.begin(),vect.end());

	cout << "vector is: ";
	for(int i = 0; i<n; i++)
		cout << vect[i] << " ";
	cout << endl;

	cout << "Maximum element of vector is: " << endl;
	cout << *max_element(vect.begin(),vect.end());

	cout << "Minimum element of vector is: " << endl;
	cout << *min_element(vect.begin(),vect.end());

	cout << "The sumtation of vector is: " << endl;
	cout << accumulate(vect.begin(),vect.end(), 0);

	return 0;
}