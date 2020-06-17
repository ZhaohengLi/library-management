#ifndef CONSOLE_H
#define CONSOLE_H

#include <bits/stdc++.h>
using namespace std;

class Console{
public:
	template <typename A> void inf(const string &s,A &a);
	template <typename A> void outf(const string &s,const A &a);
	void mkdir(const string &s);
	void rmdir(const string &s);
	string bdir(const string &s);
	string rdir(const string &s);
	string hdir(const string &s);
};
template <typename A> void Console::inf(const string &s,A &a){
    ifstream in;
	in.open(s);
	in>> a;
	in.close();
}
template <typename A> void Console::outf(const string &s,const A &a){
	ofstream out;
	out.open(s);
	out<< a << endl;
	out.close();
}

#endif
