3. Write a Python program to compute following computation on matrix:
  a) Addition of two matrices	
  b) Subtraction of two matrices


3. Write a Python program to compute following computation on matrix:
c)  Multiplication of two matrices 
d)  Transpose of a matrix


Objectives 
• Create functions to perform matrix addition, subtraction, multiplication, and 
transposition. 
• Implement the functions to handle matrices of compatible dimensions. 
• Test the functions with different matrix inputs. 
 
Theory 
Matrices are rectangular arrays of numbers. Matrix operations involve combining 
matrices according to specific rules. Addition and subtraction require matrices of the 
same dimensions, while multiplication has specific constraints on dimensions. 
Transposition involves swapping rows and columns of a matrix. 

Algorithm 
 
print_matrix(matrix) 
1. Iterate through each row in the matrix. 
2. Convert each row into a string by joining its elements with spaces. 
3. Print the resulting string. 
add_matrices(A, B) 
1. Create a new matrix C with the same dimensions as A and B, initialized with zeros. 
2. Iterate through each element of A and B simultaneously. 
3. Add the corresponding elements of A and B and store the result in C. 
4. Return the resulting matrix C. 
subtract_matrices(A, B) 
1. Create a new matrix C with the same dimensions as A and B, initialized with zeros. 
2. Iterate through each element of A and B simultaneously. 
3. Subtract the corresponding element of B from the corresponding element of A and 
store the result in C. 
4. Return the resulting matrix C. 
multiply_matrices(A, B) 
1. Check if the number of columns in A is equal to the number of rows in B 
(compatibility check). 
2. Create a new matrix C with dimensions rows_A x cols_B, initialized with zeros. 
3. Iterate through each element of C:  
o Calculate the dot product of the corresponding row in A and column in B. 
o Store the result in the corresponding element of C.   



def print_matrix(matrix): 
    
    for row in matrix: 
        print(" ".join(map(str, row)))  # Join elements of the row with space and print 
    print() 
 
def add_matrices(A, B): 
    
    rows = len(A)       # Number of rows in matrix A 
    cols = len(A[0])    # Number of columns in matrix A 
    C = [[0] * cols for _ in range(rows)]  # Initialize result matrix C with zeros 
 
    for i in range(rows): 
        for j in range(cols): 
            C[i][j] = A[i][j] + B[i][j]  # Element-wise addition 
 
    return C 
 
 
 
def subtract_matrices(A, B): 
     
    rows = len(A)       # Number of rows in matrix A 
    cols = len(A[0])    # Number of columns in matrix A 
    C = [[0] * cols for _ in range(rows)]  # Initialize result matrix C with zeros 
 
    for i in range(rows): 
        for j in range(cols): 
            C[i][j] = A[i][j] - B[i][j]  # Element-wise subtraction 
 
    return C 
 

def multiply_matrices(A, B): 
 
    rows_A = len(A)         # Number of rows in matrix A 
    cols_A = len(A[0])      # Number of columns in matrix A 
    rows_B = len(B)         # Number of rows in matrix B 
    cols_B = len(B[0])      # Number of columns in matrix B 
 
    if cols_A != rows_B: 
        raise ValueError("Incompatible matrices for multiplication")  # Check for compatibility 
 
    # Initialize result matrix C with zeros 
    C = [[0] * cols_B for _ in range(rows_A)] 
 
    for i in range(rows_A): 
        for j in range(cols_B): 
            for k in range(cols_A): 
                C[i][j] += A[i][k] * B[k][j]  # Matrix multiplication logic 
 
    return C 
 

 
def transpose_matrix(A): 
    rows = len(A)         # Number of rows in matrix A 
    cols = len(A[0])      # Number of columns in matrix A 
 
    # Initialize result matrix B with zeros 
    B = [[0] * rows for _ in range(cols)] 
 
    for i in range(rows): 
        for j in range(cols): 
            B[j][i] = A[i][j]  # Transpose operation 
 
    return B 
 

 
# Example matrices 
A = [ 
    [1, 2, 3], 
    [4, 5, 6] 
] 
B = [ 
    [7, 8, 9], 
    [10, 11, 12] 
    ] 
 
print("Matrix A:") 
print_matrix(A)  # Print matrix A 
print("Matrix B:") 
print_matrix(B)  # Print matrix B 
 
# Perform matrix operations 
print("Addition of A and B:") 
C_add = add_matrices(A, B) 
print_matrix(C_add)  # Print result of addition 
 
print("Subtraction of A from B:") 
C_sub = subtract_matrices(A, B) 
print_matrix(C_sub)  # Print result of subtraction 
 
print("Multiplication of A and B:") 
# To demonstrate multiplication, transpose B to make dimensions compatible 
B_T = transpose_matrix(B) 
C_mul = multiply_matrices(A, B_T) 
print_matrix(C_mul)  # Print result of multiplication 
 
print("Transpose of A:") 
C_trans = transpose_matrix(A) 
print_matrix(C_trans)  # Print result of transpose 
