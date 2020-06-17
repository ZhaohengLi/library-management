#include "Library.h"
#include "Console.h"
#include "Menu.h"
#include <bits/stdc++.h>
using namespace std;

Console con;
Library lib;
Menu m(&lib);

int main(){
	m.start();
	return 0;
}
