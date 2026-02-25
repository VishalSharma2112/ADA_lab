#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// Add two matrices
Matrix addMatrix(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Subtract two matrices (optional, useful for Strassen later)
Matrix subMatrix(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Split matrix into 4 submatrices
void splitMatrix(const Matrix &A, Matrix &A11, Matrix &A12,
                 Matrix &A21, Matrix &A22) {
    int n = A.size();
    int mid = n / 2;

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
        }
    }
}

// Combine 4 submatrices into one
Matrix combineMatrix(Matrix &C11, Matrix &C12,
                     Matrix &C21, Matrix &C22) {
    int mid = C11.size();
    int n = mid * 2;
    Matrix C(n, vector<int>(n));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
    return C;
}

// Recursive Divide & Conquer multiplication
Matrix multiply(Matrix &A, Matrix &B) {
    int n = A.size();

    // Base case
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int mid = n / 2;

    Matrix A11(mid, vector<int>(mid));
    Matrix A12(mid, vector<int>(mid));
    Matrix A21(mid, vector<int>(mid));
    Matrix A22(mid, vector<int>(mid));

    Matrix B11(mid, vector<int>(mid));
    Matrix B12(mid, vector<int>(mid));
    Matrix B21(mid, vector<int>(mid));
    Matrix B22(mid, vector<int>(mid));

    splitMatrix(A, A11, A12, A21, A22);
    splitMatrix(B, B11, B12, B21, B22);

    Matrix C11 = addMatrix(multiply(A11, B11), multiply(A12, B21));
    Matrix C12 = addMatrix(multiply(A11, B12), multiply(A12, B22));
    Matrix C21 = addMatrix(multiply(A21, B11), multiply(A22, B21));
    Matrix C22 = addMatrix(multiply(A21, B12), multiply(A22, B22));

    return combineMatrix(C11, C12, C21, C22);
}

// Utility to print matrix
void printMatrix(const Matrix &M) {
    for (auto &row : M) {
        for (auto &val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    Matrix A = {
        {1, 2},
        {3, 4}
    };

    Matrix B = {
        {5, 6},
        {7, 8}
    };

    Matrix C = multiply(A, B);

    cout << "Result Matrix:\n";
    printMatrix(C);

    return 0;
}