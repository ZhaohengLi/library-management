#include "Functions.h"
#include <bits/stdc++.h>
using namespace std;

bool isPositiveInt(const string &s){
	for(int i=0;i<s.length();i++) if(s[i]<'0'||s[i]>'9') return false;
	if(stoi(s)==0) return false;
	return true;
}
void replace(string &s,const string &a, const string &b){
	string::size_type x=s.find(a);
	while(x!=string::npos){
		s.replace(x,1,b);
		x=s.find(a);
	}
}
string getTime(){
	time_t t;
	time(&t);
	string tm=ctime(&t);
	tm.pop_back();
	replace(tm," ","_");
	return tm;
}
