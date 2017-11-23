#include <iostream>

using namespace std; 

class Queue{
	class Node{
	private: 
		int data; 
		Node * next; 
	public:
		Node(int data){
			this->data = data; 
		}
		friend class Queue; 
	};
private: 
	Node * first; 
	Node * last; 
public:
	Queue(){
		first = NULL; 
		last = NULL; 
	}
	~Queue(){
		clear(); 
	}
	void add(int item);
	void remove(); 
	void peek(); 
	bool isEmpty(); 
	void clear(); 
};

void Queue::add(int item){
	Node * n = new Node(item); 
	n->next = NULL; 
	if(isEmpty()){
		first = n; 
		last = first; 
		return;
	}

	last->next = n; 
	last = n; 

	return; 
}

void Queue::remove(){
	if(isEmpty()){
		cout << "Cannot perform operation. The queue is empty" << endl; 
		return; 
	}
	else{

		Node * temp = first; 

		
		first = temp->next; 

		if(first == NULL){
			last = NULL; 
		}
		temp->next = NULL; 
		delete temp; 
	}
}

void Queue::peek(){
	if(isEmpty()){
		cout << "Cannot perform operation. The queue is empty" << endl; 
		return; 
	}
	else{
		cout << first->data << endl; 
		return; 
	}
}
void Queue::clear(){
	if(isEmpty()){
		cout << "Cannot perform operation. The queue is empty" << endl; 
		return;
	}
	else{
	

		while(first != NULL){
			Node * temp = first; 

			first = temp->next;

			if(first == NULL){
				last = NULL;
			}
			temp->next = NULL;

			delete temp; 

		}
	}
}
bool Queue::isEmpty(){
	return first == NULL && last == NULL; 
}

int main(){

	Queue * q = new Queue(); 

	
	char option = 'a'; 
	int temp = 0; 
	cout << "Enter option: "; 
	cin >> option; 

	while(option != 'q'){
		switch(option){
			case 'a':
				
				cout << "Enter a number: "; 
				cin >> temp; 
				q->add(temp); 
				break; 
			case 'r':
				q->remove(); 
				break; 
			case 'd':
				q->clear(); 
				break; 
			case 'p':
				q->peek();
				break; 
			default:
				cout << "Unrecognized command. Try again" << endl; 
				break; 
		}
		cout << "Enter option: "; 
		cin >> option; 
	}

	delete q; 

	return 0; 
}