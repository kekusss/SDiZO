#include "List.h"
#include<iostream>
#include<time.h>
#include <fstream>
#include<string>

List::List() {
	size = 0;
	head = NULL;
	tail = NULL;
}

List::~List() {
	while (head) {
		//removeFirst();
	}
	size = 0;
}

int List::getSize() {
	return size;
}

/*void List::show() {
	if (getSize()) {
		int *
	}
}*/