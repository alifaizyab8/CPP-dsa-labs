#include <iostream>
    using namespace std;

const int MAX = 10;
void storeTriangular(int A[10][10], int U[], int n)
{
    int i = 0;

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k <= j; k++)
        {
            U[i] = A[j][k];
            i++;
        }
    }
}
void retrieveTriangular(int A[10][10], int U[], int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (k > j)
            {
                A[j][k] = 0;
            }
            else
            {
                A[j][k] = U[(j * (j + 1)) / 2 + k];
            }
        }
    }
}
void displayMatrix(int A[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}
void displayArray(int U[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << U[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;

    cout << "Enter size of matrix: ";
    cin >> n;

    int A[10][10];
    int U[55];
    int retrieved[10][10];
    cout << "Enter " << n << " x " << n << " matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    storeTriangular(A, U, n);
    int totalElements = n * (n + 1) / 2;
    cout << "Original Matrix:\n";
    displayMatrix(A, n);

    cout << "Stored Array U:\n";
    displayArray(U, totalElements);

    retrieveTriangular(retrieved, U, n);

    cout << "Retrieved Matrix:\n";
    displayMatrix(retrieved, n);

    return 0;
}
