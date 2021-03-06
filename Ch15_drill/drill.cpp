#include "std_lib_facilities.h"

struct Person {
    Person() { }
    Person(string fn, string ln, int aa);

    string first_name() const { return first; }
    string last_name() const { return last; }
    int age() const { return a; }

private:
    string first;
    string last;
    int a;
};

Person::Person(string fn, string ln, int aa)
    : first{fn}, last{ln}, a{aa}
{
    if (aa < 0 || 150 < aa) error("Person(): invalid age");
    
    string nn = fn + ln;
    for (char c : nn) {
        switch(c) {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
                error("Person(): bad char in names");
                break;
            default:
                break;
        }
    }
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << p.first_name() << ' '
              << p.last_name() << '\t'
              << p.age();
}

istream& operator>>(istream& is, Person& p)
{
    string f;
    string l;
    int a;

    is >> f >> l >> a;
    if (!is) error("Unable to read into Person");

    p = Person(f, l, a);

    return is;
}

int main()
{

    vector<Person> vp;

    cout << "Enter some names and ages. Terminate with name 'end'\n";

    for (Person p; cin >> p; ) {
        if (p.first_name() == "end") break;
        vp.push_back(p);
    }

    for (Person p : vp)
        cout << p << '\n';
}