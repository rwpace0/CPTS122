/*
Name: Reid Pace
Class: 122
Assignment: PA7
Date: March 29th, 2025
Lab Section: 10
Description: list template for linked list
*/
#include "include.hpp"
#include "Node.hpp"

template <typename T>
class List {
public:
	//constructor
	List();
	//destructor
	~List();

	//inserts node to front of list
	void insertFront(const T& data);
	//checks if list is empty
	bool isEmpty() const;
	//clears list
	void clearList();
	//gets size of list
	int getSize() const;

	//imports and parses input file
	bool importFile(const string& fileName);
	//saves info into an output file
	bool saveFile(const string& fileName) const;

	//getter for head node
	Node<T>* getHead() const;
	//searches for student by id
	Node<T>* findByID(int &id) const;
	//searches for student by name
	Node<T>* findByName(const string& name) const;

private:
	Node<T>* head;
	int size;

	// function to handle the name section of classList
	
};

template <typename T>
List<T>::List() : head(nullptr), size(0) {}


template <typename T>
List<T>::~List() {
	clearList();
}

template <typename T>
void List<T>::insertFront(const T& data) {
	Node<T>* newNode = new Node<T>(data);
	newNode->setNext(head);
	head = newNode;
	size++;
}

template <typename T>
bool List<T>::isEmpty() const {
	return head == nullptr;
}

template <typename T>
void List<T>::clearList() {
	Node<T>* current = head;
	Node<T>* next = nullptr;

	while (current != nullptr) {
		next = current->getNext();
		delete current;
		current = next;
	}

	head = nullptr;
	size = 0;
}

template <typename T>
int List<T>::getSize() const {
	return size;
}

template <typename T>
Node<T>* List<T>::getHead() const {
	return head;
}

template <typename T>
Node<T>* List<T>::findByID(int &id) const {
	Node<T>* current = head;

	while (current != nullptr) {
		if (current->getData().getIdNumber() == id) return current;
		current = current->getNext();
	}
	return nullptr;
}

template <typename T>
Node<T>* List<T>::findByName(const string& name) const {
	Node<T>* current = head;

	while (current != nullptr) {
		if (current->getData().getName() == name) return current;
		current = current->getNext();
	}
	return nullptr;
}

template <typename T>
bool List<T>::importFile(const string& fileName) {
	ifstream file(fileName);
	if (!file.is_open()) return false;

	clearList();

	string line;
	getline(file, line); // skip 1st line

	while (getline(file, line)) {
		stringstream ss(line);
		string token;

		int recordNum=0, id=0;
		string name, email, units, program, level;

		// record
		if (getline(ss, token, ',')) {
			recordNum = stoi(token);
		}
		else {
			continue;
		}

		// id
		if (getline(ss, token, ',')) {
			id = stoi(token);
		}
		else {
			continue;
		}

		// name
		//need to add correct parsing for quoted names to ignore the comma from last,first
		if (getline(ss, token, ','));
		else continue;

		if (getline(ss, token, ',')) {
			name = token;
		}
		else {
			continue;
		}

		// email
		if (getline(ss, token, ',')) {
			email = token;
		}
		else {
			continue;
		}

		// units
		if (getline(ss, token, ',')) {
			units = token;
		}
		else {
			continue;
		}

		// program
		if (getline(ss, token, ',')) {
			program = token;
		}
		else {
			continue;
		}

		// level
		if (getline(ss, token)) {
			level = token;
		}
		else {
			continue;
		}

		T data(recordNum, id, name, email, units, program, level);
		insertFront(data);
	}
	file.close();
	return true;
}

template <typename T>
bool List<T>::saveFile(const string& fileName) const {
	ofstream file(fileName);
	if (!file.is_open()) return false;

	file << ",ID,Name,Email,Units,Program,Level" << endl;

	Node<T>* current = head;
	while (current != nullptr) {
		const T& data = current->getData();

		file << data.getRecordNumber() << ","
			<< data.getIdNumber() << ","
			<< data.getName() << ","
			<< data.getEmail() << ","
			<< data.getUnits() << ","
			<< data.getProgram() << ","
			<< data.getLevel();

		current = current->getNext();

		// newline
		if (current != nullptr) file << endl;
	}
	file.close();
	return true;
}