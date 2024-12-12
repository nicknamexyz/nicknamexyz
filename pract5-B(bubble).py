5.	Write a Python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
b)	Bubble sort and display top five scores.


def selection(arr):
    n=len(arr)
    for i in range(n):
        min_index=i
        for j in range(i+1,n):
            if arr[j]<arr[min_index]:
                min_index=j

        arr[i], arr[min_index]= arr[min_index],arr[i]
    return arr

def display_top_five(arr):
    top_scores= sorted(arr, reverse=True)[:5]
    print("Top 5 scores are:")
    for score in top_scores:
        print(score)

print()

percentage=[90.15, 91.56,88.90,99.40,90.34,93.18,85.75,95.65,80.80,81.23]

print("Sorting using selection sort:")
sel=selection(percentage.copy())
print(sel)

print()

display_top_five(percentage)
