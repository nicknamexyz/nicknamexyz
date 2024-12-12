5.	Write a Python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a)	Selection Sort and display top five scores.   


Sorting algorithms are essential for organizing data, which makes retrieval and 
analysis easier. Selection Sort repeatedly selects the minimum element from the 
unsorted part of the array and moves it to the beginning. Bubble Sort repeatedly 
steps through the list, compares adjacent elements, and swaps them if they are in 
the wrong order. Both algorithms are useful for educational purposes, although 
they are not the most efficient for large datasets. 
 
Algorithm 
1.  Store first-year percentages in an array. 
2.  Define a function Selection_Sort(marks): 
    a.  Iterate through the array to find the minimum element. 
    b.  Swap it with the first unsorted element. 
3.  Define a function Bubble_Sort(marks): 
    a.  Compare adjacent elements and swap them if needed. 
    b.  Repeat until the array is sorted. 
4.  Define a function top_five_marks(marks) to display the top five scores. 
5.  In the main function, get input from the user and present a menu for sorting 
options.





def bubble(arr):
    n=len(arr)
    for i in range(n-1):
        for j in range(0,n-i-1):
            if arr[j]>arr[j+1]:
                arr[j], arr[j+1]= arr[j+1], arr[j]

    return arr

def display_top_five(arr):
    top_scores= sorted(arr, reverse=True)[:5]
    print("Top 5 scores are:")
    for score in top_scores:
        print(score)

print()

percentage=[90.15, 91.56,88.90,99.40,90.34,93.18,85.75,95.65,80.80,81.23]
print("Sorting using bubble sort:")
bubble= bubble(percentage.copy())
print(bubble)

print()

display_top_five(percentage)
