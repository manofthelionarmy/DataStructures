#include <iostream>

using namespace std; 

class Node{
private:
	int elem; 
	Node * next; 
	friend class LinkedList; 
}; 

class LinkedList{
public:
	LinkedList();
	~LinkedList(); 
	bool empty() const; 
	const int& front() const; 
	void addFront(const int& e); 
	void removeFront(); 
	void clear(); 
	void print(); 
private: 
	Node * head; 
}; 

void printOptions(){
	cout << "Options: \n"; 
	cout << "a ---------- addFront():    add a Node to the front of the LL\n"; 
	cout << "r ---------- removeFront(): remove a Node from the front of the LL\n";
	cout << "f ---------- front():		 print the front element out\n"; 
	cout << "p ---------- print():       print all the content in the LL\n"; 
	cout << "d ---------- delete():		 delete all of the content in the LL\n"; 
	cout << "q ---------- quit():		 end the program\n"; 
	cout << "o ---------- options():     print out the list of options\n"; 
}
int main(){


	char option = 'a'; 
	LinkedList *l = new LinkedList(); 
	int n = 0; 
	cout << "Welcome to the Linked List Class interface!" << endl; 

	printOptions(); 

	cout << "Enter option: "; 
	cin >> option; 

	while(option != 'q'){
		switch(option){
			case 'a':

				cout << "Enter number: "; 
				cin >> n; 

				l->addFront(n); 
			break;
			case 'r':
				l->removeFront(); 
			break; 
			case 'f':
				cout << l->front() << endl; 
			break; 
			case 'p':
				l->print(); 
			break; 
			case 'd':
				l->clear(); 

			break; 
			case 'o':
				printOptions(); 
			break; 
			default:
				cout << "Error: Not an option" << endl; 
			break; 
		}

		cout << "Enter option: "; 
		cin >> option; 
			 
	}

	delete l; 

	return 0; 
}


LinkedList::LinkedList(){
	head = NULL; 
}
LinkedList::~LinkedList(){
	clear(); 	
}
bool LinkedList::empty() const{
	if(head == NULL){
		return true; 
	}

	return false; 
}

const int& LinkedList::front() const{
	return head->elem; 
}
void LinkedList::addFront(const int& e){
	Node * n = new Node(); 

	n->elem = e; 
	n->next = NULL;

	if(empty()){
		head = n; 
		return; 
	}
	else{
		n->next = head;  
		head = n; 
		return; 
	}
}

void LinkedList::removeFront(){

	if(empty()){
		cout << "Cannot remove ---- List is empty" << endl; 
	}
	else{
		Node * temp; 
		temp = head; 

		head = temp->next; 
		cout << "Removed " << temp->elem << endl; 
		delete temp; 

	}

}

void LinkedList::clear(){
	if(empty()){
		cout << "Cannot delete linked list --- list is empty" << endl; 
	}
	else{
		 

		while(head != NULL){
			Node * temp = head;
			head = temp->next; 
			cout << "Deleted " << temp->elem << endl; 
			delete temp; 
		}
		
	}
}

void LinkedList::print(){
	if(empty()){
		cout << "Cannot print ---- List is empty" << endl; 
	}
	else{
		Node * temp = head; 

		while(temp != NULL){
			cout << temp->elem << " "; 
			temp = temp->next; 
		}

		cout << endl;  

		
		delete temp; 
	}
}