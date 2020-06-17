#include "Book.h"
#include "Reader.h"
#include "History.h"
#include "Library.h"
#include "Console.h"
#include "Functions.h"
#include <bits/stdc++.h>
#define LR Library::ReaderOperation
#define BH BaseHistory
using namespace std;

//Library_reader.cpp
extern Console con;
string LR::addHistory(const string &bid) const {
	string hid=data->getHid();
	History h(hid,bid,rid,data->bl[bid].getBname(),data->rl[rid].getRname());
	string p=con.hdir(hid);
	con.mkdir(p);
	p+=hid;
	con.outf(p,h);
	data->hl.add(h.getBase());
	data->outhl();
	return hid;
}
void LR::setReader(const string &_rid){
	rid=_rid;
	rp=con.rdir(rid)+rid;
	con.inf(rp,r);
}
void LR::reqBorrow(const string &bid){
	string hid=addHistory(bid);
	BH bh=data->hl[hid];
	string bp=con.bdir(bid)+bid; Book b; con.inf(bp,b);
	string hp=con.hdir(hid)+hid; History h; con.inf(hp,h);
	h.reqBorrow(); con.outf(hp,h); bh=h.getBase();
	b.reqBorrow(bh); con.outf(bp,b);
	r.reqBorrow(bh); con.outf(rp,r);
	data->hl.del(hid); data->hl.add(bh); data->outhl();
	data->borrowReq.add(bh); data->outbr();
}
void LR::canBorrow(const string &hid){
	BH bh=data->hl[hid];
	string bid=bh.getBid();
	string bp=con.bdir(bid)+bid; Book b; con.inf(bp,b);
	string hp=con.hdir(hid)+hid; History h; con.inf(hp,h);
	h.canBorrow(); con.outf(hp,h); bh=h.getBase();
	b.canBorrow(bh); con.outf(bp,b);
	r.canBorrow(bh); con.outf(rp,r);
	data->hl.del(hid); data->hl.add(bh); data->outhl();
	data->borrowReq.del(hid); data->outbr();
}
void LR::reqReturn(const string &hid){
	BH bh=data->hl[hid];
	string bid=bh.getBid();
	string bp=con.bdir(bid)+bid; Book b; con.inf(bp,b);
	string hp=con.hdir(hid)+hid; History h; con.inf(hp,h);
	h.reqReturn(); con.outf(hp,h); bh=h.getBase();
	b.reqReturn(bh); con.outf(bp,b);
	r.reqReturn(bh); con.outf(rp,r);
	data->hl.del(hid); data->hl.add(bh); data->outhl();
	data->returnReq.add(bh); data->outrr();
}
void LR::canReturn(const string &hid){
	BH bh=data->hl[hid];
	string bid=bh.getBid();
	string bp=con.bdir(bid)+bid; Book b; con.inf(bp,b);
	string hp=con.hdir(hid)+hid; History h; con.inf(hp,h);
	h.canReturn(); con.outf(hp,h); bh=h.getBase();
	b.canReturn(bh); con.outf(bp,b);
	r.canReturn(bh); con.outf(rp,r);
	data->hl.del(hid); data->hl.add(bh); data->outhl();
	data->returnReq.del(bh); data->outrr();
}
int LR::showBorrowReq() const {
	return r.showBorrowReq();
}
int LR::showBorrowHis() const {
	return r.showBorrowHis();
}
int LR::showReturnReq() const {
	return r.showReturnReq();
}
int LR::showReturnHis() const {
	return r.showReturnHis();
}

QTableModel* LR::QshowBorrowHis() const {
    return r.QshowBorrowHis();
}
QTableModel* LR::QshowBorrowReq() const {
    return r.QshowBorrowReq();
}
QTableModel* LR::QshowReturnReq() const {
    return r.QshowReturnReq();
}
QTableModel* LR::QshowReturnHis() const {
    return r.QshowReturnHis();
}

string LR::getRname() const {
    return r.getRname();
}

string LR::getRid() const {
    return r.getRid();
}

string LR::showBorrowReq(const int &num) const {
	return r.showBorrowReq(num);
}
string LR::showBorrowHis(const int &num) const {
	return r.showBorrowHis(num);
}
string LR::showReturnReq(const int &num) const {
	return r.showReturnReq(num);
}
string LR::showReturnHis(const int &num) const {
	return r.showReturnHis(num);
}
void LR::changeRpasswd(const string &rpasswd){
	r.changeRpasswd(rpasswd);
	con.outf(rp,r);
}
