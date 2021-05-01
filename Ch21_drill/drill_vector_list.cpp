#include "std_lib_facilities.h"

//1. feladat
struct Item {
	string name;
	int iid;
	double value;
};

ostream& operator<<(ostream& os, const Item& it)
{
	return os << it.name << '\t'
	<< it.iid << '\t'
	<< it.value << '\t'; 

}

istream& operator>>(istream& is, Item& it)
{
	string ss;
	int ii;
	double dd;
	is >> ss >> ii >> dd;
	Item itt {ss, ii, dd};
	it = itt;
	return is;

}
//4. feladat:
struct Cmp_by_dec_val
{
	bool operator()(const Item& a, const Item& b)
	{
		return a.value > b.value;
	}
};
//5. feladat:
class Insert_in_order {
	double val;
public:
	Insert_in_order(double vv) : val{vv} { }
	bool operator()(const Item& x) const { return x.value < val; }
};
//6. feladat:
class Cmp_by_name
{
	string name;
public:
	Cmp_by_name(const string& nn) : name{nn} {}
	bool operator()(const Item& x) const { return x.name == name; }
};
//7. feladat:
class Cmp_by_iid
{
	int iid;
public:
	Cmp_by_iid(const int& ii) : iid{ii} {}
	bool operator()(const Item& x) const { return x.iid == iid; }
};

template<typename C>
void print(const C& c, char sep = ' ')
{
	for (const auto& a : c)
		cout << a << sep;
	cout << '\n';
}

int main()
{
//1. feladat:
	const string input {"input.txt"};

	ifstream ifs {input};
	if (!ifs) throw runtime_error("Could not read from file: " + input);

	vector<Item> vi;
	for(Item ii; ifs >> ii; )
		vi.push_back(ii);

	for(int i = 0; i<vi.size(); ++i)
		cout << vi[i] << endl;
//2. feladat:
	sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b) { return a.name < b.name; });

	cout << "\nVi sorted by name: \n" << endl;
	for(int i = 0; i<vi.size(); ++i)
		cout << vi[i] << endl;
//3. feladat:
	sort(vi.begin(), vi.end(),
		[](const Item& a, const Item& b) { return a.iid < b.iid; });

	cout << "\nVi sorted by id: \n" << endl;
	for(int i = 0; i<vi.size(); ++i)
		cout << vi[i] << endl;
//4. feladat:
	sort(vi.begin(), vi.end(),Cmp_by_dec_val());

	cout << "\nVi sorted by value: \n" << endl;
	for(int i = 0; i<vi.size(); ++i)
		cout << vi[i] << endl;
//5. feladat:
	Item Hs = {"horse shoe", 99, 12.34};
	vi.insert(
		find_if(vi.begin(), vi.end(), Insert_in_order(Hs.value)),
		Hs);

	Item Canon = {"Canon S4000", 9988, 499.95};
	vi.insert(
		find_if(vi.begin(), vi.end(), Insert_in_order(Canon.value)),
		Canon);

	cout << "\nVi after insert: \n" << endl;
	for(int i = 0; i<vi.size(); ++i)
		cout << vi[i] << endl;

//6. feladat:
	vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_name("Kenyér")));
	vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_name("Nadrág")));

	cout << "\nVi after erase by name: \n" << endl;
	for(int i = 0; i<vi.size(); ++i)
		cout << vi[i] << endl;

//7. feladat:
	vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_iid(14)));
	vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_iid(12)));

	cout << "\nVi after erase by iid: \n" << endl;
	for(int i = 0; i<vi.size(); ++i)
		cout << vi[i] << endl;
	cout << '\n';

//8. feladat:
	list<Item> li (vi.size());
	copy(vi.begin(), vi.end(), li.begin());

	print(li, '\n');

	li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
	li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
	li.sort([](const Item& a, const Item& b) { return a.value > b.value; });

	Hs = {"horse", 99, 1.34};
	li.insert(find_if(li.begin(), li.end(), Insert_in_order(Hs.value)),
		Hs);

	Canon = {"Canon", 9988, 499.95};
	li.insert(find_if(li.begin(), li.end(), Insert_in_order(Canon.value)),
		Canon);

	li.erase(find_if(li.begin(), li.end(), Cmp_by_name("Asztal")));
	li.erase(find_if(li.begin(), li.end(), Cmp_by_name("Víz")));

	li.erase(find_if(li.begin(), li.end(), Cmp_by_iid(92)));
	li.erase(find_if(li.begin(), li.end(), Cmp_by_iid(75)));

	print(li, '\n');

	return 0;
}