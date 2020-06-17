#include "Book.h"
#include "Reader.h"
#include "History.h"
#include "Library.h"
#include "Functions.h"
#include <bits/stdc++.h>
#include <QApplication>
#define LO Library::Operation
using namespace std;

#include <QDebug>

//Library.cpp
//Library:
void Library::init(){
    data.init();
    mop.init();
}

//Lirary::Operation:
void LO::sortByBorrow() const{
    data->bl.sortByBorrow();
}
int LO::showBook() const {
	return data->bl.show();
}

QTableModel* LO::QshowBook() const {
    return data->bl.Qshow();
}

QTableModel* LO::QshowBook(int rows) const {
    return data->bl.Qshow(rows);
}

int LO::showReader() const {
	return data->rl.show();
}

QTableModel *LO::QshowReader() const {
    return data->rl.Qshow();
}

int LO::showHistory() const {
	return data->hl.show();
}
string LO::showBook(const int &num) const {
	return data->bl.show(num);
}
string LO::showReader(const int &num) const {
	return data->rl.show(num);
}
string LO::showHistory(const int &num) const {
	return data->hl.show(num);
}
void LO::showBook(const string &bid) const {
	data->bl.show(bid);
}

QStringList LO::QshowBook(const string &bid) const {
    return data->bl.Qshow(bid);
}

void LO::showReader(const string &rid) const {
	data->rl.show(rid);
}

QStringList LO::QshowReader(const string &rid) const {
    return data->rl.Qshow(rid);
}

void LO::showHistory(const string &hid) const {
	data->hl.show(hid);
}
void LO::schBook(const string &s) const {
	data->bl.schBook(s);
}

QTableModel *Library::Operation::QschBook(const string &s) const {
    return data->bl.QschBook(s);
}

bool LO::bidExist(const string &bid){
	return data->bl.bidExist(bid);
}
bool LO::ridExist(const string &rid){
	return data->rl.ridExist(rid);
}
