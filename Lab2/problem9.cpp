/*
Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to
Add two MATRIX objects. Write a main function to implement it.
*/

#include<iostream>

using namespace std;

class Matrix{
    int row, col;
    int **mat;

    public:
        Matrix(int r, int c){
            row = r;
            col = c;
            mat = new int*[r];
            for(int i=0; i<r; i++){
                mat[i] = new int[c];
                for(int j=0; j<c; j++){
                    mat[i][j] = 0;
                }
            } 
        }
        
        ~Matrix(){
            for(int i=0; i<row; i++){
                delete[] mat[i];
            }
            delete[] mat;
        }

        void input(){
            if(row==0 && col==0){
                cout << "Enter the dimensions of the matrix(row and col): ";
                cin >> row >> col;
            }
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    cin >> mat[i][j];
                }
            }
        }

        Matrix operator+(Matrix& o){
            if(row==o.row && col==o.col){
                Matrix result(row, col);
                for(int i=0; i<row; i++){
                    for(int j=0; j<col; j++){
                        result.row = row + o.row;
                        result.col = col + o.col;

                    }
                }
                return result;
            } else {
                cout<<"Matrix dimensions should be equal for addition";
                return Matrix(0, 0);
            }
        }

        void show(){
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    cout << mat[i][j] << "\t";
                }
                cout << endl;
            }
        }
};

int main(){
    Matrix m(3, 3);
    Matrix m2(3, 3);
    Matrix m3(3, 3);
    cout << "Enter the matrix A: ";
    m.input();
    cout << "Enter the matrix B: ";
    m2.input();
    m3 = m + m2;
    m3.show();
    return 0;
}