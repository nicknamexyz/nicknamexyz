7.	Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to:
a)	Add and delete the members as well as president or even secretary.
b)	Compute total number of members of club
c)	Display members
d)	Two linked lists exists for two divisions. Concatenate two lists.

Theory 
A singly linked list is a dynamic data structure that allows efficient insertion and 
deletion of elements. Each node contains data and a pointer to the next node, 
enabling traversal. This program uses linked lists to manage club membership, 
ensuring flexibility in managing members. 
 
Algorithm 
1. Define a Node class for storing PRN and Name. 
2. Define a Club class to manage the linked list operations: 
   a. Implement functions to add members at the beginning, end, and after a specific 
node. 
   b. Implement functions to delete members from the beginning, end, or by value. 
   c. Implement a function to compute the total number of members. 
   d. Implement a function to display members. 
   e. Implement a function to concatenate two lists. 
3. Implement the main function to interact with the user and manage the club 
members.






#include <iostream>
#include <string>
using namespace std;
// Node structure
struct Node{
 string name;
 long prn;
 Node* next;
};
// Singly Linked List class
class PinnacleClub{
private:
 Node* head;
 
public:
 PinnacleClub(){
 head = NULL;
 };
 // Function to add member (president, secretary, or regular member)
 void addMember(string name, long prn, string position = "member") {
 Node* newNode = new Node();
 newNode->name = name;
 newNode->prn = prn;
 newNode->next = NULL;
 if (head == NULL) {
 head = newNode;
 cout << position << " " << name << " added as the first member." << endl;
 return;
 }
 if (position == "president") {
 newNode->next = head;
 head = newNode;
 cout << name << " added as president." << endl;
 } else if (position == "secretary") {
 Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newNode;
 cout << name << " added as secretary." << endl;
 } else {
 Node* temp = head;
 while (temp->next != NULL && temp->next->next != NULL) {
 temp = temp->next;
 }
 newNode->next = temp->next;
 temp->next = newNode;
 cout << name << " added as member." << endl;
 }
 }
 // Function to delete member (president, secretary, or regular member)
 void deleteMember(long prn, string position = "member") {
 if (head == NULL) {
 cout << "No members in the list." << endl;
 return;
 }
 Node* temp = head;
 Node* prev = NULL;
 // Deleting president
 if (position == "president") {
 head = head->next;
 delete temp;
 cout << "President removed." << endl;
 return;
 }
 // Deleting regular member or secretary
 while (temp != NULL && temp->prn != prn) {
 prev = temp;
 temp = temp->next;
 }
 if (temp == NULL) {
 cout << "Member not found." << endl;
 return;
 }
 prev->next = temp->next;
 delete temp;
 cout << "Member removed." << endl;
 }
 // Function to count the total number of members
 int countMembers() {
 Node* temp = head;
 int count = 0;
 while (temp != NULL) {
 count++;
 temp = temp->next;
 }
 return count;
 }
 // Function to display the list of members
 void displayMembers() {
 if (head == NULL) {
 cout << "No members in the list." << endl;
 return;
 }
 Node* temp = head;
 while (temp != NULL) {
 cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
 temp = temp->next;
 }
 }
 // Function to display members in reverse order using recursion
 void displayReverse(Node* node) {
 if (node == NULL) {
 return;
 }
 displayReverse(node->next);
 cout << "PRN: " << node->prn << ", Name: " << node->name << endl;
 }
 void displayReverse() {
 if (head == NULL) {
 cout << "No members in the list." << endl;
 return;
 }
 displayReverse(head);
 }
 // Function to concatenate two lists
 void concatenate(PinnacleClub& club2) {
 if (head == NULL) {
 head = club2.head;
 return;
 }
 Node* temp = head;
 while (temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = club2.head;
 club2.head = NULL;
 }
};
int main() {
 PinnacleClub club1, club2;
 // Add members to the first club
 club1.addMember("Alice", 101, "president");
 club1.addMember("Bob", 102, "member");
 club1.addMember("Charlie", 103, "secretary");
 // Display members
 cout << "\nMembers of Club 1:" << endl;
 club1.displayMembers();
 // Count total members
 cout << "\nTotal members in Club 1: " << club1.countMembers() << endl;
 // Display members in reverse order
 cout << "\nMembers of Club 1 in reverse order:" << endl;
 club1.displayReverse();
 // Add members to the second club
 club2.addMember("David", 201, "president");
 club2.addMember("Eve", 202, "member");
 club2.addMember("Frank", 203, "secretary");
 // Concatenate club1 and club2
 club1.concatenate(club2);
 // Display members after concatenation
 cout << "\nMembers after concatenating Club 1 and Club 2:" << endl;
 club1.displayMembers();
 return 0;
}


