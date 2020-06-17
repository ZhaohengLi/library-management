#include "Reader.h"
#include "History.h"
#include <bits/stdc++.h>
#define BR BaseReader
#define RL ReaderList
#define BH BaseHistory
using namespace std;

//Reader.cpp
//BaseReader:
bool BR::match(const string &s) const {
	return rid==s||rname==s;
}
void BR::show() const {
	cout<< rid << "  " << rname << "  " << borrowNum << endl;
}
istream &operator >> (istream &in,BR &br){
	in>> br.rid >> br.rname >> br.borrowNum;
	return in;
}
ostream &operator << (ostream &out,const BR &br){
	out<< br.rid << "\n" << br.rname << "\n" << br.borrowNum << endl;
	return out;
}

//Reader:
void Reader::reqBorrow(const BH &bh){
	borrowReq.add(bh);
}
void Reader::agrBorrow(const BH &bh){
	borrowReq.del(bh);
	borrowHis.add(bh);
	borrowNum++;
}
void Reader::canBorrow(const BH &bh){
	borrowReq.del(bh);
	returnHis.add(bh);
}
void Reader::refBorrow(const BH &bh){
	borrowReq.del(bh);
	returnHis.add(bh);
}
void Reader::reqReturn(const BH &bh){
	borrowHis.del(bh);
	returnReq.add(bh);
}
void Reader::agrReturn(const BH &bh){
	returnReq.del(bh);
	returnHis.add(bh);
	borrowNum--;
}
void Reader::canReturn(const BH &bh){
	returnReq.del(bh);
	borrowHis.add(bh);
}
void Reader::refReturn(const BH &bh){
	returnReq.del(bh);
	borrowHis.add(bh);
}
int Reader::showBorrowReq() const {
	return borrowReq.show();
}
int Reader::showBorrowHis() const {
	return borrowHis.show();
}
int Reader::showReturnReq() const {
	return returnReq.show();
}
int Reader::showReturnHis() const {
	return returnHis.show();
}
string Reader::showBorrowReq(const int &num) const {
	return borrowReq.show(num);
}
string Reader::showBorrowHis(const int &num) const {
	return borrowHis.show(num);
}
string Reader::showReturnReq(const int &num) const {
	return returnReq.show(num);
}
string Reader::showReturnHis(const int &num) const {
	return returnHis.show(num);
}
istream &operator >> (istream& in,Reader &r){
	in>> r.rid >> r.rname >> r.borrowNum >> r.rpasswd >> r.borrowReq >> r.borrowHis >> r.returnReq >> r.returnHis;
	return in;
}
ostream &operator << (ostream &out,const Reader &r){
	out<< r.rid << "\n" << r.rname << "\n" << r.borrowNum << "\n" << r.rpasswd << endl
	   << r.borrowReq << r.borrowHis << r.returnReq << r.returnHis << endl;
	return out;
}

//ReaderList:
BR &RL::operator [] (const string &rid){
	for(int i=0;i<rl.size();i++) if(rl[i].getRid()==rid) return rl[i];
}
BR &RL::operator [] (const int &num){
	return rl[num];
}
bool RL::ridExist(const string &rid) const {
	for(int i=0;i<rl.size();i++) if(rl[i].getRid()==rid) return true;
	return false;
}
void RL::add(const BR &br){
	rl.push_back(br);
}
void RL::del(const BR &br){
	del(br.getRid());
}
void RL::del(const string &rid){
	for(int i=0;i<rl.size();i++) if(rl[i].getRid()==rid){
		rl.erase(rl.begin()+i);
		return;
	}
}
int RL::show() const {
	cout<< "编号  读者id  读者姓名  借阅数量" << endl;
	for(int i=0;i<rl.size();i++){
		cout<< i+1 << ".  ";
		rl[i].show();
	}
	return rl.size();
}
string RL::show(const int &num) const {
	rl[num].show();
	return rl[num].getRid();
}
void RL::show(const string &rid) const {
	for(int i=0;i<rl.size();i++) if(rl[i].getRid()==rid){
		rl[i].show();
		return;
	}
}
void RL::schReader(const string &s) const {
	cout<< "编号  读者id  读者姓名  借阅数量" << endl;
	int cnt=0;
	for(int i=0;i<rl.size();i++) if(rl[i].match(s)){
		cout<< ++cnt << ".  ";
		rl[i].show();
	}
}
istream &operator >> (istream &in,RL &rl){
	int num; in>> num;
	while(num--){ BR br; in>> br; rl.add(br); }
	return in;
}
ostream &operator << (ostream &out,const RL &rl){
	out<< rl.size() << endl;
	for(int i=0;i<rl.rl.size();i++) out<< rl.rl[i];
	return out;
}
