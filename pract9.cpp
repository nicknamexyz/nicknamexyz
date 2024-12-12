9.	A palindrome is a string of character that‘s the same forward and backward. Typically, punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop” is a palindrome, as can be seen by examining the characters “poor danisina droop” and observing that they are the same forward and backward. One way to check for a palindrome is to reverse the characters in the string and then compare with them the original-in a palindrome, the sequence will be identical. Write C++ program with functions-
a)	To print original string followed by reversed string using stack
b)	To check whether given string is palindrome or not


Theory: A palindrome is a string that reads the same forward and backward. By 
using a stack, we can easily reverse the order of characters. The original string can 
be compared with the reversed string to determine if it is a palindrome. Stacks 
follow the Last In First Out (LIFO) principle, making them suitable for this task. 
 
 
Algorithm: 
1. Define a STACK class to manage character storage with push and pop 
operations. 
2. Implement methods to push characters onto the stack and to reverse the string. 
3. Create a method to convert the input string by ignoring punctuation and spaces, 
and converting to lowercase. 
4. Compare the original string with the reversed string to check for palindrome. 
5. In the main function, accept user input, perform the required operations, and 
display results.


#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    string arr;
    
public:
    void push(char c) {
        arr += c;  // Append to the string
    }

    void reverse() {
        cout << "\nReversed string is: ";
        for (int i = arr.length() - 1; i >= 0; i--) {
            cout << arr[i];
        }
        cout << endl;
    }

    bool checkPalindrome(const string& original) {
        return arr == string(arr.rbegin(), arr.rend());  // Check if the string is equal to its reverse
    }
};

void preprocessString(const string& str, string& processed) {
    for (size_t i=0;i<str.length();i++) {
    	char ch=str[i];
        if (isalnum(ch)) {
            processed += tolower(ch);  // Add lowercase alphanumeric characters
        }
    }
}

int main() {
    Stack stack;
    string str, processed;

    cout << "Enter string to check if it is a palindrome: ";
    getline(cin, str);

    preprocessString(str, processed);

    // Push each character of the processed string onto the stack
    for (size_t i=0; i<processed.length();i++) {
        stack.push(processed[i]);
    }

    // Check if the processed string is a palindrome
    if (stack.checkPalindrome(processed)) {
        cout << "\nString is a palindrome..." << endl;
    } else {
        cout << "\nString is not a palindrome..." << endl;
    }

    // Print the reversed string
    stack.reverse();

    return 0;
}