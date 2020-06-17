#include "Book.h"
#include "History.h"
#include <bits/stdc++.h>

#include <QString>
#include <QDebug>

#define BB BaseBook
#define BH BaseHistory
#define BL BookList
using namespace std;

//Book.cpp
//BaseBook:
bool BB::match(const string &s) const {
	return bid==s||bname==s||author==s||press==s;
}
void BB::show() const {
	cout<< bid << "  " << bname << "  " << author << "  " << press << "  " << totalNum << "  " << borrowNum << endl;
}

QStringList BB::Qshow() const {
    QStringList line;
    line<< QString::fromStdString(bid) << QString::fromStdString(bname) << QString::fromStdString(author)
        << QString::fromStdString(press) << QString::number(totalNum-borrowNum) << QString::number(borrowNum);
    return line;
}

istream &operator >> (istream &in,BB &bb){
	in>> bb.bid >> bb.bname >> bb.author >> bb.press >> bb.totalNum >> bb.borrowNum;
	return in;
}
ostream &operator << (ostream &out,const BB &bb){
	out<< bb.bid << "\n" << bb.bname << "\n" << bb.author << "\n" << bb.press << "\n" << bb.totalNum << "\n" << bb.borrowNum << endl;
	return out;
}

//Book:
void Book::addNum(const int &num){
	totalNum+=num;
}
void Book::reqBorrow(const BH &bh){
	borrowReq.add(bh);
}
void Book::agrBorrow(const BH &bh){
	borrowReq.del(bh);
	borrowHis.add(bh);
	borrowNum++;
}
void Book::canBorrow(const BH &bh){
	borrowReq.del(bh);
	returnHis.add(bh);
}
void Book::refBorrow(const BH &bh){
	borrowReq.del(bh);
	returnHis.add(bh);
}
void Book::reqReturn(const BH &bh){
	borrowHis.del(bh);
	returnReq.add(bh);
}
void Book::agrReturn(const BH &bh){
	returnReq.del(bh);
	returnHis.add(bh);
	borrowNum--;
}
void Book::canReturn(const BH &bh){
	returnReq.del(bh);
	borrowHis.add(bh);
}
void Book::refReturn(const BH &bh){
	returnReq.del(bh);
	borrowHis.add(bh);
}
int Book::showBorrowReq() const {
	return borrowReq.show();
}
int Book::showBorrowHis() const {
	return borrowHis.show();
}
int Book::showReturnReq() const {
	return returnReq.show();
}
int Book::showReturnHis() const {
	return returnHis.show();
}
string Book::showBorrowReq(const int &num) const {
	return borrowReq.show(num);
}
string Book::showBorrowHis(const int &num) const {
	return borrowHis.show(num);
}
string Book::showReturnReq(const int &num) const {
	return returnReq.show(num);
}
string Book::showReturnHis(const int &num) const {
	return returnHis.show(num);
}
istream &operator >> (istream &in,Book &b){
	in>> b.bid >> b.bname >> b.author >> b.press >> b.totalNum >> b.borrowNum;
	in>> b.borrowReq >> b.borrowHis >> b.returnReq >> b.returnHis;
	return in;
}
ostream &operator << (ostream &out,const Book &b){
	out<< b.bid << "\n" << b.bname << "\n" << b.author << "\n" << b.press << "\n" << b.totalNum << "\n" << b.borrowNum << endl;
	out<< b.borrowReq << b.borrowHis << b.returnReq << b.returnHis;
	return out;
}

//BookList:
BB &BL::operator [] (const string &bid){
	for(int i=0;i<bl.size();i++) if(bl[i].getBid()==bid) return bl[i];
}
BB &BL::operator [] (const int &num){
	return bl[num];
}
bool BL::bidExist(const string &bid) const {
	for(int i=0;i<bl.size();i++) if(bl[i].getBid()==bid) return true;
	return false;
}
void BL::add(const BB &bb){
	bl.push_back(bb);
}
void BL::del(const BB &bb){
	del(bb.getBid());
}
void BL::del(const string &bid){
	for(int i=0;i<bl.size();i++) if(bl[i].getBid()==bid){
		bl.erase(bl.begin()+i);
		return;
	}
}
int BL::show() const {
	cout<< "编号  书籍id  书籍名称  作者  出版社  书籍总数  借出数量" << endl;
	for(int i=0;i<bl.size();i++){
		cout<< i+1 << ".  ";
		bl[i].show();
	}
	return bl.size();
}

QTableModel* BL::Qshow() const {
    QTableModel *model = new QTableModel(QTableModel::Book);

    QVector<QStringList> data;
    for(int i=0;i<bl.size();i++){
        data.append(bl[i].Qshow());
    }

    model->loadData(data);
    return model;
}

QTableModel* BL::Qshow(int rows) const {
    QTableModel *model = new QTableModel(QTableModel::Book);

    QVector<QStringList> data;
    int size;
    if(bl.size() > 10) { size = 10;}
    else size = bl.size();
    for(int i=0;i<size;i++){
        data.append(bl[i].Qshow());
    }

    model->loadData(data);
    return model;
}

string BL::show(const int &num) const {
	bl[num].show();
	return bl[num].getBid();
}
void BL::show(const string &bid) const {
	for(int i=0;i<bl.size();i++) if(bl[i].getBid()==bid){
		bl[i].show();
		return;
	}
}

QStringList BL::Qshow(const string& bid) const {
    for(int i=0;i<bl.size();i++) if(bl[i].getBid()==bid){
        return bl[i].Qshow();
    }
}

QTableModel *BookList::QschBook(const string &bid) const {
    QTableModel *model = new QTableModel(QTableModel::Book);

    QVector<QStringList> data;
    for(int i=0;i<bl.size();i++){
        if(bl[i].match(bid)){
            data.append(bl[i].Qshow());
        }
    }

    model->loadData(data);
    return model;
}

void BL::schBook(const string &s) const {
	cout<< "编号  书籍id  书籍名称  作者  出版社  书籍总数  借出数量" << endl;
	int cnt=0;
	for(int i=0;i<bl.size();i++) if(bl[i].match(s)){
		cout<< ++cnt << ".  ";
		bl[i].show();
	}
}
bool cmpByBorrow(const BB &a, const BB &b){
    return a.getBorrowNum()>b.getBorrowNum();
}
void BL::sortByBorrow(){
    sort(bl.begin(),bl.end(),cmpByBorrow);
}
istream &operator >> (istream &in,BL &bl){
	int num; in>> num;
	while(num--) { BB bb; in>> bb; bl.add(bb); }
	return in;
}
ostream &operator << (ostream &out,const BL &bl){
	out<< bl.size() << endl;
	for(int i=0;i<bl.bl.size();i++) out<< bl.bl[i]; 
	return out;
}
