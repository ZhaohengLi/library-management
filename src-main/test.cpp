#include <bits/stdc++.h>
#include "Console.h"
using namespace std;

class B{
	int x;
public:
	B(int _x):x(_x){}
	B(){}
	bool operator < (const B &b) const { return x<b.x; }
};
class A{
public:
	template <class T> bool min(T a, T b);
};
template <class T>
bool A::min(T a,T b){
	return a<b;
}
int main(){
	A a;
	B x(9),y(10);
	cout<< a.min(x,y);
	int n=5;
	Console con;
	string s="test.txt";
	con.outf(s,n);
	return 0;
}
