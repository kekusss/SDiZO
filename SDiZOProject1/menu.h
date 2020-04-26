#pragma once
#include <string>
#include <iostream>
#include "Array.h"
#include "List.h"
#include "Heap.h"

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

	void menuArray();
	void menuList();
	void menuHeap();
	void menuBSTTree();
};

