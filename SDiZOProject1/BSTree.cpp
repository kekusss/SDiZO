#include "BSTree.h"

BSTree::BSTree() {
	root = NULL;
	size = 0;
}

BSTree::~BSTree() {
	removeTree(root);
}

/*
Zwraca korzen drzewa
*/
Node* BSTree::getRoot() {
	return root;
}

/*
Zwraca rozmiar drzewa
*/
int BSTree::getSize() {
	return size;
}

/*
Wyswietla drzewo
*/
void BSTree::show(string sp, string sn, Node* node) {
	string tmp;
	
	if (node) {
		tmp = sp;
		if (sn == cr) {
			tmp[tmp.length() - 2] = ' ';
		}

		show(tmp + cp, cr, node->rightChild);

		tmp = tmp.substr(0, sp.length() - 2);
		cout << tmp << sn << node->value << endl;

		tmp = sp;
		if (sn == cl) {
			tmp[tmp.length() - 2] = ' ';
		}
		show(tmp + cp, cl, node->leftChild);
	}
}

/*
Sprawdza czy dana wartosc znajduje sie w drzewie
*/
Node* BSTree::findElement(Node* node, int value) {
	while (node && node->value != value) {
		if (value < node->value) {
			node = node->leftChild;
		}
		else {
			node = node->rightChild;
		}
	}
	return node;
}

/*
Wczytuje drzewo z pliku
*/
void BSTree::readFromFile(string fileName) {
	string value;
	string newSize;
	ifstream file(fileName);

	if (file.is_open()) {
		file >> newSize;
		removeTree(root);
		root = nullptr;

		for (int i = 0; i < stoi(newSize); i++) {
			file >> value;
			addElement(stoi(value));
		}
		file.close();
	}
	else {
		cout << "Blad odczytu pliku \n";
	}
}

/*
Usuwa dany fragment drzewa - rekurencyjnie usuwa obie galezie wezla a nastepnie sam wezel
*/
void BSTree::removeTree(Node* node) {
	if (node) {
		removeTree(node->leftChild);
		removeTree(node->rightChild);
		delete(node);
	}
}

/*
Dodaje element do drzewa
*/
void BSTree::addElement(int value) {
	Node* node;
	Node* tmp = new Node();

	tmp->leftChild = tmp->rightChild = NULL;
	tmp->value = value;

	node = root;

	if (!node) { 
		root = tmp; 
		return;
	}

	size++;

	while (true) {
		if (value < node->value) {
			if (!node->leftChild) {
				node->leftChild = tmp;
				break;
			}
			else {
				node = node->leftChild;
			}
		}
		else {
			if (!node->rightChild) {
				node->rightChild = tmp;
				break;
			}
			else {
				node = node->rightChild;
			}
		}
	}
	tmp->parent = node;

	//balansowanie drzewa po dodaniu elementu
	rebalance();
}

/*
Usuwa element z drzewa
*/
Node* BSTree::removeElement(int value) {
	Node* node = removeNode(findElement(root, value));
	size--;
	return node;

	//balansowanie drzewa po wykonaniu usuwania
	rebalance();
}

/*
Zwraca nastepnik
*/
Node* BSTree::next(Node* node) {
	Node* tmp;

	if (node) {
		if (node->rightChild) {
			return minNode(node->rightChild);
		}
		else {
			tmp = node->parent;
			while (tmp && (tmp == tmp->rightChild)) {
				node = tmp;
				tmp = tmp->parent;
			}
			return tmp;
		}
	}
	return node;
}

/*
Zwraca poprzednik
*/
Node* BSTree::before(Node* node) {
	Node* tmp;

	if (node) {
		if (node->leftChild) {
			return maxNode(node->leftChild);
		}
		else {
			tmp = node->parent;
			while (tmp && (node == tmp->leftChild)) {
				node = tmp;
				tmp = tmp->parent;
			}
			return tmp;
		}
	}
	return node;
}

/*
Zwraca najmniejszy wezel
*/
Node* BSTree::minNode(Node* node) {
	if (node) {
		while (node->leftChild) {
			node = node->leftChild;
		}
	}
	return node;
}

/*
Zwraca najwiekszy wezel
*/
Node* BSTree::maxNode(Node* node) {
	if (node) {
		while (node->rightChild) {
			node = node->rightChild;
		}
	}
	return node;
}

/*
Usuwa wezel
*/
Node* BSTree::removeNode(Node* node) {
	Node* tmp1, * tmp2;

	if (node) {
		if (!node->leftChild || !node->rightChild) {
			tmp1 = node;
		}
		else {
			tmp1 = next(node);
		}

		if (tmp1->leftChild) {
			tmp2 = tmp1->leftChild;
		}
		else {
			tmp2 = tmp1->rightChild;
		}

		if (tmp2) {
			tmp2->parent = tmp1->parent;
		}

		if (!tmp1->parent) {
			root = tmp2;
		}
		else if (tmp1 == tmp1->parent->leftChild) {
			tmp1->parent->leftChild = tmp2;
		}
		else {
			tmp1->parent->rightChild = tmp2;
		}

		if (tmp1 != node) {
			node->value = tmp1->value;
		}

		delete tmp1;
	}
	return node;
}

/*
Zwrot w prawo
*/
Node* BSTree::turnRight(int value) {
	if (findElement(root, value) != nullptr) {
		rotateRight(findElement(root, value));
		return findElement(root, value);
	}
	else {
		return nullptr;
	}
}

/*
Zwrot w lewo
*/
Node* BSTree::turnLeft(int value) {
	if (findElement(root, value) != nullptr) {
		rotateLeft(findElement(root, value));
		return findElement(root, value);
	}
	else {
		return nullptr;
	}
}

/*
obrot w lewo
*/
void BSTree::rotateLeft(Node* node) {
	Node* node2 = node->rightChild, * p = node->parent;

	if (node2) {
		node->rightChild = node2->leftChild;
		if (node->rightChild) {
			node->rightChild->parent = node;
		}

		node2->leftChild = node;
		node2->parent = p;
		node->parent = node2;

		if (p) {
			if (p->leftChild == node) {
				p->leftChild = node2;
			}
			else {
				p->rightChild = node2;
			}
		}
		else {
			root = node2;
		}
	}
}

/*
obrot w prawo
*/
void BSTree::rotateRight(Node* node) {
	Node* node2 = node->leftChild, * p = node->parent;

	if (node2) {
		node->leftChild = node2->rightChild;
		if (node->leftChild) {
			node->leftChild->parent = node;
		}

		node2->rightChild = node;
		node2->parent = p;
		node->parent = node2;

		if (p) {
			if (p->leftChild == node) {
				p->leftChild = node2;
			}
			else {
				p->rightChild = node2;
			}
		}
		else {
			root = node2;
		}
	}
}

/*
algorytm DSW - balansowanie drzewa
*/
void BSTree::rebalance() {
	Node* node;
	unsigned nodeAmount, spinAmount, i;

	node = root;
	nodeAmount = 0;

	while (node) {
		if (node->leftChild) {
			rotateRight(node);
			node == node->parent;
		}
		else {
			nodeAmount++;
			node = node->rightChild;
		}
	}

	// poczatkowa liczba obrotow
	spinAmount = 1 - log2(nodeAmount + 1) + nodeAmount;

	node = root;

	for (i = 0; i < spinAmount; i++) {
		rotateLeft(node);
		node = node->parent->rightChild;
	}

	nodeAmount = nodeAmount - spinAmount;

	while (nodeAmount > 1) {
		nodeAmount >>= 1;
		node = root;

		for (i = 0; i < nodeAmount; i++) {
			rotateLeft(node);
			node = node->parent->rightChild;
		}
	}
}

/*
tworzy przykladowe drzewo
*/
void BSTree::makeExample(int size) {
	srand(time(NULL));

	//zerowanie drzewa
	removeTree(root);
	root = nullptr;
	this->size = 0;

	for (int i = 0; i < size; i++) {
		addElement(rand() % 1000);
	}
}

/*
przeprowadza testy
*/
void BSTree::makeTests() {
	Clock clock;
	int elements = 1;
	for (int i = 1; i < 8; i++) {
		makeExample(elements);
		cout << endl << elements << " elementow: \n";

		clock.beginTest();
		findElement(root,10);
		clock.endTest();
		cout << " | search: ";
		clock.displayTime();

		clock.beginTest();
		addElement(10);
		clock.endTest();
		cout << " | add: ";
		clock.displayTime();

		clock.beginTest();
		removeElement(10);
		clock.endTest();
		cout << " | remove: ";
		clock.displayTime();
		elements *= 10;
	}
}

//oblicza szybko wartoœæ log2
unsigned log2(unsigned x){
	unsigned y = 1;
	while ((x >>= 1) > 0) y <<= 1;
	return y;
}