#include <iostream>
using namespace std;

const int MAX = 150;

void inputMatrix(int mat[MAX][MAX], int rows, int cols) {
    cout << "Enter elements of matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX],
                      int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        cout << "Matrix multiplication not possible" << endl;
        return;
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "Result of multiplication (" << r1 << "x" << c2 << "):" << endl;
    printMatrix(C, r1, c2);
}

void transposeMatrix(int A[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transpose[i][j] = A[j][i];
        }
    }
    cout << "Transpose of first matrix (" << cols << "x" << rows << "):" << endl;
    printMatrix(transpose, cols, rows);
}

int main() {
    int r1, c1, r2, c2;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], transposeA[MAX][MAX];

    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    inputMatrix(A, r1, c1);
    inputMatrix(B, r2, c2);

    multiplyMatrices(A, B, C, r1, c1, r2, c2);
    transposeMatrix(A, transposeA, r1, c1);

    return 0;
}

