#include <iostream>
using namespace std;

int main()
{
    int rA, cA, rB, cB;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> rA >> cA;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> rB >> cB;

    // Validate dimensions
    if (cA != rB)
    {
        cout << "Error: Matrices cannot be multiplied!" << endl;
        cout << "cA != rB" << endl;
        return 0;
    }

    int A[100][100], B[100][100], C[100][100];

    // Input Matrix A
    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cA; j++)
        {
            cin >> A[i][j];
        }
    }

    // Input Matrix B
    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < rB; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            cin >> B[i][j];
        }
    }

    // Initialize C
    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            C[i][j] = 0;
        }
    }

    // Multiply
    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            for (int k = 0; k < cA; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print result
    cout << "Product Matrix:" << endl;

    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}