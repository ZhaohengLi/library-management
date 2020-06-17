#include "Book.h"
#include "Reader.h"
#include "History.h"
#include "Library.h"
#include "Console.h"
#include "Functions.h"
#include <bits/stdc++.h>
#define LM Library::ManagerOperation
#define BH BaseHistory
using namespace std;

//Library_manager.cpp
extern Console con;
void LM::addBook(const string &bid,const int &num) const {
	string p=con.bdir(bid)+bid;
	Book b; con.inf(p,b);
	b.addNum(num); con.outf(p,b);
	data->bl.del(bid);
	data->bl.add(b.getBase());
	data->outbl();
}
void LM::addBook(const Book &b) const {
	string p=con.bdir(b.getBid());
	con.mkdir(p);
	p+=b.getBid();
	con.outf(p,b);
	data->bl.add(b.getBase());
	data->outbl();
}
void LM::addReader(const Reader &r) const {
	string p=con.rdir(r.getRid());
	con.mkdir(p);
	p+=r.getRid();
	con.outf(p,r);
	data->rl.add(r.getBase());
	data->outrl();
}
bool LM::canDelb(const string &bid) const {
	return data->bl[bid].canDel();
}
bool LM::canDelr(const string &rid) const {
	return data->rl[rid].canDel();
}
bool LM::canDelb(const int &num) const {
	return data->bl[num].canDel();
}
bool LM::canDelr(const int &num) const {
	return data->rl[num].canDel();
}
void LM::delBook(const string &bid) const {
	string p=con.bdir(bid);
	con.rmdir(p);
	data->bl.del(bid);
	data->outbl();
}
void LM::delReader(const string &rid) const {
	string p=con.rdir(rid);
	con.rmdir(p);
	data->rl.del(rid);
	data->outrl();
}
void LM::agrBorrow(const string &hid) const {
	BH bh=data->hl[hid];
	string bid=bh.getBid(),rid=bh.getRid();
	string bp=con.bdir(bid)+bid; Book b; con.inf(bp,b);
	string rp=con.rdir(rid)+rid; Reader r; con.inf(rp,r);
	string hp=con.hdir(hid)+hid; History h; con.inf(hp,h);
	h.agrBorrow(); con.outf(hp,h); bh=h.getBase();
	b.agrBorrow(bh); con.outf(bp,b);
	r.agrBorrow(bh); con.outf(rp,r);
	data->bl.del(bid); data->bl.add(b.getBase()); data->outbl();
	data->rl.del(rid); data->rl.add(r.getBase()); data->outrl();
	data->hl.del(hid); data->hl.add(bh); data->outhl();
	data->borrowReq.del(hid); data->outbr();
}
void LM::agrReturn(const string &hid) const {
	BH bh=data->hl[hid];
	string bid=bh.getBid(),rid=bh.getRid();
	string bp=con.bdir(bid)+bid; Book b; con.inf(bp,b);
	string rp=con.rdir(rid)+rid; Reader r; con.inf(rp,r);
	string hp=con.hdir(hid)+hid; History h; con.inf(hp,h);
	h.agrReturn(); con.outf(hp,h); bh=h.getBase();
	b.agrReturn(bh); con.outf(bp,b);
	r.agrReturn(bh); con.outf(rp,r);
	data->bl.del(bid); data->bl.add(b.getBase()); data->outbl();
	data->rl.del(rid); data->rl.add(r.getBase()); data->outrl();
	data->hl.del(hid); data->hl.add(bh); data->outhl();
	data->returnReq.del(hid); data->outrr();
}
void LM::refBorrow(const string &hid) const {
	BH bh=data->hl[hid];
	string bid=bh.getBid(),rid=bh.getRid();
	string bp=con.bdir(bid)+bid; Book b; con.inf(bp,b);
	string rp=con.rdir(rid)+rid; Reader r; con.inf(rp,r);
	string hp=con.hdir(hid)+hid; History h; con.inf(hp,h);
	h.refBorrow(); con.outf(hp,h); bh=h.getBase();
	b.refBorrow(bh); con.outf(bp,b);
	r.refBorrow(bh); con.outf(rp,r);
	data->hl.del(hid); data->hl.add(bh); data->outhl();
	data->borrowReq.del(hid); data->outbr();
}
void LM::refReturn(const string &hid) const {
	BH bh=data->hl[hid];
	string bid=bh.getBid(),rid=bh.getRid();
	string bp=con.bdir(bid)+bid; Book b; con.inf(bp,b);
	string rp=con.rdir(rid)+rid; Reader r; con.inf(rp,r);
	string hp=con.hdir(hid)+hid; History h; con.inf(hp,h);
	h.refReturn(); con.outf(hp,h); bh=h.getBase();
	b.refReturn(bh); con.outf(bp,b);
	r.refReturn(bh); con.outf(rp,r);
	data->hl.del(hid); data->hl.add(bh); data->outhl();
	data->returnReq.del(hid); data->outrr();
}
int LM::showBorrowReq() const {
	return data->borrowReq.show();
}
int LM::showReturnReq() const {
	return data->returnReq.show();
}
string LM::showBorrowReq(const int &num) const {
	return data->borrowReq.show(num);
}
string LM::showReturnReq(const int &num) const {
	return data->returnReq.show(num);
}
bool LM::canBorrow(const string &hid) const {
	return data->bl[data->hl[hid].getBid()].canBorrow();
}
void LM::schReader(const string &s) const {
	data->rl.schReader(s);
}
void LM::schHistory(const string &s) const {
	data->hl.schHistory(s);
}
