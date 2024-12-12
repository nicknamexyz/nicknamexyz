6.	Write a Python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using quick sort and display top five scores.

Algorithm 
1.  Store first-year percentages in an array. 
2.  Define a function input_percentage() to accept percentages from the user. 
3.  Define a function percentage_partition(perc, start, end) for partitioning. 
4.  Define a function quick_sort(perc, start, end) to implement the Quick Sort 
algorithm. 
5.  Define a function display_top_five(perc) to display the top five percentages. 
6.  In the main function, present a menu for user interaction. 

def input_percentage():
    perc = []
    number_of_students = int(input("Enter the number of students: "))
    for i in range(number_of_students):
        perc.append(float(input(f"Enter the percentage of Student {i+1}: ")))
    return perc

def print_percentage(perc):
    print("Entered Percentages:")
    for p in perc:
        print(p)

def percentage_partition(perc, start, end):
    pivot = perc[start]
    lower_bound = start + 1
    upper_bound = end

    while True:
        while lower_bound <= upper_bound and perc[lower_bound] <= pivot:
            lower_bound += 1

        while lower_bound <= upper_bound and perc[upper_bound] >= pivot:
            upper_bound -= 1

        if lower_bound <= upper_bound:
            perc[lower_bound], perc[upper_bound] = perc[upper_bound], perc[lower_bound]
        else:
            break

    perc[start], perc[upper_bound] = perc[upper_bound], perc[start]
    return upper_bound


def quick_sort(perc, start, end):
    if start < end:
        partition_index = percentage_partition(perc, start, end)
        quick_sort(perc, start, partition_index - 1)
        quick_sort(perc, partition_index + 1, end)
    return perc


def display_top_five(perc):
    print("Top Five Percentages are:")
    
    top_five = perc[-5:] if len(perc) >= 5 else perc
    for p in reversed(top_five): 
        print(p)

percentages = input_percentage()

print_percentage(percentages)


sorted_percentages = quick_sort(percentages, 0, len(percentages) - 1)


display_top_five(sorted_percentages)