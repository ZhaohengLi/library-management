#include "Menu.h"
#include "Library.h"
#include "Functions.h"
#include <bits/stdc++.h>
#define MS Menu::SubMenu
using namespace std;

//Menu.cpp
//SubMenu:
void MS::showBook() const {
	system("clear");
	op->showBook();
	cout<< "输入任意字符返回上级菜单" << endl;
	string k; getline(cin,k);
	return;
}
void MS::showReader() const {
	system("clear");
	op->showReader();
	cout<< "输入任意字符返回上级菜单" << endl;
	string k; getline(cin,k);
	return;
}
void MS::schBook() const {
	while(true){
		system("clear");
		cout<< "请输入搜索书籍的关键字" << endl;
		string s; getline(cin,s);
		op->schBook(s);
		cout<< "1.继续搜索" << endl
			<< "2.返回上级菜单" << endl
			<< "3.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=3) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") continue;
		else if(k=="2") return;
		else exit(0);
	}
}
//Menu::
void Menu::start() const {
	while(true){
		system("clear");
		cout<< "图书管理系统" << endl
			<< "1.读者入口" << endl
			<< "2.管理员入口" << endl
			<< "3.退出" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=3) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") rm.login();
		else if(k=="2") mm.login();
		else exit(0);
	}
}

