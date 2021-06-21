//-----------------------------------------------------------------------
// File: MatrixMultiplication.cpp
// Summary: A program that reads two matrices and prints a third one by
// multiplying them
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2021-1-1 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

const int MAXDIM = 5; // max number of rows and columns supported by program

typedef double Matrix[MAXDIM][MAXDIM];

// Prototypes
void readMatrix(Matrix M, int row, int col);
// Reads a matrix with row number of rows and col number of columns

void multMatrix(const Matrix A, const Matrix B, Matrix C, int m, int n, int p);
// Multiplies m•p-matrix A with p•n matrix B and stores the result in the m•n-matrix C

void printMatrix(const Matrix M, int row, int col);
// Prints the matrix M

int main()
{
    // Define and initialise variables
    int rowA = 0;
    int colA = 0;
    int rowB = 0;
    int colB = 0;
    Matrix mA;
    Matrix mB;
    Matrix mC;
    char answer;

    do
    {
        system("CLS");
        cout << "Matrix Multiplication" << endl;
        cout << "=====================" << endl;
        
        // Read the first matrix
        cout << "Enter dimensions of Matrix A (row x col) with space between: ";
        cin >> rowA;
        cin >> colA;
        cout << "Enter matrix A in free format: " << endl;
        readMatrix(mA,rowA,colA);

        // Read the second matrix
        cout << "Enter dimensions of Matrix B (row x col) with space between: ";
        cin >> rowB;
        cin >> colB;
        cout << "Enter matrix B in free format: " << endl;
        readMatrix(mB,rowB,colB);


        cout << "------------------------------------------------" << endl;
        cout << "ANSWER" << endl;

        // If the conditions are met proceed with multiplication and printing
        if (colA == rowB)
        {
            multMatrix(mA,mB,mC,rowA,colB,rowB);
            printMatrix(mC,rowA,colB);
        }

        // If conditions are not met print error message
        if (colA != rowB)
        {
            cout << "Cannot perform multiplication between the two matrices, ";
            cout << "columns of matrix A must be equal to rows of matrix B" << endl;
        }
        
        
        cout << "One more time (Y/N)?: ";
        cin >> answer;
    } while (toupper(answer) == 'Y');
    
    return 0;
}

// A function with a nested for-loop for reading each value of the matrix
void readMatrix(Matrix M, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> M[i][j];
        }
    }
    M[row][col];  
}

// A function that multiplies the  elements of two matrices and allocate the results in a new matrix
void multMatrix(const Matrix A, const Matrix B, Matrix C, int m, int n, int p)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < p; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// A function for printing a matrix
void printMatrix(const Matrix M, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << fixed << setprecision(1) << showpoint;
            cout << setw(10) << M[i][j];
        }
        cout << endl;
    }
}
