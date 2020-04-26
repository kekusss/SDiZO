#include "Heap.h"

Heap::Heap(int maxSize) {
	this->maxSize = maxSize;
	size = 0;
	array = new int[maxSize];
}

Heap::~Heap() {
	delete[] array;
}

int Heap::parent(int index) {
	return (index - 1) / 2;
}

int Heap::leftChild(int index) {
	return 2 * index + 1;
}

int Heap::rightChild(int index) {
	return 2 * (index + 1);
}

/*
Zamienia miejscami 2 elementy
*/
void Heap::swap(int* elem1, int* elem2) {
	int tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

/*
Wyswietla kopiec w formie piramidki
*/
void Heap::show() {
	int lvl = 1;
	if (size == 0) {
		cout << "Kopiec jest pusty";
		return;
	}

	cout << array[0] << " \n";

	for (int i = 1; i < size; i++) {
		cout << array[i] << " ";
		if (i == lvl + 1) {
			cout << endl;
			lvl = (2 * i) + 1;
		}
	}

	cout << endl;
}

/*
Sprawdza czy element jest na kopcu
*/
int Heap::findElement(int value) {
	for (int i = 0; i < size; i++) {
		if (array[i] == value) { return i; }
	}
	return -1;
}

/*
Wczytuje stertê z pliku
*/
void Heap::readFromFile(string fileName) {
	int tmp;
	ifstream file(fileName);

	if (file.is_open()) {
		file >> tmp;

		if (file.fail()) {
			cout << "Blad odczytu - bledny rozmiar \n";
			return;
		}

		while (file >> tmp) {
			add(tmp);
		}

		file.close();
	}
	else{
		cout << "Blad otwarcia pliku \n";
	}
}

/*
dodaje element do kopca
*/
void Heap::add(int value) {
	if (size == maxSize) {
		cout << "Nie mozna wstawic nowego elementu, osiagnieto maxymalny rozmiar kopca \n";
		return;
	}

	int index = size;
	size++;
	
	array[index] = value;

	//naprawia kopiec po dodaniu elementu
	fixUp(index);
}

/*
Usuwa element z kopca
*/
void Heap::remove(int value) {
	int index = findElement(value);

	if (index < 0) {
		cout << "Nie ma elementu o takiej wartosci \n";
		return;
	}
	
	size--;
	swap(&array[index], &array[size]);
	fixDown(index);

}

/*
naprawia kopiec w dó³
*/
void Heap::fixDown(int index) {
	int leftC = leftChild(index);
	int rightC = rightChild(index);
	int parentL = index;

	if (leftC<size && array[leftC]>array[index]) { parentL = leftC; }
	if (rightC<size && array[rightC]>array[parentL]) { parentL = rightC; }
	if (parentL != index) {
		swap(&array[index], &array[parentL]);
		fixDown(parentL);
	}
}

/*
naprawia kopiec w górê
*/
void Heap::fixUp(int index) {
	if(index >= 0 && parent(index) >=0 && array[parent(index)] < array[index]){
		swap(&array[index], &array[parent(index)]);
		fixUp(parent(index));
	}
}

/*
Tworzy przykladowy, losowy kopiec o danym rozmiarze
*/
void Heap::makeExample(int size, int maxSize) {
	this->maxSize = maxSize;
	this->size = 0;
	array = new int[maxSize];

	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		add(rand() % 1000);
	}
}

/*
Przeprowadza testy
*/
void Heap::makeTests() {
	Clock clock;
	makeExample(1,1);
	add(640000);

	clock.beginTest();
	findElement(640000);
	clock.endTest();

	cout << "1 element: ";
	clock.displayTime();
}