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
		clear(); 
	}

	friend class HashTable;  

	bool isEmpty(); 

	void addNode(Node * n); 

	void removeNode(int& value); 

	void clear(); 

	void printNodes(); 
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
	
	tail->next = n; 
	tail = n; 

	return; 
}
void LinkedList::removeNode(int& value){

	Node * runner1 = head; 
	Node * runner2 = runner1->next; 

	if(runner1->value == value){
		if(runner1 == head){
			head = runner1->next; 

			if(head == NULL){
				tail = NULL; 
			}

			runner1->next = NULL; 

			delete runner1; 
		}
	}
	else{

		while(runner2 != NULL){
		if(runner2->value == value){
			cout << "Succesfully deleted " << endl ;
			runner1->next = runner2->next; 

			if(runner1->next == NULL){
				tail = runner1; 
			}

			runner2->next = NULL; 
			delete runner2; 
			return;
			
		}
		else{
			runner1 = runner1->next; 
			runner2 = runner2->next; 		
		} 
	}

	cout << "Value doesn't exist." << endl; 

	}

	
}

void LinkedList::printNodes(){
	if(isEmpty()){
		cout << "-> NULL" << endl;
		return; 
	}
	else{
		Node * temp = head; 

		while(temp != NULL){
			cout << "-> " << temp->value << " "; 
			temp = temp->next; 
		}
	}
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
		hashtable = new LinkedList*[length]; 

		for(int i = 0; i < length; ++i){
			hashtable[i] = new LinkedList(); 
		}
	}

	~HashTable(){
		
		for(int i = 0; i < length; ++i){
			LinkedList * temp = hashtable[i]; 
			hashtable[i] = NULL; 
			delete temp; 
		}

		delete []hashtable; 
	}

	int hashcode(int& value) const; 

	void insert(int& value); 

	void remove(int &value); 

	const int search(int &value); 

	void print(); 
}; 

int HashTable::hashcode(int& value) const{
	int key = length % value; 

	if(key == length){
		key -= 1; 
	}

	return key; 
}

void HashTable::insert(int& value){

	int key = hashcode(value); 

	Node * n = new Node(key, value); 

	n->next = NULL;

	hashtable[key]->addNode(n);  



	return; 
}

const int HashTable::search(int &value)
{

	int index = hashcode(value); 

	if(hashtable[index]->isEmpty()){
		return -1; 
	}
	else{

		cout << "Found value " << value << " at key " << index << "." <<  endl; 

		return index; 
	}
}

void HashTable::remove(int& value){

	int index = search(value); 

	if(index == -1){
		cout << "Value does not exist." << endl; 
	}
	else{

		hashtable[index]->removeNode(value); 

		return; 
	}
}

void HashTable::print(){

	for(int i = 0; i < length; ++i){

		cout << "Key: [" << i << "] "; 
		hashtable[i]->printNodes(); 
		cout << endl;
	}


	return; 
}


void printOperations(){

	cout << "i ------ insert():  insert a value into the hashtable\n";
	cout << "r ------ remove():  remove a value from the hashtable\n"; 
	cout << "s ------ search():  find the key of the value\n"; 
	cout << "p ------ print():   print out the hashtable\n"; 
	cout << "o ------ options(): print out the options\n";
	cout << "q ------ quit():    quit the program\n";
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
			case 'o':
				printOperations(); 
			break; 
			case 'p':
				h->print(); 
			break; 
			default:
				cout << "Option doesn't exist. Try again." << endl; 
			break; 
		}

		cout << "Enter option: ";
		cin >> option; 
	}

	delete h; 
	return 0; 
}