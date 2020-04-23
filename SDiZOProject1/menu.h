#pragma once
#include <string>
#include <iostream>

using namespace std;

class Menu
{
public:
	char choice;
	string fileName;
	int index, amount, value;

	Menu();
private:
	int mainMenu();
	void displayMenu(string info);

	void menuTable();
	void menuList();
	void menuHeap();
	void menuBSTTree();
};

