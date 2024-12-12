2.Write a Python Program for magic square. A magic square is an n * n matrix of the integers 1 to n2 such that the sum of each row, column, and diagonal is the same. The figure given below is an example of magic square for case n=5. In this example, the common sum is 65.
 

Theory 
A magic square is a square matrix where the sum of each row, column, and diagonal 
is equal. This program implements an algorithm to generate a magic square for odd
sized matrices and then verifies its properties.

Algorithm 
 
Create an empty magic square: 
• Create a square matrix of size size x size filled with zeros. 
 
 Initialize starting position: 
• Set the starting row to the middle row of the magic square. 
• Set the starting column to the last column of the magic square. 
 
Fill the magic square: 
• Iterate through numbers from 1 to size * size: 
o Place the current number in the current position. 
o Calculate the next row and column based on the magic square pattern: 
▪ Move one row up and one column right. 
o If the next position is out of bounds or already filled: 
▪ Move one row down. 
o Update the current row and column. 
 
Print the magic square: 
• Calculate the sum of each row or column. 
• Print the magic square in a formatted manner.


# A function to generate odd sized magic squares
def generate_Magic_Square(size):
    magic_square=[[0 for x in range(size)] for y in range(size)]

    # Initializing first position of matrix
    i=int(size/2) # First row
    j=size-1      # Middle column

    # Fill the magic square by placing values at appropriate position
    for num in range(1, size*size + 1): # range(start, end, step)
        magic_square[i][j] = num
        new_i, new_j = (i - 1) % size, (j + 1) % size # move to next position: up & right
        
        # Check if the next cell is already filled or out of bounds
        if magic_square[new_i][new_j] != 0:
            new_i = (i + 1) % size  # Move down
            new_j = j               # Stay in the same column
        
        i, j = new_i, new_j


    # Printing of magic square
    sum=size*(size*size+1)/2
    print("Sum of each row or column is : ",sum)
    print("Magic Square of size",size,"*",size,"is : \n")

    for i in range(0,size):
        for j in range(0,size):
            print(' %2d ' % (magic_square[i][j]),end=' | ')

            # To display magic square in matrix form
            if j==size-1:
                print()

#<------------------------------------------------------------------------------------------------->

# We are using Siamese method for odd-orders (only)
while True:
    n=int(input("\nEnter the size of the MAGIC SQUARE : "))
    if n%2==0:
        s=int(input("Please enter an ODD Number (for example - 3,5,7,9,....) : "))
        generate_Magic_Square(s)
    else:
        generate_Magic_Square(n)

    # generate new Magic Square
    a = input("\nDo you want to print Magic Square of some other size (y/N) : ")
    if a=='n' or a=='N' or a==' ' or a=='':
      break

#-----------------------------------output-----------------------
Enter the size of the MAGIC SQUARE : 5
Sum of each row or column is :  65.0
Magic Square of size 5 * 5 is : 

 21  |   3  |  10  |  12  |  19  |
  2  |   9  |  11  |  18  |  25  |
  8  |  15  |  17  |  24  |   1  |
 14  |  16  |  23  |   5  |   7  |
 20  |  22  |   4  |   6  |  13  |

Do you want to print Magic Square of some other size (y/N) : y

Enter the size of the MAGIC SQUARE : 
 
 
 
 

 
 
    