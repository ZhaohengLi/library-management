#ifndef READER_H
#define READER_H

#include "History.h"
#include "qtablemodel.h"
#include <bits/stdc++.h>

#include <QStandardItemModel>

#define HL HistoryList
#define BH BaseHistory
using namespace std;

//Reader.h
class BaseReader{
protected:
	string rid,rname;
	int borrowNum;
public:
	BaseReader(string _rid,string _rname,int _borrowNum=0):rid(_rid),rname(_rname),borrowNum(_borrowNum){}
	BaseReader(){}
	string getRid() const { return rid; }
	string getRname() const { return rname; }
	int getBorrowNum() const { return borrowNum; }
	bool canDel() const { return borrowNum==0; }
	bool match(const string &s) const;

    bool Qmatchrid(const string &s) const;
    bool Qmatchrname(const string &s) const;

	void show() const;		//将BaseReader存储的信息输出到屏幕上

    QStringList Qshow() const;

	friend istream &operator >> (istream &in,BaseReader &br);
	friend ostream &operator << (ostream &out,const BaseReader &br);
};
class Reader : public BaseReader{
	string rpasswd;
	HL borrowReq;
	HL borrowHis;
	HL returnReq;
	HL returnHis;
public:
	Reader(string _rid,string _rname,string _rpasswd,int _borrowNum=0)
		:BaseReader(_rid,_rname,_borrowNum){ rpasswd=_rpasswd; }
	Reader(){}
	BaseReader getBase() const { return BaseReader(rid,rname,borrowNum); }
	bool rpasswdRight(const string &_rpasswd) const { return rpasswd==_rpasswd; }
	void changeRpasswd(const string &_rpasswd){ rpasswd=_rpasswd; }
    void clr();
	void reqBorrow(const BH &bh);
	void agrBorrow(const BH &bh);
	void canBorrow(const BH &bh);
	void refBorrow(const BH &bh);
	void reqReturn(const BH &bh);
	void agrReturn(const BH &bh);
	void canReturn(const BH &bh);
	void refReturn(const BH &bh);
	int showBorrowReq() const ;		
	int showBorrowHis() const ;
	int showReturnReq() const ;
	int showReturnHis() const ;		//将Reader的相关历史记录输出到屏幕上,并返回相应历史记录的总数

    QTableModel* QshowBorrowReq() const;
    QTableModel* QshowBorrowHis() const;
    QTableModel* QshowReturnReq() const;
    QTableModel* QshowReturnHis() const;

	string showBorrowReq(const int &num) const ;
	string showBorrowHis(const int &num) const ;
	string showReturnReq(const int &num) const ;
	string showReturnHis(const int &num) const ;		//将特点序号的历史记录输出到屏幕上,并返回hid
	friend istream &operator >> (istream &in,Reader &r);
	friend ostream &operator << (ostream &out,const Reader &r);
};
class ReaderList{
	vector <BaseReader> rl;
public:
	BaseReader &operator [] (const string &id);
	BaseReader &operator [] (const int &num);
	int size() const { return rl.size(); }
	bool ridExist(const string &rid) const;
	void add(const BaseReader &br);
	void del(const BaseReader &br);
	void del(const string &id);
	int show() const;		//将rl存储的信息输出到屏幕上并返回rl的大小

    QTableModel* Qshow() const;

    QStringList Qshow(const string &rid) const;

	string show(const int &num) const;		//将rl[num]输出到屏幕上,并返回rid

	void show(const string &rid) const;
	void schReader(const string &s) const;

    QTableModel* QschReader(const string &s) const;
    QTableModel* Qschrid(const string &s) const;
    QTableModel* Qschrname(const string &s) const;

	friend istream &operator >> (istream &in,ReaderList &rl);
	friend ostream &operator << (ostream &out,const ReaderList &rl);
};

#endif
