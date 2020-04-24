#include "List.h"

List::List() {
	srand(time(NULL));
	size = 0;
	head = NULL;
	tail = NULL;
}

List::~List() {
	while (head!=nullptr) {
		remove(0);
	}
	size = 0;
}

/*
Zwraca rozmiar listy
*/
int List::getSize() {
	return size;
}

/*
Wyœwietla listê
*/
void List::show() {
	Element* element = new Element();

	if (!head) {
		cout << "Lista jest pusta \n";
		return;
	}

	element = head;

	while (element) {
		cout << element->value << " ";
		element = element->next;
	}
	cout << endl;
}

/*
Wczytuje liste z pliku w zadanym formacie
*/
void List::readFromFile(string fileName) {
	string value, listSize;
	ifstream file(fileName);
	if (file.is_open()) {
		file >> listSize;
		Element* element;

		while (head != nullptr) {
			element = head->next;
			delete head;
			head = element;
		}

		head = tail = NULL;
		size = 0;

		if (file.fail()) {
			cout << "Blad odczytu rozmiaru \n";
			return;
		}

		for (int i = 0; i < stoi(listSize); i++) {
			file >> value;
			if (file.fail()) {
				cout << "Blad odczytu danych \n";
				break;
			}
			addElement(stoi(value), i);
		}
		file.close();
	}
	else {
		cout << "Blad otwarcia pliku \n";
	}
}

/*
Dodaje wartosc w dowolne miejsce listy
*/
void List::addElement(int element, int index) {
	bool exist=false;
	Element* newElement = new Element;
	size++;
	if (index == 0 || size==1) {
		newElement->prev = NULL;
		newElement->next = head;
		newElement->value = element;
		if (head != NULL) head->prev = newElement;
		if (tail == NULL) tail = newElement;
		head = newElement;
	}
	else if (index == size-1) {
		newElement->prev = tail;
		newElement->next = NULL;
		newElement->value = element;
		tail->next = newElement;
		tail = newElement;
	}
	else if(index<0 || index >=size){
		cout << "Niepoprawny indeks \n";
	}
	else {
		Element* tmp = head;
		for (int i=0; tmp; tmp = tmp->next, i++){
			if (i == index){
				newElement->value = element;
				newElement->prev = tmp->prev;
				newElement->next = tmp;
				tmp->prev->next = newElement;
				tmp->prev = newElement;
				break;
			}
		}
	}
	return;
}

/*
Usuwa element z listy
*/
void List::remove(int value) {
	Element* tmp = head;
	for (int i = 0; i<size; i++){
		if (tmp->value == value) {
			if (tmp->prev && tmp->next){
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			else if (!tmp->prev){
				head = tmp->next;
				tmp->next->prev = NULL;
			}
			else if (!tmp->next){
				tail = tmp->prev;
				tmp->prev->next = NULL;
			}
			size--;
		}
		tmp = tmp->next;
	}
}

/*
Sprawdza czy element o danej wartoœci istnieje na liscie
*/
bool List::findElement(int value) {
	Element* tmp = head;
	for (int i = 0; i < size; i++){
		if (tmp->value == value) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

/*
Generuje losowa liste
*/
void List::makeExample(int eSize) {
	head = tail = NULL;
	size = 0;
	for (int i = 0; i < eSize; i++){
		this->addElement(rand() % 1000, 0);
	}
}

/*
Przeprowadza testy
*/
void List::makeTests() {
	Clock clock;
	makeExample(1);
	addElement(640000, 1);

	clock.beginTest();
	findElement(640000);
	clock.endTest();

	cout << "1 element: ";
	clock.displayTime();
}