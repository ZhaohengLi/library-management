#include "Menu.h"
#include "Library.h"
#include "Functions.h"
#include "bits/stdc++.h"
#define MR Menu::ReaderMenu
using namespace std;

//Menu_reader.cpp
void MR::login() const {
	while(true){
		system("clear");
		string rid,rpasswd;
		while(true){
			cout<< "请输入读者id(输入-1返回上级菜单)" << endl;
			getline(cin,rid);
			if(rid=="-1") return;
			if(op->ridExist(rid)) break;
			cout<< "不存在id为 " << rid << " 的读者" << endl;
		}
		rop->setReader(rid);
		while(true){
			cout<< "请输入密码(输入-1返回上级菜单)" << endl;
			getline(cin,rpasswd);
			if(rpasswd=="-1") return;
			if(rop->rpasswdRight(rpasswd)) break;
			cout<< "密码错误" << endl;
		}
		start();
	}
}
void MR::start() const {
	while(true){
		system("clear");
		cout<< "1.借阅书籍" << endl
			<< "2.归还书籍" << endl
			<< "3.显示所有书籍" << endl
			<< "4.搜索书籍" << endl
			<< "5.更改密码" << endl
			<< "6.返回上级菜单" << endl
			<< "7.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=7) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") borrowBook();
		else if(k=="2") returnBook();
		else if(k=="3") showBook();
		else if(k=="4") schBook();
		else if(k=="5") changeRpasswd();
		else if(k=="6") return;
		else exit(0);
	}
}
void MR::borrowBook() const {
	while(true){
		system("clear");
		cout<< "1.提出借书申请" << endl
			<< "2.撤销借书申请" << endl
			<< "3.返回上级菜单" << endl
			<< "4.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=4)break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") reqBorrow();
		else if(k=="2") canBorrow();
		else if(k=="3") return;
		else exit(0);
	}
}
void MR::returnBook() const {
	while(true){
		system("clear");
		cout<< "1.提出还书申请" << endl
			<< "2.撤销还书申请" << endl
			<< "3.返回上级菜单" << endl
			<< "4.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=4) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") reqReturn();
		else if(k=="2") canReturn();
		else if(k=="3") return;
		else exit(0);
	}
}
void MR::reqBorrow() const {
	while(true){
		system("clear");
		int total=op->showBook();
		string num,bid;
		while(true){
			cout<< "输入借阅图书前的编号(输入-1返回上级菜单)" << endl;
			getline(cin,num);
			if(num=="-1") return;
			if(isPositiveInt(num) && stoi(num)<=total) break;
			cout<< "输入错误" << endl;
		}
		cout<< "要借阅的图书为" << endl;
		bid=op->showBook(stoi(num)-1);
		rop->reqBorrow(bid);
		cout<< "借书申请已提交" << endl
			<< "1.继续提出借书申请" << endl
			<< "2.返回上级菜单" << endl
			<< "3.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k) <=3) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") continue;
		else if(k=="2") return;
		else exit(0);
	}
}
void MR::reqReturn() const {
	while(true){
		system("clear");
		int total=rop->showBorrowHis();
		string num,hid;
		while(true){
			cout<< "输入要归还的书籍前的编号(输入-1返回上级菜单)" << endl;
			getline(cin,num);
			if(num=="-1") return;
			if(isPositiveInt(num) && stoi(num)<=total ) break;
			cout<< "输入错误" << endl;
		}
		cout<< "要归还的书籍为" << endl;
		hid=rop->showBorrowHis(stoi(num)-1);
		rop->reqReturn(hid);
		cout<< "还书申请已提交" << endl
			<< "1.继续提出还书申请" << endl
			<< "2.返回上级菜单" << endl
			<< "3.退出系统" << endl;
		string k;
		while(true){
			getline(cin,k);
			if(isPositiveInt(k) && stoi(k)<=3) break;
			cout<< "输入错误,请重新输入" << endl;
		}
		if(k=="1") continue;
		else if(k=="2") break;
		else exit(0);
	}
}
void MR::canBorrow() const {
	while(true){
		system("clear");
		int total=rop->showBorrowReq();
		string num,hid;
		while(true){
			cout<< "输入要撤销的借书申请前的编号(输入-1返回上级菜单)" << endl;
			getline(cin,num);
			if(num=="-1") return;
			if(isPositiveInt(num) && stoi(num)<=total) break;
			cout<< "输入错误" << endl;
		}
		cout<< "要撤销的借书申请为" << endl;
		hid=rop->showBorrowReq(stoi(num)-1);
		rop->canBorrow(hid);
		cout<< "借书申请已撤销" << endl
			<< "1.继续撤销借书申请" << endl
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
void MR::canReturn() const {
	while(true){
		system("clear");
		int total=rop->showReturnReq();
		string num,hid;
		while(true){
			cout<< "输入要撤销的还书申请前的编号(输入-1返回上级菜单)" << endl;
			getline(cin,num);
			if(num=="-1") return;
			if(isPositiveInt(num) && stoi(num)<=total) break;
			cout<< "输入错误" << endl;
		}
		cout<< "要撤销的还书申请为:" << endl;
		hid=rop->showReturnReq(stoi(num)-1);
		rop->canReturn(hid);
		cout<< "还书申请已撤销" << endl
			<< "1.继续撤销还书申请" << endl
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
void MR::changeRpasswd() const {
	system("clear");
	string rpasswd,rpasswd1;
	while(true){
		while(true){
			cout<< "输入新密码(输入-1返回上级菜单)" << endl;
			getline(cin,rpasswd);
			if(rpasswd=="-1") return;
			if(rpasswd.find(" ")==string::npos) break;
			cout<< "密码中不能含有空格" << endl;
		}
		cout<< "确认新密码(输入-1返回上级菜单)" << endl;
		getline(cin,rpasswd1);
		if(rpasswd1=="-1") return;
		if(rpasswd==rpasswd1) break;
		cout<< "两次密码输入不相同" << endl;
	}
	rop->changeRpasswd(rpasswd);
	cout<< "密码修改成功,新密码为:" << endl
		<< rpasswd << endl
		<< "输入任意字符返回" << endl;
	string k; getline(cin,k);
}
