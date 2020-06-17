#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Reader.h"
#include "History.h"
#include "Console.h"
#include "qtablemodel.h"
#include <bits/stdc++.h>

#include <QStandardItemModel>
#include <QApplication>

using namespace std;

//Libray.h
extern Console con;
class Library{
	class Data{
	public:
		BookList bl;
		ReaderList rl;
		HistoryList hl;
		HistoryList borrowReq;
		HistoryList returnReq;
		string getHid() const { return "His"+to_string(100000000+hl.size()); }
        void outbl() const { con.outf(QApplication::applicationDirPath().toStdString() + "/data/bookls",bl); }
        void outrl() const { con.outf(QApplication::applicationDirPath().toStdString() + "/data/readerls",rl);}
        void outhl() const { con.outf(QApplication::applicationDirPath().toStdString() + "/data/historyls",hl); }
        void outbr() const { con.outf(QApplication::applicationDirPath().toStdString() + "/data/borrowReq",borrowReq); }
        void outrr() const { con.outf(QApplication::applicationDirPath().toStdString() + "/data/returnReq",returnReq); }
        /*void outbl() const { con.outf("data/bookls",bl); }
        void outrl() const { con.outf("data/readerls",rl);}
        void outhl() const { con.outf("data/historyls",hl); }
        void outbr() const { con.outf("data/borrowReq",borrowReq); }
        void outrr() const { con.outf("data/returnReq",returnReq); }*/
        Data(){}
        /*Data(){
			con.inf("data/bookls",bl);
            con.inf(QDir::currentPath().toStdString() + "/data/readerls",rl);
			con.inf("data/historyls",hl);
			con.inf("data/borrowReq",borrowReq);
			con.inf("data/returnReq",returnReq);
        }*/
        void init(){
            con.inf(QApplication::applicationDirPath().toStdString() + "/data/bookls",bl);
            con.inf(QApplication::applicationDirPath().toStdString() + "/data/readerls",rl);
            con.inf(QApplication::applicationDirPath().toStdString() + "/data/historyls",hl);
            con.inf(QApplication::applicationDirPath().toStdString() + "/data/borrowReq",borrowReq);
            con.inf(QApplication::applicationDirPath().toStdString() + "/data/returnReq",returnReq);
        }
	}data;
public:
	class Operation{
		Data *data;
	public:
        Operation(Data *_data):data(_data){}
        void sortByBorrow() const;
		int showBook() const;
		int showReader() const;

        QTableModel* QshowBook() const;
        QTableModel* QshowBook(int rows) const;

        QTableModel* QshowReader() const;

		int showHistory() const;		//将bl,rl,hl输出到屏幕上,并返回总数
		string showBook(const int &num) const;
		string showReader(const int &num) const;
		string showHistory(const int &num) const;		//将特定序号的输出到屏幕上,并返回id
		void showBook(const string &bid) const;

        QStringList QshowBook(const string &bid) const;

		void showReader(const string &rid) const;

        QStringList QshowReader(const string &rid) const;

		void showHistory(const string &hid) const;
		void schBook(const string &s) const;

        QTableModel* QschBook(const string &s) const;

		bool bidExist(const string &bid);
		bool ridExist(const string &rid);
	}op;
	class ManagerOperation{
		Data *data;
		string mpasswd;
	public:
        ManagerOperation(Data *_data):data(_data){}
        void init(){ con.inf(QApplication::applicationDirPath().toStdString() + "/data/managerPasswd",mpasswd); }
        void outp() const { con.outf(QApplication::applicationDirPath().toStdString() + "/data/managerPasswd",mpasswd); }
		void addBook(const string &bid,const int &num) const;
		void addBook(const Book &b) const;
		void addReader(const Reader &r) const;
		bool canDelb(const string &bid) const;
		bool canDelr(const string &rid) const;
		bool canDelb(const int &num) const;
		bool canDelr(const int &num) const;
		void delBook(const string &bid) const;
		void delReader(const string &rid) const;
		void agrBorrow(const string &hid) const;
		void agrReturn(const string &hid) const;
		void refBorrow(const string &hid) const;
		void refReturn(const string &hid) const;
		int showBorrowReq() const;

        QTableModel* QshowBorrowReq() const;

		int showReturnReq() const;		//将借还申请输出到屏幕上,并返回申请的总数

        QTableModel* QshowReturnReq() const;

		string showBorrowReq(const int &num) const;
		string showReturnReq(const int &num) const;		//将特定序号的借还申请输出,并返回hid
		bool canBorrow(const string &hid) const;
		bool mpasswdRight(const string &_mpasswd) const { return mpasswd==_mpasswd; }
		void changeMpasswd(const string &_mpasswd){ mpasswd=_mpasswd; outp(); }
		void schReader(const string &s) const;

        QTableModel* QschReader(const string &s) const;
        QTableModel* Qschrid(const string &s) const;
        QTableModel* Qschrname(const string &s) const;

		void schHistory(const string &s) const;

        QTableModel* QschHistory(const string &s) const;
	}mop;
	class ReaderOperation{
		Data *data;
		string rid,rp;
		Reader r;
		string addHistory(const string &bid) const;		//由要借书的bid新建一个历史记录,并返回hid
	public:
        ReaderOperation(Data *_data):data(_data){}
		void setReader(const string &_rid);
        void logout(){ r.clr(); }
		void reqBorrow(const string &bid);
		void canBorrow(const string &hid);
		void reqReturn(const string &hid);
		void canReturn(const string &hid);
		int showBorrowHis() const;
		int showBorrowReq() const;
		int showReturnReq() const;
		int showReturnHis() const;		//将历史记录输出到屏幕上,并返回历史记录的数量

        QTableModel* QshowBorrowHis() const;
        QTableModel* QshowBorrowReq() const;
        QTableModel* QshowReturnReq() const;
        QTableModel* QshowReturnHis() const;

        string getRname() const;
        string getRid() const;

        string showBorrowReq(const int &num) const;
		string showBorrowHis(const int &num) const;
		string showReturnReq(const int &num) const;
		string showReturnHis(const int &num) const;		//将特定序号的历史记录输出,并返回hid

		bool rpasswdRight(const string &rpasswd) const { return r.rpasswdRight(rpasswd); }
		void changeRpasswd(const string &rpasswd);
	}rop;
    Library():op(Operation(&data)),mop(ManagerOperation(&data)),rop(ReaderOperation(&data)){}
    void init();
};

#endif
