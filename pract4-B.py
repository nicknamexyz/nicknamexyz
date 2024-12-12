Write a Python program to store roll numbers of students in an array who attended a training 
program in sorted order. Write functions for searching whether a particular student attended 
the training program or not, using Binary Search and Fibonacci Search. 

Theory 
A sorted array allows for more efficient search operations. Binary search is a logarithmic 
search algorithm that divides the array in half repeatedly to find the target element. Fibonacci 
search is another efficient search method that uses Fibonacci numbers to divide the search 
space, leveraging the properties of the Fibonacci sequence for optimal performance. 
 
Algorithm 
 
1. Store roll numbers in a sorted array. 
2. Define a function binary_search(roll_numbers, target): 
a. Initialize two pointers, low and high, representing the bounds of the search. 
b. While low is less than or equal to high: 
i. Calculate the midpoint. 
ii. If the midpoint element equals target, return its index. 
iii. If the midpoint element is less than target, adjust low. 
iv. Otherwise, adjust high. 
c. If not found, return -1. 
3. Define a function fibonacci_search(roll_numbers, target): 
a. Initialize Fibonacci variables and calculate the largest Fibonacci number less 
than the length of the array. 
b. Use a loop to compare target with the elements at Fibonacci indices. 
c. Adjust the Fibonacci numbers based on comparisons until the target is found 
or the search space is exhausted. 
d. Return the index if found, otherwise return -1. 
4. Test both functions with sample roll numbers. 


import random
# Function to perform Binary Search
def binary_search(arr, key):
    low = 0
    high = len(arr) - 1
    
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid  # Return the index if key is found
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1  # Return -1 if key is not found

# Function to perform Fibonacci Search
def fibonacci_search(arr, key):
    n = len(arr)
    # Initialize fibonacci numbers
    fib_m2 = 0  # (m-2)'th Fibonacci number
    fib_m1 = 1  # (m-1)'th Fibonacci number
    fib_m = fib_m2 + fib_m1  # m'th Fibonacci number

    # fib_m will store the smallest Fibonacci number greater than or equal to n
    while fib_m < n:
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m2 + fib_m1

    # Marks the eliminated range from front
    offset = -1

    # While there are elements to be inspected
    while fib_m > 1:
        # Check if fib_m2 is a valid index
        i = min(offset + fib_m2, n - 1)

        if arr[i] < key:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i
        elif arr[i] > key:
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1
        else:
            return i  # Key found
    # Compare the last element
    if fib_m1 and arr[offset + 1] == key:
        return offset + 1
    return -1  # Key not found

# Main function for Part (b)
def main_part_b():
    # Roll numbers of students who attended the training program (sorted order)
    roll_numbers = [102, 105, 108, 110, 115, 120]
    
    print("Roll Numbers of students who attended the training program (sorted):", roll_numbers)
    
    key = int(input("Enter the roll number to search: "))
    
    # Perform Binary Search
    result = binary_search(roll_numbers, key)
    if result != -1:
        print(f"Binary Search: Roll number {key} attended the training program at index {result}.")
    else:
        print(f"Binary Search: Roll number {key} did not attend the training program.")
    
    # Perform Fibonacci Search
    result = fibonacci_search(roll_numbers, key)
    if result != -1:
        print(f"Fibonacci Search: Roll number {key} attended the training program at index {result}.")
    else:
        print(f"Fibonacci Search: Roll number {key} did not attend the training program.")

# Call the function for Part (b)
main_part_b()