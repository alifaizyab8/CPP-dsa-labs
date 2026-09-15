#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int arr[100][100];

public:
    void input();
    void display();
    friend Matrix operator*(Matrix A, Matrix B);
};
void Matrix::input()
{

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
}
void Matrix::display()
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
Matrix operator*(Matrix A, Matrix B)
{
    if (A.cols != B.rows)
    {
        cout << "Error: Columns and Rows dont match of respective matrices" << endl;

        Matrix result;
        result.rows = 0;
        result.cols = 0;

        return result;
    }

    Matrix result;
    result.rows = A.rows;
    result.cols = B.cols;
    for (int i = 0; i < result.rows; i++)
    {
        for (int j = 0; j < result.cols; j++)
        {
            result.arr[i][j] = 0;
        }
    }
    for (int i = 0; i < A.rows; i++)
    {

        for (int j = 0; j < B.cols; j++)
        {

            for (int k = 0; k < A.cols; k++)
            {

                result.arr[i][j] +=
                    A.arr[i][k] * B.arr[k][j];
            }
        }
    }

    return result;
}

int main()
{
    Matrix A, B, C;
    cout << "Enter Matrix A:\n";
    A.input();
    cout << "\nEnter Matrix B:\n";
    B.input();
    C = A * B;
    cout << "\nResult:\n";
    C.display();
    return 0;
}