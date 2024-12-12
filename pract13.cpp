13.	Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. Order once placed cannot be cancelled. Write C++ program to simulate the system using circular queue using array.


#include <iostream>
using namespace std;
#define MAX 5 // Maximum number of orders
class PizzaOrderQueue {
private:
 int orders[MAX]; // Array to store pizza orders
 int front; // Front pointer
 int rear; // Rear pointer
 int count; // Count of orders in the queue
public:
 // Constructor to initialize the queue
 PizzaOrderQueue() {
 front = -1;
 rear = -1;
 count = 0;
 }
 // Function to check if the queue is full
 bool isFull() {
 return count == MAX;
 }
 // Function to check if the queue is empty
 bool isEmpty() {
 return count == 0;
 }
 // Function to place an order in the queue
 void placeOrder(int orderID) {
 if (isFull()) {
 cout << "Order queue is full. Cannot place more orders." << endl;
 return;
 }
 if (front == -1) { // First order being placed
 front = rear = 0;
 } else {
 rear = (rear + 1) % MAX; // Circular increment
 }
 orders[rear] = orderID;
 count++;
 cout << "Order " << orderID << " placed successfully." << endl;
 }
 // Function to serve an order (remove from front)
 void serveOrder() {
 if (isEmpty()) {
 cout << "No orders to serve." << endl;
 return;
 }
 cout << "Order " << orders[front] << " is being served." << endl;
 if (front == rear) { // Only one order left
 front = rear = -1;
 } else {
 front = (front + 1) % MAX; // Circular increment
 }
 count--;
 }
 // Function to display all orders in the queue
 void displayOrders() {
 if (isEmpty()) {
 cout << "No orders in the queue." << endl;
 return;
 }
 cout << "Current orders in the queue: ";
 int i = front;
 for (int j = 0; j < count; j++) {
 cout << orders[i] << " ";
 i = (i + 1) % MAX; // Circular traversal
 }
 cout << endl;
 }
};
int main() {
 PizzaOrderQueue pq;
 int choice, orderID;
 do {
 cout << "\nPizza Parlor Order System\n";
 cout << "1. Place Order\n";
 cout << "2. Serve Order\n";
 cout << "3. Display Orders\n";
 cout << "4. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter order ID to place: ";
 cin >> orderID;
 pq.placeOrder(orderID);
 break;
 case 2:
 pq.serveOrder();
 break;
 case 3:
 pq.displayOrders();
 break;
 case 4:
 cout << "Exiting the system." << endl;
 break;
 default:
 cout << "Invalid choice, please try again." << endl;
 }
 } while (choice != 4);
 return 0;
}