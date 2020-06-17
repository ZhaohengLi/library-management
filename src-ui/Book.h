#ifndef BOOK_H
#define BOOK_H

#include "History.h"
#include "qtablemodel.h"
#include <bits/stdc++.h>

#include <QStandardItemModel>

#define BH BaseHistory
#define HL HistoryList
using namespace std;

//Book.h
class BaseBook{
protected:
	string bid,bname,author,press;
	int totalNum,borrowNum;
public:
	BaseBook(string _bid, string _bname,string _author,string _press,int _totalNum,int _borrowNum=0)
		:bid(_bid),bname(_bname),author(_author),press(_press),totalNum(_totalNum),borrowNum(_borrowNum){}
	BaseBook(){}
	string getBid() const { return bid; }
	string getBname() const { return bname; }
	string getAuthor() const { return author; }
	string getPress() const { return press; }
	int getBorrowNum() const { return borrowNum; }
	int getTotalNum() const { return totalNum; }
	bool canBorrow() const { return totalNum-borrowNum>0; }
	bool canDel() const { return borrowNum==0; }
	bool match(const string &s) const;
	void show() const;		//将BaseBook对象存储的信息输出到屏幕上

    QStringList Qshow() const;

	friend istream &operator >> (istream &in,BaseBook &bb);
	friend ostream &operator << (ostream &out,const BaseBook &bb);
};
class Book : public BaseBook{
	HL borrowReq;
	HL borrowHis;
	HL returnReq;
	HL returnHis;
public:
	using BaseBook::BaseBook;
	BaseBook getBase() const { return BaseBook(bid,bname,author,press,totalNum,borrowNum); }
	void addNum(const int &num);
	void reqBorrow(const BH &bh);
	void agrBorrow(const BH &bh);
	void canBorrow(const BH &bh);
	void refBorrow(const BH &bh);
	void reqReturn(const BH &bh);
	void agrReturn(const BH &bh);
	void canReturn(const BH &bh);
	void refReturn(const BH &bh);
	int showBorrowReq() const;
	int showBorrowHis() const;
	int showReturnReq() const;
	int showReturnHis() const;		//将Reader的相关历史记录输出到屏幕上并返回相应历史记录的数量
	string showBorrowReq(const int &num) const;
	string showBorrowHis(const int &num) const;
	string showReturnReq(const int &num) const;
	string showReturnHis(const int &num) const;		//将特定序号的历史记录输出到屏幕上并返回hid
	friend istream &operator >> (istream &in,Book &b);
	friend ostream &operator << (ostream &out,const Book &b);
};
class BookList{
	vector <BaseBook> bl;
public:
	BaseBook &operator [] (const string &bid);
	BaseBook &operator [] (const int &num);
	int size() const { return bl.size(); }
	bool bidExist(const string &bid) const;
	void add(const BaseBook &bb);
	void del(const BaseBook &bb);
	void del(const string &bid);
	int show() const;		//将bl中存储的数据输出到屏幕上,并返回bl的大小

    QTableModel* Qshow() const;

    QTableModel* Qshow(int rows) const;

	string show(const int &num) const;		//将bl[num]中存储的数据输出到屏幕上,并返回bid
	void show(const string &bid) const;

    QStringList Qshow(const string &bid) const;

    QTableModel* QschBook(const string &bid) const;

	void schBook(const string &s) const;
    void sortByBorrow();
	friend istream &operator >> (istream &in,BookList &bl);
	friend ostream &operator << (ostream &out,const BookList &bl);
};

#endif
