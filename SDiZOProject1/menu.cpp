#include "Menu.h"

Menu::Menu() {
	mainMenu();
}

/*
Glowne menu
*/
int Menu::mainMenu() {
	do {
		cout << endl;
		cout << "==== MENU GLOWNE ===" << endl;
		cout << "1.Tablica" << endl;
		cout << "2.Lista" << endl;
		cout << "3.Kopiec" << endl;
		cout << "4.Drzewo BST" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "Podaj opcje: ";
		cin >> choice;

		system("cls"); // czyœci ekran konsoli

		switch (choice) {
		case '1':
			menuArray();
			break;

		case '2':
			menuList();
			break;

		case '3':
			menuHeap();
			break;

		case '4':
			menuBSTTree();
			break;
		case '0':
			system("pause");
			return 0;
			break;
		}
		system("cls");
		choice = 0; // umo¿liwia kontynuacjê pêtli po powrocie z "podmenu"
	} while (choice != '0');
	return 0;
}

/*
podmenu z mozliwymi akcjami dla kazdej struktury
*/
void Menu::displayMenu(string info) {
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}

/*
Zawiera akcje wykonywane po wybraniu danej opcji w menu, dla wszystkich struktur
*/
#pragma region AllStructuresMenus

void Menu::menuArray() {
	Array array;

	do {
		displayMenu("--- TABLICA ---");
		cin >> choice;
		system("cls");

		switch (choice) {
		case '1': //wczytywanie z pliku
			cout << "Podaj nazwe pliku:";
			cin >> fileName;
			array.readFromFile(fileName);
			array.show();
			break;

		case '2': {//usuwanie elementu
			cout << "Podaj index elementu:";
			cin >> index;
			array.remove(index);
			array.show();
			break;
		}
		case '3': //dodawanie elementu
			cout << "Podaj index: ";
			cin >> index;
			cout << "Podaj wartosc: ";
			cin >> value;
			array.addElement(value, index);
			array.show();
			break;

		case '4': //sprawdzanie czy istnieje w tablicy
			cout << "Podaj wartosc ktora ma byc sprawdzona: ";
			cin >> value;
			if (array.findElement(value)) {
				cout << "Podana wartosc jest w tablicy \n";
			}
			else {
				cout << "Podanej wartosci nie ma w tablicy \n";
			}
			array.show();
			break;

		case '5': //generowanie tablicy
			cout << "Podaj ilosc elementow nowej tablicy:";
			cin >> amount;

			array.makeExample(amount);
			array.show();
			break;

		case '6': // wyœwietlanie
			array.show();
			break;

		case '7': // test
			array.makeTests();
			break;
		}

	} while (choice != '0');
}

void Menu::menuList() {
	List list = List();

	do {
		displayMenu("--- LISTA ---");
		cin >> choice;
		system("cls");

		switch (choice) {
		case '1': // wczytywanie listy z pliku
			cout << "Podaj nazwe pliku:";
			cin >> fileName;
			list.readFromFile(fileName);
			list.show();
			break;

		case '2': {// usuwanie elementu listy
			cout << "Podaj wartosc ktora chcesz usunac:";
			cin >> value;
			list.remove(value);
			list.show();
			break;
		}
		case '3': // dodawanie elementu do listy
			cout << "Podaj index: ";
			cin >> index;
			cout << "Podaj wartosc: ";
			cin >> value;
			list.addElement(value, index);
			list.show();
			break;

		case '4': // sprawdza czy szukana wartosc znajduje sie na liscie
			cout << "Podaj szukana wartosc:";
			cin >> value;
			if (list.findElement(value)) {
				cout << "Podana wartosc znajduje sie na liscie \n";
			}
			else {
				cout << "Podana wartosc nie znajduje sie na liscie \n";
			}
			list.show();
			break;

		case '5': // generowanie losowej listy
			cout << "Podaj ilosc elementow listy:";
			cin >> amount;
			list.makeExample(amount);
			list.show();
			break;

		case '6': // wyswietlanie listy
			list.show();
			break;

		case '7':
			list.makeTests();
			break;
		}
	} while (choice != '0');
}

void Menu::menuHeap() {
	Heap heap = Heap(100000);
	do {
		displayMenu("--- KOPIEC ---");

		cin >> choice;
		system("cls");

		switch (choice) {
		case '1': // wczytywanie kopca z pliku
			cout << "Podaj nazwe pliku:";
			cin >> fileName;
			heap.readFromFile(fileName);
			heap.show();
			break;

		case '2': {// usuwanie elementu z kopca
			cout << "Podaj wartosc ktora chcesz usunac:";
			cin >> value;
			heap.remove(value);
			heap.show();
			break;
		}
		case '3': // dodawanie elementu do kopca
			cout << "Podaj wartosc: ";
			cin >> value;
			heap.add(value);
			heap.show();
			break;

		case '4': // sprawdza czy szukana wartosc znajduje sie w kopcu
			cout << "Podaj szukana wartosc:";
			cin >> value;
			if (heap.findElement(value) != -1) {
				cout << "Podana wartosc znajduje sie w kopcu \n";
			}
			else {
				cout << "Podana wartosc nie znajduje sie w kopcu \n";
			}
			heap.show();
			break;

		case '5': // generowanie losowej listy
			cout << "Podaj ilosc elementow kopca:";
			cin >> amount;
			heap.makeExample(amount,100000);
			heap.show();
			break;

		case '6': // wyswietlanie kopca
			heap.show();
			break;

		case '7': // testy
			heap.makeTests();
			break;
		}
	} while (choice != '0');
}

void Menu::menuBSTTree() {

	BSTree bst;

	bst.cr = bst.cl = bst.cp = "  ";
	bst.cr[0] = 218; bst.cr[1] = 196;
	bst.cl[0] = 192; bst.cl[1] = 196;
	bst.cp[0] = 179;

	do {
		displayMenu("--- DRZEWO BST ---\n8.Poziomowanie DSW");

		cin >> choice;
		system("cls");

		switch (choice) {
		case '1': // wczytywanie drzewa z pliku
			cout << "Podaj nazwe pliku:";
			cin >> fileName;
			bst.readFromFile(fileName);
			bst.show("  ", "==", bst.getRoot());
			break;

		case '2': {// usuwanie elementu z drzewa
			cout << "Podaj wartosc ktora chcesz usunac:";
			cin >> value;
			bst.removeElement(value);
			bst.show("  ", "==", bst.getRoot());
			break;
		}
		case '3': // dodawanie elementu do drzewa
			cout << "Podaj wartosc: ";
			cin >> value;
			bst.addElement(value);
			bst.show("  ", "==", bst.getRoot());
			break;

		case '4': // sprawdza czy szukana wartosc znajduje sie w drzewie
			cout << "Podaj szukana wartosc:";
			cin >> value;
			if (bst.findElement(bst.getRoot(), value) != nullptr) {
				cout << "Podana wartosc znajduje sie w drzewie \n";
			}
			else {
				cout << "Podana wartosc nie znajduje sie w drzewie \n";
			}
			bst.show("  ", "==", bst.getRoot());
			break;

		case '5': // generowanie losowego drzewa
			cout << "Podaj ilosc elementow drzewa:";
			cin >> amount;
			bst.makeExample(amount);
			bst.show("  ", "==", bst.getRoot());
			break;

		case '6': // wyswietlanie drzewa
			bst.show("  ","==",bst.getRoot());
			break;

		case '7': // testy
			bst.makeTests();
			break;

		case '8':
			bst.rebalance();
			bst.show("  ", "==", bst.getRoot());
			break;
		}
	} while (choice != '0');
}

#pragma endregion
