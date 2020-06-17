#include "Menu.h"
#include "Library.h"
#include "Functions.h"
#include <bits/stdc++.h>
#define MM Menu::ManagerMenu
using namespace std;

//Menu_manager.cpp
void MM::login() const {
	while(true){
		system("clear");
		string mpasswd;
		while(true){
			cout<< "请输入管理员密码(输入-1返回上级菜单)" << endl;
			getline(cin,mpasswd);
			if(mpasswd=="-1") return;
			if(mop->mpasswdRight(mpasswd)) break;
			else cout << "密码错误" << endl;
		}
		start();
	}
}
void MM::start() const {
	while(true){
		system("clear");
		cout<< "1.添加书籍" << endl
			<< "2.删除书籍" << endl
			<< "3.添加读者" << endl
			<< "4.删除读者" << endl
			<< "5.处理借还书申请" << endl
			<< "6.显示所有书籍" << endl
			<< "7.显示所有读者" << endl
			<< "8.搜索书籍" << endl
			<< "9.搜索读者" << endl
			<< "10.搜索历史记录" << endl
			<< "11.修改密码" << endl
			<< "12.返回上级菜单" << endl
			<< "13.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=13) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") addBook();
		else if(k=="2") delBook();
		else if(k=="3") addReader();
		else if(k=="4") delReader();
		else if(k=="5") dealRequest();
		else if(k=="6") showBook();
		else if(k=="7") showReader();
		else if(k=="8") schBook();
		else if(k=="9") schReader();
		else if(k=="10") schHistory();
		else if(k=="11") changeMpasswd();
		else if(k=="12") return;
		else exit(0);
	}
}
void MM::addBook() const {
	while(true){
		system("clear");
		cout<< "1.添加已有书籍" << endl;
		cout<< "2.添加新书" << endl;
		cout<< "3.返回上一级" << endl;
		cout<< "4.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=4) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") addOldBook();
		else if(k=="2") addNewBook();
		else if(k=="3") return;
		else exit(0);
	}
}
void MM::addOldBook() const {
	while(true){
		system("clear");
		int total=op->showBook();
		string num,bid,bnum;
		while(true){
			cout<< "输入要添加的书籍前的编号(输入-1返回上级菜单)" << endl;
			getline(cin,num);
			if(num=="-1") return;
			if(isPositiveInt(num) && stoi(num)<=total) break;
			cout<< "输入错误" << endl;
		}
		cout<< "要添加的书籍为" << endl;
		bid=op->showBook(stoi(num)-1);
		while(true){
			cout<< "输入新添加的书籍的数量(输入-1返回上级菜单)" << endl;
			getline(cin,bnum);
			if(bnum=="-1") return;
			if(isPositiveInt(bnum)) break;
			cout<< "数量必须为正整数" << endl;
		}
		mop->addBook(bid,stoi(bnum));
		system("clear");
		cout<< "添加书籍成功" << endl
			<< "1.继续添加" << endl
			<< "2.返回上一级" << endl
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
void MM::addNewBook() const {
	while(true){
		system("clear");
		string bid,bname,author,press,bnum;
		while(true){
			cout<< "输入新书ID(输入-1返回上级菜单)" << endl;
			getline(cin,bid);
			if(bid=="-1") return;
			replace(bid," ","_");
			if(!op->bidExist(bid)) break;
			cout<< "该id已被其他书籍占用" << endl;
		}
		cout<<"输入新书书名(输入-1返回上级菜单)" << endl;
		getline(cin,bname);
		if(bname=="-1") return;
		replace(bname," ","_");
		cout<<"输入新书作者(输入-1返回上级菜单)" << endl;
		getline(cin,author);
		if(author=="-1") return;
		replace(author," ","_");
		cout<<"输入新书出版社(输入-1返回上级菜单)" << endl;
		getline(cin,press);
		if(press=="-1") return;
		replace(press," ","_");
		while(true){
			cout<<"输入新书数量(输入-1返回上级菜单)" << endl;
			getline(cin,bnum);
			if(bnum=="-1") return;
			if(isPositiveInt(bnum)) break;
			cout<< "数量必须为正整数" << endl;
		}
		mop->addBook(Book(bid,bname,author,press,stoi(bnum)));
		system("clear");
		cout<< "添加书籍成功" << endl
			<< "1.继续添加" << endl
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
void MM::addReader() const {
	while(true){
		system("clear");
		string rid,rname,rpasswd="000000";
		while(true){
			cout<< "输入读者ID(输入-1返回上级菜单):" << endl;
			getline(cin,rid);
			if(rid=="-1") return;
			replace(rid," ","_");
			if(!op->ridExist(rid)) break;
			cout<< "该id已被其他读者占用" << endl;
		}
		cout<<"输入读者姓名(输入-1返回上级菜单):" << endl;
		getline(cin,rname);
		if(rname=="-1") return;
		replace(rname," ","_");
		mop->addReader(Reader(rid,rname,rpasswd));
		system("clear");
		cout<< "添加读者成功,初始密码为000000" << endl
			<< "1.继续添加" << endl
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
void MM::delBook() const {
	while(true){
		system("clear");
		int total=op->showBook();
		string num,bid;
		while(true){
			cout<< "输入要删除的书籍前的编号(输入-1返回上级菜单)" << endl;
			getline(cin,num);
			if(num=="-1") return;
			if(isPositiveInt(num) && stoi(num)<=total){
				if(mop->canDelb(stoi(num)-1)) break;
				else cout<< "该书不全在库中,无法删除" << endl;
			}
			else cout<< "输入错误" << endl;
		}
		cout<< "要删除的书籍为" << endl;
		bid=op->showBook(stoi(num)-1);
		mop->delBook(bid);
		system("clear");
		cout<< "删除书籍成功" << endl
			<< "1.继续删除" << endl
			<< "2.返回上级菜单" << endl
			<< "3.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=3) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") continue;
		else if(k=="2")  return;
		else exit(0);
	}
}
void MM::delReader() const {
	while(true){
		system("clear");
		int total=op->showReader();
		string num,rid;
		while(true){
			cout<< "输入要删除的读者前的编号(输入-1返回上级菜单)" << endl;
			getline(cin,num);
			if(num=="-1") return;
			if(isPositiveInt(num) && stoi(num)<=total){
				if(mop->canDelr(stoi(num)-1)) break;
				else cout<< "该读者还未归还所有书籍,无法删除" << endl;
			}
			else cout<< "输入错误" << endl;
		}
		cout<< "要删除的读者为" << endl;
		rid=op->showReader(stoi(num)-1);
		mop->delReader(rid);
		system("clear");
		cout<< "删除读者成功" << endl
			<< "1.继续删除" << endl
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
void MM::agrBorrow(const string &hid) const {
	mop->agrBorrow(hid);
	system("clear");
	cout<< "已同意借书申请" << endl;
	op->showHistory(hid);
	cout<< "1.继续处理借书申请" << endl
		<< "2.退出系统" << endl;
	string k;
	while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=2) break;
			cout<< "输入错误,请重新输入" << endl;
		}
	if(k=="1") return;
	else exit(0);
}
void MM::refBorrow(const string &hid) const {
	mop->refBorrow(hid);
	system("clear");
	cout<< "已拒绝借书申请" << endl;
	op->showHistory(hid);
	cout<< "1.继续处理借书申请" << endl
		<< "2.退出系统" << endl;
	string k;
	while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=2) break;
			cout<< "输入错误,请重新输入" << endl;
		}
	if(k=="1") return;
	else exit(0);
}
void MM::agrReturn(const string &hid) const {
	mop->agrReturn(hid);
	system("clear");
	cout<< "已同意还书申请" << endl;
	op->showHistory(hid);
	cout<< "1.继续处理还书申请" << endl
		<< "2.退出系统" << endl;
	string k;
	while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=2) break;
			cout<< "输入错误,请重新输入" << endl;
		}
	if(k=="1") return;
	else exit(0);
}
void MM::refReturn(const string &hid) const {
	mop->refReturn(hid);
	system("clear");
	cout<< "已拒绝还书申请" << endl;
	op->showHistory(hid);
	cout<< "1.继续处理还书申请" << endl
		<< "2.退出系统" << endl;
	string k;
	while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=2) break;
			cout<< "输入错误,请重新输入" << endl;
		}
	if(k=="1") return;
	else exit(0);
}
void MM::dealRequest() const {
	while(true){
		system("clear");
		cout<< "1.处理借书申请" << endl
			<< "2.处理还书申请" << endl
			<< "3.返回上级菜单" << endl
			<< "4.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=4) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") dealBorrow();
		else if(k=="2") dealReturn();
		else if(k=="3") return;
		else exit(0);
	}
}
void MM::dealBorrow() const {
	while(true){
		system("clear");
		int total=mop->showBorrowReq();
		string num,hid;
		while(true){
			cout<< "输入要处理的借书申请前的编号(输入-1返回上级菜单)" << endl;
			getline(cin,num);
			if(num=="-1") return;
			if(isPositiveInt(num) && stoi(num)<=total) break;
			cout<< "输入错误" << endl;
		}
		cout<< "选定的借书申请为" << endl;
		hid=mop->showBorrowReq(stoi(num)-1);
		if(mop->canBorrow(hid)){
			cout<< "该书仍有库存,可以借出" << endl
				<< "1.同意借书" << endl
				<< "2.拒绝借书" << endl
				<< "3.重新选择要处理的借书申请" << endl
				<< "4.返回上级菜单" << endl
				<< "5.退出系统" << endl;
			string k;
			while(true){
				getline(cin,k);
				if(isPositiveInt(k) && stoi(k)<=5) break;
				cout<< "输入错误,请重新输入" << endl;
			}
			if(k=="1") agrBorrow(hid);
			else if(k=="2") refBorrow(hid);
			else if(k=="3") continue;
			else if(k=="4") return;
			else exit(0);
		}
		else{
			cout<< "该书没有库存,无法借出" << endl
				<< "1.拒绝借书" << endl
				<< "2.重新选择要处理的借书申请" << endl
				<< "3.返回上级菜单" << endl
				<< "4.退出系统" << endl;
			string k;
			while(true){
				getline(cin,k);
				if(isPositiveInt(k) && stoi(k)<=4) break;
				cout<< "输入错误,请重新输入" << endl;
			}
			if(k=="1") refBorrow(hid);
			else if(k=="2") continue;
			else if(k=="3") return;
			else exit(0);
		}
	}
}
void MM::dealReturn() const {
	while(true){
		system("clear");
		int total=mop->showReturnReq();
		string num,hid;
		while(true){
			cout<< "输入要处理的还书申请前的编号(输入-1返回上级菜单)" << endl;
			getline(cin,num);
			if(num=="-1") return;
			if(isPositiveInt(num) && stoi(num)<=total) break;
			cout<< "输入错误" << endl;
		}
		cout<< "选定的还书申请为" << endl;
		hid=mop->showReturnReq(stoi(num)-1);
		cout<< "1.同意还书" << endl
			<< "2.拒绝还书" << endl
			<< "3.重新选择要处理的还书申请" << endl
			<< "4.返回上级菜单" << endl
			<< "5.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=5) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") agrReturn(hid);
		else if(k=="2") refReturn(hid);
		else if(k=="3") continue;
		else if(k=="4") return;
		else exit(0);
	}
}
void MM::changeMpasswd() const {
	system("clear");
	string mpasswd,mpasswd1;
	while(true){
		while(true){
			cout<< "输入新密码(输入-1返回上级菜单)"<< endl;
			getline(cin,mpasswd);
			if(mpasswd=="-1") return;
			if(mpasswd.find(" ")==string::npos) break;
			cout<< "密码中不能含有空格" << endl;
		}
		cout<< "确认新密码(输入-1返回上级菜单)" << endl;
		getline(cin,mpasswd1);
		if(mpasswd1=="-1") return;
		if(mpasswd==mpasswd1) break;
		cout<< "两次输入密码不相同" << endl;
	}
	mop->changeMpasswd(mpasswd);
	cout<< "密码修改成功,新密码为:" << endl 
		<< mpasswd << endl
		<< "输入任意字符返回" << endl;
	string k; getline(cin,k);
}
void MM::schReader() const {
	while(true){
		system("clear");
		cout<< "请输入搜索读者的关键字" << endl;
		string s; getline(cin,s);
		mop->schReader(s);
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
void MM::schHistory() const {
	while(true){
		system("clear");
		cout<< "请输入搜索历史记录的关键字" << endl;
		string s; getline(cin,s);
		mop->schHistory(s);
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
