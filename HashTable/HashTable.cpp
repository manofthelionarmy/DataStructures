#include <iostream>

using namespace std; 


class Node{
private:
	int key; 
	int value; 
	Node * next; 
public: 
	Node(int key, int value){
		this->key = key; 
		this->value = value; 
	}
	friend class LinkedList; 
	friend class HashTable; 
};

class LinkedList{
private:
	Node * head; 
	Node * tail; 

public:
	LinkedList(){
		head = NULL; 
		tail = NULL; 
	}
	~LinkedList(){

	}

	friend class HashTable;  

	bool isEmpty(); 

	void addNode(Node * n); 

	void removeNode(int& value); 

	void clear(); 
};

bool LinkedList::isEmpty(){
	return head == NULL && tail == NULL; 
}

void LinkedList::addNode(Node *n){
	if(isEmpty()){
		head = n; 
		tail = head; 
		return; 
	}
	else{
		tail->next = n; 
		tail = tail->next; 
		return; 
	}
}
void LinkedList::removeNode(int& value){

	Node * temp = head; 

	while(temp != NULL){
		if(temp->value == value){

			cout << "Found value " << value << " at key " << temp->key << ". Successfully deleted." << endl; 

			head = temp->next; 
			temp->next = NULL; 

			delete temp; 

			return; 
		}
		else{
			temp = temp->next; 
		}
	}

	cout << "Value doesn't exist." << endl; 
}

void LinkedList::clear(){

	if(isEmpty()){
		return; 
	}
	else{

		while(head != NULL){
			Node * temp = head; 

			head = head->next; 

			if(head == NULL){
				tail = NULL; 
			}

			temp->next = NULL;
			delete temp; 
		}
	}

	return; 
}
class HashTable{
private:
	LinkedList ** hashtable;
	int length;  
public:
	HashTable(int m){

		length = m; 
		LinkedList ** hashtable = new LinkedList*[length]; 

		for(int i = 0; i < length; ++i){
			hashtable[i] = new LinkedList(); 
		}
	}

	~HashTable(){
		
		for(int i = 0; i < length; ++i){
			LinkedList * temp = hashtable[i]; 

			delete temp; 
		}

		delete []hashtable; 
	}

	int hashcode(int& value) const; 

	void insert(int& value); 

	void remove(int &value); 

	int search(int &value) const; 

	//void print(); //this function will print out all the values in the hashtable
}; 

int HashTable::hashcode(int& value) const{
	int key = length % value; 

	return key; 
}

void HashTable::insert(int& value){

	int key = hashcode(value); 

	Node * n = new Node(key, value); 

	n->next = NULL;

	hashtable[key]->addNode(n);

	return; 
}

int HashTable::search(int &value) const{

	int index = hashcode(value); 

	if(hashtable[index] != NULL){

		cout << "Found value " << value << " at key " << index << "." <<  endl; 

		return index; 
	}
	else{
		return -1; 
	}
}

void HashTable::remove(int& value){

	int index = search(value); 

	if(index == -1){
		cout << "Value does not exist." << endl; 
	}
	else{

		LinkedList *l = hashtable[index]; 
		l->removeNode(value); 

		l = NULL; 

		return; 
	}
}


void printOperations(){

	cout << "i ------ insert(): insert a value into the hashtable\n";
	cout << "r ------ remove(): remove a value from the hashtable\n"; 
	cout << "s ------ search(): find the key of the value\n"; 
	cout << "q ------ quit():   quit the program\n";
}


int main(){

	char option = 'a';
	const int length = 10; 
	int n = 0;
	HashTable *h = new HashTable(length); 

	cout << "Welcome to the HashTable class interface!!" << endl; 

	printOperations(); 

	cout << "Enter option: "; 

	cin >> option; 

	while( option != 'q'){
		switch(option){
			case 'i':
				
				cout << "Enter number: ";
				cin >> n; 
				h->insert(n); 
			break; 
			case 'r':
				
				cout << "Enter number: ";
				cin >> n; 
				h->remove(n); 
			break; 
			case 's':
				 
				cout << "Enter number: "; 
				cin >> n; 
				if(h->search(n) == -1){
					cout << "Value doesn't exist" << endl;
				}
			break; 
			default:
				cout << "Option doesn't exist. Try again." << endl; 
			break; 
		}

		cout << "Enter opiton: ";
		cin >> option; 
	}

	delete h; 
	return 0; 
}