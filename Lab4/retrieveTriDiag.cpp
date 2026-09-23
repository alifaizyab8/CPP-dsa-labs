#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 10;

// Retrieve B from U
void retrieveTridiagonal(int B[10][10], int U[], int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (abs(j - k) <= 1)
            {
                int L = 2 * j + k;
                B[j][k] = U[L];
            }
            else
            {
                B[j][k] = 0;
            }
        }
    }
}

// Display matrix B
void displayMatrix(int B[10][10], int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            cout << B[j][k] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n;

    cout << "Enter size of matrix: ";
    cin >> n;

    int U[28];


    int size = 3 * n - 2;

    cout << "Enter " << size << " elements of U:\n";

    for (int i = 0; i < size; i++)
    {
        cin >> U[i];
    }

    int B[10][10];

    // Retrieve B from U
    retrieveTridiagonal(B, U, n);

    cout << "Retrieved Tridiagonal Matrix B:\n";
    displayMatrix(B, n);

    return 0;
}