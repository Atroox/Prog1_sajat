#include "std_lib_facilities.h"

//5. feladat:
void f(map<string, int>& m)
{
    string s;
    int i = 0;

    while (m.size() < 10) {
        cin >> s >> i;
        m.insert(make_pair(s, i));
    }
}

// 3. Feladat:
template<typename T, typename U>
void print(const map<T,U>& m)
{
    cout << "MAP CONTENTS:" << '\n'
              << "=============" << '\n';

    for (const auto& a : m)
        cout << a.first << '\t' << a.second << '\n';

    cout << "END" << "\n\n";
}

template <class T>
class Sum {
private:
    T& val;
public:
    Sum (T& i = 0) : val(i) {
    }

    void operator()(T x) { 
        val += x; 
    }

    T result() const { 
        return val; 
    }
};

int main()
{
//1. feladat:
	map<string,int> msi;
//2. feladat:
	msi["Béla"] = 51;
	msi["István"] = 23;
	msi["Ádám"] = 19;
	msi["Kristóf"] = 30;
	msi["Szabolcs"] = 38;
	msi["Ági"] = 20;
	msi["Fanni"] = 19;
	msi["Péter"] = 60;
	msi["Gábor"] = 48;
	msi["Kati"] = 50;

//3. feladat:
	print(msi);

//4. feladat:
    msi.erase(msi.begin(), msi.end());

    print(msi);

//6. feladat:    
    f(msi);

//7. feladat:
    print(msi);

//8. feladat:
    int i = 0;
    Sum<int> s(i);
    for_each(msi.begin(), msi.end(), s);
    cout << "Total of integers: " << s.result() << '\n';

//9. feladat:
    map<int, string> mis;

//10. feladat:
    for (const auto& a : msi)
        mis[a.second] = a.first;

//11. feladat:
    print(mis);

    return 0;
}