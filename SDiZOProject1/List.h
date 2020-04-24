#pragma once

#include <String>
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <string>
#include "Clock.h"

using namespace std;

struct Element {
	Element* next, * prev;
	int value;
};

class List
{
private:
	Element *head, *tail;
	int size;

public:
	List();
	~List();

	int getSize();
	void show();
	void readFromFile(string fileName);
	void addElement(int element, int index);
	void remove(int value);
	bool findElement(int value);
	void makeExample(int eSize);
	void makeTests();
};

