#include "Book.h"
#include "Reader.h"
#include "History.h"
#include "Library.h"
#include "Functions.h"
#include <bits/stdc++.h>
#define LO Library::Operation
using namespace std;

//Library.cpp
//Lirary::Operation:
int LO::showBook() const {
	return data->bl.show();
}
int LO::showReader() const {
	return data->rl.show();
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
void LO::showReader(const string &rid) const {
	data->rl.show(rid);
}
void LO::showHistory(const string &hid) const {
	data->hl.show(hid);
}
void LO::schBook(const string &s) const {
	data->bl.schBook(s);
}
bool LO::bidExist(const string &bid){
	return data->bl.bidExist(bid);
}
bool LO::ridExist(const string &rid){
	return data->rl.ridExist(rid);
}
