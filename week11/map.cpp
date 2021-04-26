#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main()
{
	map<int, int> quiz1;

	quiz1.insert(pair<int, int>(1,40));
	quiz1.insert(pair<int, int>(2,10));
	quiz1.insert(pair<int, int>(3,30));
	quiz1.insert(pair<int, int>(4,70));
	quiz1.insert(pair<int, int>(5,50));
	quiz1.insert(pair<int, int>(6,50));
	quiz1.insert(pair<int, int>(7,20));
	quiz1.insert(pair<int, int>(1,50));
	quiz1[8] = 50;
	quiz1[9] = 90;
	quiz1[8] = 20;

	map<int, int>::iterator itr;
	cout << "The map quiz1 is: " << endl;
	cout << "\tKEY\tELEMENT" << endl;
	for(itr = quiz1.begin(); itr != quiz1.end(); ++itr){
		cout << '\t' << itr->first << '\t' << itr->second << endl;
	}
	cout << endl;

	map<int, int> quiz2(quiz1.begin(), quiz1.end());

	cout << "The map quiz2 is: " << endl;
	cout << "\tKEY\tELEMENT" << endl;
	for(itr = quiz2.begin(); itr != quiz2.end(); ++itr){
		cout << '\t' << itr->first << '\t' << itr->second << endl;
	}
	cout << endl;

	cout << "quiz2 after removal of elements less than key=3 : " << endl;
	cout << "\tKEY\tELEMENT" << endl;
	quiz2.erase(quiz2.begin(), quiz2.find(3));

	for(itr = quiz2.begin(); itr != quiz2.end(); ++itr){
		cout << '\t' << itr->first << '\t' << itr->second << endl;
	}
	cout << endl;


	int num;
	num = quiz2.erase(4);
	cout << num << " removed:" << endl;

	for(itr = quiz2.begin(); itr != quiz2.end(); ++itr){
		cout << '\t' << itr->first << '\t' << itr->second << endl;
	}
	cout << endl;

	cout << quiz1.lower_bound(5)->first << '\t' << quiz1.lower_bound(5)->second << endl;
	cout << quiz1.upper_bound(5)->first << '\t' << quiz1.upper_bound(5)->second << endl;


	

	

	return 0;
}