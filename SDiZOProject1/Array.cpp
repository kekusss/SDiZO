#include "Array.h"

Array::Array() {
	elementPtr = new int[0];
	size = 0;
}

Array::~Array() {
	delete[] elementPtr;
	elementPtr = nullptr;
}

/*
Zwraca rozmiar tablicy
*/
int Array::getSize() {
	return size;
}

/*
Wyœwietlenie wszystkich elementów tablicy
*/
void Array::show() {
	if (size == 0) {
		cout << "Brak elementow w tablicy \n";
		return;
	}

	for (int i = 0; i < size; i++) {
		cout << elementPtr[i] << " ";
	}
	cout << endl;
}

/*
Wczytuje tablicê z pliku
*/
void Array::readFromFile(string fileName) {
	string element;
	string newSize;
	ifstream file(fileName);

	if (file.is_open()) {
		file >> newSize;

		delete elementPtr;
		size = stoi(newSize);
		elementPtr = new int[size];

		if (file.fail()) {
			cout << "Blad odczytu - bledny rozmiar \n";
		}
		else {
			for (int i = 0; i < size; i++) {
				file >> element;
				if (file.fail()) {
					cout << "Blad odczytu danych \n";
					break;
				}
				else {
					elementPtr[i] = stoi(element);
				}
			}
			file.close();
		}
	}
	else {
		cout << "Blad otwarcia pliku \n";
	}
}

/*
Dodaje element do tablicy na jej poczatek
*/
void Array::addElementFirst(int element) {
	size++;
	int* tmpPtr = new int[size];

	for (int i = 0; i < size-1; i++) {
		tmpPtr[i+1] = elementPtr[i];
	}

	delete[] elementPtr;
	elementPtr = tmpPtr;
	elementPtr[0] = element;
}

/*
Dodaje element na sam koniec tablicy
*/
void Array::addElementLast(int element) {
	size++;
	int* tmpPtr = new int[size];

	for (int i = 0; i < size-1; i++) {
		tmpPtr[i] = elementPtr[i];
	}

	delete[] elementPtr;
	elementPtr = tmpPtr;
	elementPtr[size-1] = element;
}

/*
Dodaje element w dowolnym mijescu tablicy
*/
void Array::addElement(int element, int index) {

	if (index == 0) {
		addElementFirst(element);
		return;
	}
	else if (index == size) {
		addElementLast(element);
		return;
	}
	else if (index < 0 || index > size) {
		cout << "Niepoprawna wartosc indeksu" << endl;
		return;
	}

	size++;
	int* tmpPtr = new int[size];

	for(int i = 0; i < size-1; i++){
		tmpPtr[i] = elementPtr[i];
	}

	for (int i=size-1; i > index; i--) {
		tmpPtr[i] = tmpPtr[i-1];
	}

	delete[] elementPtr;
	tmpPtr[index] = element;
	elementPtr = tmpPtr;
}

/*
Usuwa element z dowolnego miejsca w tablicy
*/
void Array::remove(int index) {

	if (size == 0) {
		return;
	}
	if (index >= size || index < 0) {
		cout << "Indeks wykracza poza tablice." << endl;
		return;
	}

	for (int j=index; j < size-1; j++){
		elementPtr[j] = elementPtr[j + 1];
	}

	size--;
	int* tmpPtr = new int[size];

	for (int j=0; j<size; j++){
		tmpPtr[j] = elementPtr[j];
	}

	delete[] elementPtr;
	elementPtr = tmpPtr;
}

/*
Sprawdza czy wartoœæ znajduje siê w tablicy
*/
bool Array::findElement(int value){
	int index = 0;
	bool found = false;
	while ((!found) && (index < size)) {
		if (value == elementPtr[index]) {
			return true;
		}
		else {
			index++;
		}
	}
	return false;

}

void Array::makeExample(int eSize){
	srand(time(NULL));
	delete[]elementPtr;
	elementPtr = nullptr;
	size = 0;

	elementPtr = new int[eSize];
	size = eSize;
	for (int i = 0; i < eSize; i++){
		elementPtr[i] = rand() % 1000;
	}
}