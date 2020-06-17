#ifndef HISTORY_H
#define HISTORY_H

#include "qtablemodel.h"

#include <bits/stdc++.h>
using namespace std;

//History.h
class BaseHistory{
protected:
	string hid,bid,rid,bname,rname,note,brtime,btime,rrtime,rtime;
public:
	BaseHistory(string _hid,string _bid,string _rid,string _bname,string _rname,string _note="无",string _brtime="无",string _btime="无",string _rrtime="无",string _rtime="无"):
		hid(_hid),bid(_bid),rid(_rid),bname(_bname),rname(_rname),note(_note),brtime(_brtime),btime(_btime),rrtime(_rrtime),rtime(_rtime){}
	BaseHistory(){}
	string getHid() const { return hid; }
	string getBid()const { return bid; }
	string getRid() const { return rid; }
	string getBname() const { return bname; }
	string getRname() const { return rname; }
	string getNote() const { return note; }
	string getBrtime() const { return brtime; }
	string getBtime() const { return btime; }
	string getRrtime() const { return rrtime; }
	string getRtime() const { return rtime; }
	bool match(const string &s) const;
	void show() const;		//将BaseHistory对象存储的信息输出到屏幕上

    QStringList Qshow() const;

	friend istream &operator >> (istream &in,BaseHistory &bh);
	friend ostream &operator << (ostream &out,const BaseHistory &bh);
};
class History : public BaseHistory{
	class Record{
		string time,note;
	public:
		Record(string _time,string _note):time(_time),note(_note){}
		Record(){}
		friend istream &operator >> (istream &in,Record &r);
		friend ostream &operator << (ostream &out,const Record &r);
	};
	vector <Record> record;
public:
	using BaseHistory::BaseHistory;
	BaseHistory getBase() const { return BaseHistory(hid,bid,rid,bname,rname,note,brtime,btime,rrtime,rtime); }
    void reqBorrow();   //申请借阅
    void agrBorrow();   //同意借阅
    void canBorrow();   //可以借阅
    void refBorrow();   //拒绝借阅
    void reqReturn();   //申请归还
    void agrReturn();   //同意归还
    void canReturn();   //可以归还
    void refReturn();   //拒绝归还
	friend istream &operator >> (istream &in,Record &r);
	friend ostream &operator << (ostream &out,const Record &r);
	friend istream &operator >> (istream &in,History &h);
	friend ostream &operator << (ostream &out,const History &h);
};
class HistoryList{
	vector <BaseHistory> hl;
public:
	BaseHistory &operator [] (const string &hid);
	BaseHistory &operator [] (const int &num);
	int size() const { return hl.size(); }
    void clr(){ hl.clear(); }
	void add(const BaseHistory &bh);
	void del(const BaseHistory &bh);
	void del(const string &hid);
	int show() const;		//将hl存储的信息输出到屏幕上,并且返回hl的大小

    QTableModel* Qshow() const;

	string show(const int &num) const;		//将hl[num]存储的信息输出到屏幕上,并返回其his
	void show(const string &hid) const;
	void schHistory(const string &s) const;

    QTableModel* QschHistory(const string &s) const;

	friend istream &operator >> (istream &in,HistoryList &hl);
	friend ostream &operator << (ostream &out,const HistoryList &hl);
};

#endif


