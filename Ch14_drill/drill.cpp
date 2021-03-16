#include <iostream>
#include <string>

using std::cout;
using std::string;

struct B1 {

	virtual void vf() {cout << "B1::vf()" <<std::endl;}
	void f() {cout << "B1::f()" <<std::endl;}
	virtual void pvf() =0;
};

struct D1:B1 {

	void vf() {cout << "D1::vf()" <<std::endl;}
	void f() {cout << "D1::f()" <<std::endl;}
};

struct D2:D1 {

	void pvf() override {cout << "D2::pvf()" <<std::endl;}
};

struct B2 {

	virtual void  pvf() =0;
};

struct D21:B2 {

	string s = "something" ;

	void pvf() {cout << s <<std::endl;}
};

struct D22:B2 {

	int i = 19;

	void pvf() {cout << i <<std::endl;}
};

void f (B2& b)
{
	b.pvf();
}


int main() 
{
	/*
	B1 b;

	b.vf();
	b.f();

	D1 d;

	d.vf();
	d.f();

	B1& r {d};

	r.vf();
	r.f();
	

	D2 dd;

	dd.f();
	dd.vf();
	dd.pvf();
	*/

	D21 one;
	D22 two;

	f(one);
	f(two);

}