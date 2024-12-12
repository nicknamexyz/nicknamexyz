12.	Write program to implement a priority queue in C++ using an inorder list to store the items in the queue. Create a class that includes the data items (which should be template) and the priority (which should be int). The inorder list should contain these objects, with operator <= overloaded so that the items with highest priority appear at the start of the list (which will make it relatively easy to retrieve the highest item.)


A priority queue is an abstract data type similar to a regular queue but with an added priority 
assigned to each element. Elements with higher priority are served before elements with lower 
priority. This data structure is useful in scenarios where certain tasks must be prioritized over others, 
such as job scheduling in operating systems. 

Algorithm 
 
1. Class Definition 
   - Define a template class for the priority queue, including a nested structure for the nodes. 
 
2. Node Structure 
   - Define a struct for the node, containing data, priority, and a pointer to the next node. 
 
3. Constructor and Destructor 
   - Initialize the head pointer in the constructor and ensure all nodes are deleted in the destructor. 
 
4. enqueue(T data, int priority) 
   - Create a new node and insert it into the list in order of priority. 
 
5. dequeue() 
   - Remove and return the node with the highest priority from the front of the list. 
 
6. display() 
   - Iterate through the list from head to tail, printing each node's data and priority. 
 
7. Main Function 
   - Provide a menu for the user to add, delete, display items, or exit the program. 


#include<iostream>
#include<stdlib.h>
#define SIZE 5

using namespace std;

class deQueue{
	int queue[10];

public:
	int front, rear;
	deQueue();
	int add_at_beg(int);
	int add_at_end(int);
	int delete_fr_front();
	int delete_fr_rear();
	void display();
	bool isEmpty();
	bool isFull();
};

deQueue::deQueue(){
	front=-1;
	rear=-1;
	for(int i=0; i<SIZE; i++){
		queue[i]=-1;
	}
}

bool deQueue::isEmpty(){
	if((front>rear) || (front==-1 && rear==-1)){
		return 1;
	}
	else{
		return 0;
	}
}

bool deQueue::isFull(){
	if(rear==SIZE-1){
		return 1;
	}
	else{
		return 0;
	}
}

int deQueue::add_at_beg(int item){
	int  i,j;

	if(front==-1){
		front++;
	}

	i = front-1;
	while(i>=0){
		queue[i+1] = queue[i];
		i--;
	}

	j = rear;
	while(j>=front){
		queue[j+1] = queue[j];
		j--;
	}

	rear++;
	queue[front] = item;
	return front;
}

int deQueue::add_at_end(int item){
	if(front==-1 && rear==-1){
		front++;
	}

	queue[++rear] = item;
	return rear;
}

void deQueue::display(){
	for(int i=front;i<=rear;i++){
		cout<<queue[i]<<" ";	
	}
}

int deQueue::delete_fr_front(){
	int item;

	if(front==-1){
		front++;
	}

	item = queue[front];
	queue[front]=-1;
	front++;
	return item;
}

int deQueue::delete_fr_rear(){
	int item;
	item = queue[rear];
	queue[rear]=-1;
	rear--;
	return item;
}

int main(){
	int ch,item;
	deQueue d1;

	do{
		cout<<"\n\n------------------DEQUEUE OPERATION-------------------\n"<<endl;
		cout<<"1:Insert at beginning"<<endl;
		cout<<"2:Insert at end"<<endl;
		cout<<"3:Display"<<endl;
		cout<<"4:Deletion from front"<<endl;
		cout<<"5:Deletion from rear"<<endl;
		cout<<"6:Exit\n"<<endl;

		cout<<"Enter your choice: ";
		cin>>ch;
		cout<<endl;

		switch(ch){
			case 1:
				if(d1.isFull()){
					cout<<"\n  --> Dequeue is full, Item can not be inserted."<<endl;
				}
				else{
					cout<<"Enter the element to be inserted:";
					cin>>item;
					d1.front= d1.add_at_beg(item);
					cout<<"\n  --> Item "<<item<<" is inserted at beginning."<<endl;
				}
				break;

			case 2:
				if(d1.isFull()){
					cout<<"\n  --> Dequeue is full, Item can not be inserted."<<endl;
				}
				else{
					cout<<"Enter the element to be inserted:";
					cin>>item;
					d1.rear= d1.add_at_end(item);
					cout<<"\n  --> Item "<<item<<" is inserted at ending."<<endl;
				}
				break;

			case 3:
				d1.display();
				break;

			case 4:
				if(d1.isEmpty()){
					cout<<"\n  --> Dequeue is empty, Item can not be deleted."<<endl;
				}
				else{
					item = d1.delete_fr_front();
					cout<<"\n  --> Deleted item form beginning is: "<<item<<endl;
				}
				break;
			case 5:
				if(d1.isEmpty()){
					cout<<"\n  --> Dequeue is empty, Item can not be deleted."<<endl;
				}
				else{
					item = d1.delete_fr_rear();
					cout<<"\n  --> Deleted item form ending is: "<<item<<endl;
				}
				break;

			case 6:
				cout<<"---------------Thank You-------------------\n"<<endl;
				break;

			default:
				cout<<"  --> Enter correct choice...!\n"<<endl;
				break;
		}
	}while(ch!=6);

	return 0;
}