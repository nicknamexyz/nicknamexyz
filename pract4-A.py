
Write a Python program to store roll numbers of students in an array who attended a training 
program in random order. Write functions for searching whether a particular student attended 
the training program or not, using Linear Search and Sentinel Search. 

Theory 
An array is a data structure that can hold a fixed-size sequence of elements of the same type. 
Linear search is a simple searching algorithm that checks every element in the array until the 
desired element is found. Sentinel search improves upon linear search by placing a copy of 
the target value at the end of the array, which reduces the number of comparisons. 
 
 
 Algorithm 
1.Store roll numbers in an array. 
2. Define a function `linear_search(roll_numbers, target)`: 
   - Iterate through each element in `roll_numbers`. 
   - If the element matches `target`, return its index. 
   - If not found, return -1. 
3. Define a function `sentinel_search(roll_numbers, target)`: 
   - Append `target` to the end of `roll_numbers` as a sentinel. 
   - Iterate through the array until `target` is found. 
   - If found before the last element, return its index. 
   - If found at the last element, return -1 (not found). 
4. Test both functions with sample roll numbers.




import random 
 
# Function to perform linear search 
def linear_search(arr, roll_number): 
    for number in arr: 
        if number == roll_number: 
            return True 
    return False 
 
 
# Function to perform sentinel search 
def sentinel_search(arr, roll_number): 
    # Save the last element and set sentinel 
    last = arr[-1] 
    arr[-1] = roll_number 
 
    i = 0 
    while arr[i] != roll_number: 
        i += 1 
 
    # Restore the last element 
    arr[-1] = last 
    # Check if we found the roll number 
    return i < len(arr) or last == roll_number 
 
 
def generate_random_roll_numbers(n): 
    return random.sample(range(1000, 1000 + n), n)  # Unique roll numbers between 1000 and 1000 + n 
 
 
 
def main(): 
    n = 10  # Number of students 
    roll_numbers = generate_random_roll_numbers(n) 
    print("Roll numbers of students who attended the training program:", roll_numbers) 
 
    roll_number_to_search = int(input("Enter the roll number to search: ")) 
 
    # Linear Search 
    found = linear_search(roll_numbers, roll_number_to_search) 
    print(f"Linear Search: Roll number {roll_number_to_search} {'found' if found else 'not found'}") 
 
    # Sentinel Search 
    found = sentinel_search(roll_numbers, roll_number_to_search) 
    print(f"Sentinel Search: Roll number {roll_number_to_search} {'found' if found else 'not found'}") 
 
 
 
if __name__ == "__main__": 
    main()

# Function to perform Linear Search
def linear_search(arr, n, key):
    for i in range(n):
        if arr[i] == key:
            return i  # Return the index if key is found
    return -1  # Return -1 if key is not found

# Function to perform Sentinel Search
def sentinel_search(arr, n, key):
    # Place the key as the sentinel (temporarily at the end)
    last = arr[n-1]
    arr[n-1] = key
    i = 0

    # Linear search without boundary checks
    while arr[i] != key:
        i += 1

    # Restore the last element of the array
    arr[n-1] = last

    # If found within the array bounds, return index
    if i < n-1 or arr[n-1] == key:
        return i
    return -1

# Main function for Part (a)
def main_part_a():
    # Roll numbers of students who attended the training program (random order)
    roll_numbers = [105, 110, 102, 115, 120, 108]
    n = len(roll_numbers)
    
    print("Roll Numbers of students who attended the training program:", roll_numbers)
    
    key = int(input("Enter the roll number to search: "))
    
    # Perform Linear Search
    result = linear_search(roll_numbers, n, key)
    if result != -1:
        print(f"Linear Search: Roll number {key} attended the training program at index {result}.")
    else:
        print(f"Linear Search: Roll number {key} did not attend the training program.")
    
    # Perform Sentinel Search
    result = sentinel_search(roll_numbers, n, key)
    if result != -1:
        print(f"Sentinel Search: Roll number {key} attended the training program at index {result}.")
    else:
        print(f"Sentinel Search: Roll number {key} did not attend the training program.")

# Call the function for Part (a)
main_part_a()