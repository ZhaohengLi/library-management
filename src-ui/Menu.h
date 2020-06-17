#ifndef MENU_H
#define MENU_H

#include "Library.h"
#include <bits/stdc++.h>
using namespace std;

//Menu.h
class Menu{
	Library *lib;
	class SubMenu{
		Library *lib;
	protected:
		Library::Operation *op;
		void showBook() const;
		void showReader() const;
		void schBook() const;
	public:
		SubMenu(Library *l):lib(l),op(&(l->op)){}
	};
	class ManagerMenu : public SubMenu{
		Library::ManagerOperation *mop;
	public:
		ManagerMenu(Library *l):SubMenu(l){ mop=&(l->mop); }
		void login() const;
	private:
		void start() const;
		void addBook() const;
		void addOldBook() const;
		void addNewBook() const;
		void addReader() const;
		void delBook() const;
		void delReader() const;
		void agrBorrow(const string &hid) const;
		void refBorrow(const string &hid) const;
		void agrReturn(const string &hid) const;
		void refReturn(const string &hid) const;
		void dealRequest() const;
		void dealBorrow() const;
		void dealReturn() const;
		void changeMpasswd() const;
		void schReader() const;
		void schHistory() const;
	};
	class ReaderMenu : public SubMenu{
		Library::ReaderOperation *rop;
	public:
		ReaderMenu(Library *l):SubMenu(l){ rop=&(l->rop); }
		void login() const;
	private:
		void start() const;
		void borrowBook() const;
		void returnBook() const;
		void reqBorrow() const;
		void reqReturn() const;
		void canBorrow() const;
		void canReturn() const;
		void changeRpasswd() const;
	};
public:
	ManagerMenu mm;
	ReaderMenu rm;
	Menu(Library *_lib):lib(_lib),mm(ManagerMenu(_lib)),rm(ReaderMenu(_lib)){}
	void start() const ;
};

#endif
