
/*Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number etc) using vector container.*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string> // Added for string handling
using namespace std;

// Class representing an Item with attributes: name, quantity, cost, and code
class Item {
public:
    string name;  // Name of the item
    int quantity; // Quantity of the item
    int cost;     // Cost of the item
    int code;     // Unique code for the item

    // Overloading equality operator to compare items based on their 'code'
    bool operator==(const Item& i1) const {
        return code == i1.code;
    }

    // Overloading less-than operator for comparing 'code' during sorting
    bool operator<(const Item& i1) const {
        return code < i1.code;
    }
};

// Vector to hold all Item objects
vector<Item> o1;

// Function prototypes for operations on the item list
void print(Item &i1);    // Prints the details of a single item
void display();          // Displays all items in the list
void insert();           // Adds a new item to the list
void search();           // Searches for an item by its code
void dlt();              // Deletes an item based on its code

// Comparison function to sort items by their cost
bool compare(const Item &i1, const Item &i2) {
    return i1.cost < i2.cost;
}

int main() {
    int ch;  // Variable to store user's menu choice

    // Displaying a menu repeatedly until the user chooses to exit
    do {
        // Display menu options
        cout << "\n*** Menu ***";
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Search";
        cout << "\n4.Sort";
        cout << "\n5.Delete";
        cout << "\n6.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;  // Get user input

        // Switch case to handle different menu choices
        switch(ch) {
            case 1:
                insert();  // Call insert function to add an item
                break;

            case 2:
                display();  // Call display function to show all items
                break;

            case 3:
                search();  // Call search function to find an item by code
                break;

            case 4:
                // Check if the vector is empty before sorting
                if (o1.empty()) {
                    cout << "\nNo items to sort.";  // Display message if no items
                } else {
                    // Sort the vector based on the 'cost' of items
                    sort(o1.begin(), o1.end(), compare);
                    cout << "\n\nSorted on Cost";  // Notify user about sorting
                    display();  // Display sorted list
                }
                break;

            case 5:
                dlt();  // Call delete function to remove an item
                break;

            case 6:
                break;  // Exit the loop (ending the program)

            default:
                cout << "\nInvalid choice. Try again.";  // Handle invalid input
        }

    } while (ch != 6);  // Loop until user chooses 'Exit' (option 6)

    return 0;  // Return successful program termination
}

// Function to add a new item to the list
void insert() {
    Item i1;  // Create a new item object

    // Prompt the user for item details and store them in the object
    cout << "\nEnter Item Name: ";
    cin >> i1.name;
    cout << "\nEnter Item Quantity: ";
    cin >> i1.quantity;
    cout << "\nEnter Item Cost: ";
    cin >> i1.cost;
    cout << "\nEnter Item Code: ";
    cin >> i1.code;

    // Add the new item to the vector
    o1.push_back(i1);
}

// Function to display all items in the list
void display() {
    // Use the for_each algorithm to apply the 'print' function to each item
    for_each(o1.begin(), o1.end(), print);
}

// Function to print details of a single item
void print(Item &i1) {
    cout << "\n";
    cout << "\nItem Name: " << i1.name;
    cout << "\nItem Quantity: " << i1.quantity;
    cout << "\nItem Cost: " << i1.cost;
    cout << "\nItem Code: " << i1.code;
}

// Function to search for an item by its code
void search() {
    vector<Item>::iterator p;  // Iterator for vector
    Item i1;  // Temporary item to store the search code

    cout << "\nEnter Item Code to search: ";
    cin >> i1.code;

    // Use the find algorithm to search for the item by code
    p = find(o1.begin(), o1.end(), i1);

    // Check if the item was found
    if (p == o1.end()) {
        cout << "\nNot found.";  // Display message if item not found
    } else {
        // Display the details of the found item
        cout << "\nFound." << endl;
        cout << "Item Name : " << p->name << endl;
        cout << "Item Quantity : " << p->quantity << endl;
        cout << "Item Cost : " << p->cost << endl;
        cout << "Item Code: " << p->code << endl;
    }
}

// Function to delete an item by its code
void dlt() {
    vector<Item>::iterator p;  // Iterator for vector
    Item i1;  // Temporary item to store the deletion code

    cout << "\nEnter Item Code to delete: ";
    cin >> i1.code;

    // Use the find algorithm to locate the item by code
    p = find(o1.begin(), o1.end(), i1);

    // Check if the item was found
    if (p == o1.end()) {
        cout << "\nNot found.";  // Display message if item not found
    } else {
        // Erase the found item from the vector
        o1.erase(p);
        cout << "\nDeleted.";  // Notify user about successful deletion
    }
}

