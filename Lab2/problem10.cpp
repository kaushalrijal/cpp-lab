//Modify all member operator functions to friend function.

#include <iostream>

using namespace std;

class Matrix
{
    int row, col;
    int **mat;

public:
    Matrix(int r, int c)
    {
        row = r;
        col = c;
        mat = new int *[r];
        for (int i = 0; i < r; i++)
        {
            mat[i] = new int[c];
            for (int j = 0; j < c; j++)
            {
                mat[i][j] = 0;
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }

    void input()
    {
        if (row == 0 && col == 0)
        {
            cout << "Enter the dimensions of the matrix(row and col): ";
            cin >> row >> col;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> mat[i][j];
            }
        }
    }

    void show()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }

    friend Matrix operator+(Matrix&, Matrix&);
};

Matrix operator+(Matrix &a, Matrix &b) {
    if (a.row == b.row && a.col == b.col) {
        Matrix result(a.row, a.col);
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.col; j++) {
                result.mat[i][j] = a.mat[i][j] + b.mat[i][j];
            }
        }
        return result;
    } else {
        cout << "Matrix dimensions should be equal for addition\n";
    }
}

int main()
{
    int r, c;
    cout << "Enter the rows and columns of the matrices: ";
    cin >> r >> c;
    Matrix m1(r, c);
    Matrix m2(r, c);
    Matrix m3(r, c);
    cout << "Enter the matrix A: ";
    m1.input();
    cout << "Enter the matrix B: ";
    m2.input();
    m3 = m1 + m2;
    cout << "The sum of the matrices is: " << endl;
    m3.show();
    return 0;
}