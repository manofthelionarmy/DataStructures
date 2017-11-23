#include <iostream>
#include <string>

using namespace std; 
class Stack{
	class Node{
		private:
			int data; 
			Node * next; 
		public:
			Node(int data){
				this->data = data; 
			}
		friend class Stack; 
	}; 
	private:
		Node * top; 
	public:
		Stack(){
			top = NULL; 
		}
		~Stack(){
			clear(); 
		}
		const int pop(); 
		void push(const int& item); 
		const int peek(); 
		bool isEmpty(); 
		void clear(); 

}; 


const int Stack::pop(){
	
	if(isEmpty()){
		cout << "Cannot perform operation. The stack is empty" << endl; 
		return -1000000000; 
	}
	else{
		Node *temp = top; 
		top = top->next; 
		temp->next = NULL; 
		 
		delete temp; 
	}
	return top->data; 

}
void Stack::push(const int& item){
	Node * n = new Node(item); 
	n->next = NULL; 
	if(top == NULL){
		top = n; 
		return; 
	}
	else{
		n->next = top; 
		top = n; 
		return; 
	}
}
const int Stack::peek(){
	if(isEmpty()){
		cout << "Cannot perform the operation. The stack is empty" << endl;  
		return -1000000000; 
	}
	return top->data; 

}
bool Stack::isEmpty(){
	return top == NULL; 
}
void Stack::clear(){
	if(isEmpty()){
		cout << "Cannot perform the operation. The stack is empty" << endl; 
		return; 
	}
	else{
		while(top != NULL){
			Node * temp = top; 
			top = top->next; 
			temp->next = NULL;
			delete temp; 
		}
	}


}
void printOptions(){
	cout << "pop   ----- pop():     pop off the top and collect its value\n"; 
	cout << "peek  ----- peek():    see the top node's value\n"; 
	cout << "push  ----- push():    push a new value to the top of the stack\n"; 
	cout << "clear ----- clear():   delete the content from the stack \n"; 
	cout << "o     ----- options(): see the key for the functions of the class\n"; 
	cout << "q     ----- quit():    end the program\n"; 
}
int main(){

	string choice = " "; 
	Stack * s = new Stack(); 
	cout << "Welcome to the Stacks program!" << endl; 

	printOptions(); 

	cout << "Enter option: "; 
	cin >> choice; 

	while(choice.compare("q") != 0){
		if(choice.compare("pop") == 0){
			cout << s->pop() << endl; 
		}
		else if(choice.compare("peek") == 0){
		 
			cout << s->peek() << endl;
		}
		else if(choice.compare("push") == 0){
			int temp = 0; 
			cout << "Enter number: "; 
			cin >> temp; 
			s->push(temp); 
		}
		else if(choice.compare("clear") == 0){
			s->clear(); 
		}
		else if(choice.compare("o") == 0){
			printOptions(); 
		}
		else{
			cout << "Unrecognized command. Try again" << endl; 
		}
		cout << "Enter option: ";
		cin >> choice; 
	}

	delete s; 

	return 0; 
}