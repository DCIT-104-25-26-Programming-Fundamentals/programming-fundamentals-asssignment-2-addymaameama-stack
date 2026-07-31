// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


  #include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int m[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> m[i][j];
        }
    }
}

void printMatrix(int m[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << setw(5) << m[i][j];
        }
        cout << endl;
    }
}

int main() {
    // PART A - Transpose
    int r, c;
    int mat[10][10];
    int trans[10][10];

    cout << "PART A - Transpose" << endl;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    readMatrix(mat, r, c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            trans[j][i] = mat[i][j];
        }
    }

    cout << endl << "Original Matrix:" << endl;
    printMatrix(mat, r, c);
    cout << endl << "Transposed Matrix:" << endl;
    printMatrix(trans, c, r);

    // PART B - Addition
    int r2, c2;
    int a[10][10], b[10][10], sum[10][10];

    cout << endl << "PART B - Addition" << endl;
    cout << "Enter number of rows: ";
    cin >> r2;
    cout << "Enter number of columns: ";
    cin >> c2;

    cout << "Matrix A:" << endl;
    readMatrix(a, r2, c2);
    cout << "Matrix B:" << endl;
    readMatrix(b, r2, c2);

    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << endl << "Sum Matrix:" << endl;
    printMatrix(sum, r2, c2);

    // PART C - Multiplication
    int rA, cA, rB, cB;
    int matA[10][10], matB[10][10], product[10][10];

    cout << endl << "PART C - Multiplication" << endl;
    cout << "Enter rows of Matrix A: ";
    cin >> rA;
    cout << "Enter columns of Matrix A: ";
    cin >> cA;
    cout << "Enter rows of Matrix B: ";
    cin >> rB;
    cout << "Enter columns of Matrix B: ";
    cin >> cB;

    if (cA != rB) {
        cout << "Error: Columns of A must equal rows of B." << endl;
        return 0;
    }

    cout << "Matrix A:" << endl;
    readMatrix(matA, rA, cA);
    cout << "Matrix B:" << endl;
    readMatrix(matB, rB, cB);

    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            int total = 0;
            for (int k = 0; k < cA; k++) {
                total = total + matA[i][k] * matB[k][j];
            }
            product[i][j] = total;
        }
    }

    cout << endl << "Product Matrix:" << endl;
    printMatrix(product, rA, cB);

    return 0;
}