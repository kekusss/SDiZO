#include "Menu.h"

Menu::Menu() {
	mainMenu();
}

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
			menuTable();
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
}


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

void Menu::menuTable() {
	//Table table;
	do {
		displayMenu("--- TABLICA ---");
		cin >> choice;
		system("cls");
		switch (choice) {
		case '1': //tutaj wczytywanie  tablicy z pliku
			cout << "Podaj nazwe pliku:";
			cin >> fileName;
			break;

		case '2': {//tutaj generowanie  tablicy
			cout << "Podaj ilosc elementow tablicy:";
			cin >> amount;
			break;
		}
		case '3': //tutaj dodawanie elemetu do tablicy
			cout << "Podaj index: ";
			cin >> index;
			cout << "Podaj wartosc: ";
			cin >> value;
			break;

		case '4': //tutaj usuwanie elemenu z tablicy
			cout << "Podaj index:";
			cin >> index;

			break;

		case '5': //tutaj znajdowanie elemetu w tablicy
			cout << "Podaj wartosc: ";
			cin >> value;
			if (1)
				cout << "Podana wartosc jest w tablicy" << endl;
			else
				cout << "Podanej wartosci NIE ma w tablicy" << endl;
			break;

		case '6':
			break;

		case '7':
			break;
		}

	} while (choice != '0');
}

void Menu::menuList() {
	do {
		displayMenu("--- LISTA ---");

		cin >> choice;
		system("cls");

		switch (choice) {
		case '1': //tutaj wczytywanie  tablicy z pliku
			cout << "Podaj nazwe pliku:";
			cin >> fileName;
			break;

		case '2': {//tutaj generowanie  tablicy
			cout << "Podaj ilosc elementow tablicy:";
			cin >> amount;
			break;
		}
		case '3': //tutaj dodawanie elemetu do tablicy
			cout << "Podaj index: ";
			cin >> index;
			cout << "Podaj wartosc: ";
			cin >> value;
			break;

		case '4': //tutaj usuwanie elemenu z tablicy
			cout << "Podaj index:";
			cin >> index;

			break;

		case '5': //tutaj znajdowanie elemetu w tablicy
			cout << "Podaj wartosc: ";
			cin >> value;
			if (1)
				cout << "Podana wartosc jest w tablicy" << endl;
			else
				cout << "Podanej wartosci NIE ma w tablicy" << endl;
			break;

		case '6':
			break;

		case '7':
			break;
		}
	} while (choice != '0');
}

void Menu::menuHeap() {
	do {
		displayMenu("--- KOPIEC ---");

		cin >> choice;
		system("cls");

		switch (choice) {
		case '1': //tutaj wczytywanie  tablicy z pliku
			cout << "Podaj nazwe pliku:";
			cin >> fileName;
			break;

		case '2': {//tutaj generowanie  tablicy
			cout << "Podaj ilosc elementow tablicy:";
			cin >> amount;
			break;
		}
		case '3': //tutaj dodawanie elemetu do tablicy
			cout << "Podaj index: ";
			cin >> index;
			cout << "Podaj wartosc: ";
			cin >> value;
			break;

		case '4': //tutaj usuwanie elemenu z tablicy
			cout << "Podaj index:";
			cin >> index;

			break;

		case '5': //tutaj znajdowanie elemetu w tablicy
			cout << "Podaj wartosc: ";
			cin >> value;
			if (1)
				cout << "Podana wartosc jest w tablicy" << endl;
			else
				cout << "Podanej wartosci NIE ma w tablicy" << endl;
			break;

		case '6':
			break;

		case '7':
			break;
		}
	} while (choice != '0');
}

void Menu::menuBSTTree() {
	do {
		displayMenu("--- DRZEWO BST ---");

		cin >> choice;
		system("cls");

		switch (choice) {
		case '1': //tutaj wczytywanie  tablicy z pliku
			cout << "Podaj nazwe pliku:";
			cin >> fileName;
			break;

		case '2': {//tutaj generowanie  tablicy
			cout << "Podaj ilosc elementow tablicy:";
			cin >> amount;
			break;
		}
		case '3': //tutaj dodawanie elemetu do tablicy
			cout << "Podaj index: ";
			cin >> index;
			cout << "Podaj wartosc: ";
			cin >> value;
			break;

		case '4': //tutaj usuwanie elemenu z tablicy
			cout << "Podaj index:";
			cin >> index;

			break;

		case '5': //tutaj znajdowanie elemetu w tablicy
			cout << "Podaj wartosc: ";
			cin >> value;
			if (1)
				cout << "Podana wartosc jest w tablicy" << endl;
			else
				cout << "Podanej wartosci NIE ma w tablicy" << endl;
			break;

		case '6':
			break;

		case '7':
			break;
		}
	} while (choice != '0');
}
