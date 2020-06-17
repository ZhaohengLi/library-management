#include "Console.h"
#include <bits/stdc++.h>
#include <QApplication>
#include <QStandardPaths>
using namespace std;

//Console.cpp
void Console::mkdir(const string &s){
    /*QString cmd = "mkdir "+ QApplication::applicationDirPath() + "/" + QString::fromStdString(s);
    qDebug() << cmd;
    system(cmd.toStdString().c_str());*/

    string cmd="mkdir "+s;
    system(cmd.c_str());
}
void Console::rmdir(const string &s){
    /*QString cmd = "rm -r "+ QApplication::applicationDirPath() + "/" + QString::fromStdString(s);
    system(cmd.toStdString().c_str());*/

    string cmd="rm -r "+s;
    system(cmd.c_str());
}
string Console::bdir(const string &s){
    QString path = QApplication::applicationDirPath() + "/data/book/"+ QString::fromStdString(s) + "/";
    return path.toStdString();

    //string a="data/book/"+s;
    //return a+"/";
}
string Console::rdir(const string &s){
    QString path = QApplication::applicationDirPath() + "/data/reader/"+ QString::fromStdString(s) + "/";
    return path.toStdString();

    //string a="data/reader/"+s;
    //return a+"/";
}
string Console::hdir(const string &s){
    QString path = QApplication::applicationDirPath() + "/data/history/"+ QString::fromStdString(s) + "/";
    return path.toStdString();

    //string a="data/history/"+s;
    //return a+"/";
}
