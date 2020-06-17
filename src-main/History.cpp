#include "History.h"
#include "Functions.h"
#include <bits/stdc++.h>
#define BH BaseHistory
#define HL HistoryList
using namespace std;

//History.cpp
//BaseHistoy
bool BH::match(const string &s) const {
	return hid==s||bid==s||rid==s||bname==s||rname==s||note==s;
}
void BH::show() const {
	cout<< hid << "  " << rid << "  " << rname << "  " << bid << "  " << bname << "  "
		<< btime << "  " << rtime << "  " << note << endl;
}
istream &operator >> (istream &in,BH &bh){
	in>> bh.hid >> bh.bid >> bh.rid >> bh.bname >> bh.rname >> bh.note
	  >> bh.brtime >> bh.btime >> bh.rrtime >> bh.rtime;
	return in;
}
ostream &operator << (ostream &out,const BH &bh){
	out<< bh.hid << "\n" << bh.bid << "\n" << bh.rid << "\n" << bh.bname << "\n" << bh.rname << "\n"
	   << bh.note << "\n" << bh.brtime << "\n" << bh.btime << "\n" << bh.rrtime << "\n"
	   << bh.rtime << endl;
	return out;
}
//History::Record
istream &operator >> (istream &in,History::Record &hr){
	in>> hr.time >> hr.note;
	return in;
}
ostream &operator << (ostream &out,const History::Record &hr){
	out<< hr.time << "\n" << hr.note << endl;
	return out;
}
//History:
void History::reqBorrow(){
	string t=getTime();
	record.push_back(Record(t,"申请借书"));
	note="借书申请待审核";
	brtime=t;
}
void History::agrBorrow(){
	string t=getTime();
	record.push_back(Record(t,"同意借书"));
	note="借出中";
	btime=t;
}
void History::canBorrow(){
	string t=getTime();
	record.push_back(Record(t,"取消借书"));
	note="借书申请已撤销";
}
void History::refBorrow(){
	string t=getTime();
	record.push_back(Record(t,"拒绝借书"));
	note="借书申请被拒绝";
}
void History::reqReturn(){
	string t=getTime();
	record.push_back(Record(t,"申请还书"));
	note="还书申请待审核";
	rrtime=t;
}
void History::agrReturn(){
	string t=getTime();
	record.push_back(Record(t,"同意还书"));
	note="已归还";
	rtime=t;
}
void History::canReturn(){
	string t=getTime();
	record.push_back(Record(t,"取消还书"));
	note="还书申请已撤销";
}
void History::refReturn(){
	string t=getTime();
	record.push_back(Record(t,"拒绝还书"));
	note="还书申请被拒绝";
}
istream &operator >> (istream &in,History &h){
	in>> h.hid >> h.bid >> h.rid >> h.bname >> h.rname >> h.note
	  >> h.brtime >> h.btime >> h.rrtime >> h.rtime;
	int num; in>> num;
	while(num--){ History::Record hr; in>> hr; h.record.push_back(hr); }
	return in;
}
ostream &operator << (ostream &out,const History &h){
	out<< h.hid << "\n" << h.bid << "\n" << h.rid << "\n" << h.bname << "\n" << h.rname << "\n"
	   << h.note << "\n" << h.brtime << "\n" << h.btime << "\n" << h.rrtime << "\n"
	   << h.rtime << endl;
	out<< h.record.size() << endl;
	for(int i=0;i<h.record.size();i++) out<< h.record[i];
	return out;
}
//HistoryList
BH &HL::operator [] (const string &hid){
	for(int i=0;i<hl.size();i++) if(hl[i].getHid()==hid) return hl[i];
}
BH &HL::operator [] (const int &num){
	return hl[num];
}
void HL::add(const BH &bh){
	hl.push_back(bh);
}
void HL::del(const BH &bh){
	del(bh.getHid());
}
void HL::del(const string &hid){
	for(int i=0;i<hl.size();i++) if(hl[i].getHid()==hid){
		hl.erase(hl.begin()+i);
		return;
	}
}
int HL::show() const {
	cout<< "编号  历史记录id  读者id  读者姓名  书籍id  书籍名称  借书时间  还书时间  借阅状态" << endl;
	for(int i=0;i<hl.size();i++){
		cout<< i+1 << ".  ";
		hl[i].show();
	}
	return hl.size();
}
string HL::show(const int &num) const {
	hl[num].show();
	return hl[num].getHid();
}
void HL::show(const string &hid) const {
	for(int i=0;i<hl.size();i++) if(hl[i].getHid()==hid){
		hl[i].show();
		return;
	}
}
void HL::schHistory(const string &s) const {
	cout<< "编号  历史记录id  读者id  读者姓名  书籍id  书籍名称  借书时间  还书时间  借阅状态" << endl;
	int cnt=0;
	for(int i=0;i<hl.size();i++) if(hl[i].match(s)){
		cout<< ++cnt << ".  ";
		hl[i].show();
	}
}
istream &operator >> (istream &in,HL &hl){
	int num; in>> num;
	while(num--) { BH bh; in>> bh; hl.add(bh); }
	return in;
}
ostream &operator << (ostream &out,const HL &hl){
	out<< hl.size() << endl;
	for(int i=0;i<hl.hl.size();i++) out<< hl.hl[i];
	return out;
}
