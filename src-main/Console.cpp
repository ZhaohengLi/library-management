#include "Console.h"
#include <bits/stdc++.h>
using namespace std;

//Console.cpp
void Console::mkdir(const string &s){
	string cmd="mkdir "+s;
	system(cmd.c_str());
}
void Console::rmdir(const string &s){
	string cmd="rm -r "+s;
	system(cmd.c_str());
}
string Console::bdir(const string &s){
	string a="data/book/"+s;
	return a+"/";
}
string Console::rdir(const string &s){
	string a="data/reader/"+s;
	return a+"/";
}
string Console::hdir(const string &s){
	string a="data/history/"+s;
	return a+"/";
}
