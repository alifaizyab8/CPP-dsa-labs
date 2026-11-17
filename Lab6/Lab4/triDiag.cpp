#include <iostream>
using namespace std;

const int MAX = 10;

void storeTridiagonal(int B[10][10], int U[], int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            int temp = j-k;
            if (abs(temp) <= 1)
            {
                int L = 2 * j + k;
                U[L] = B[j][k];
            }
        }
    }
}
void displayU(int U[], int size)
{
    cout << "Stored array U:\n";

    for (int i = 0; i < size; i++)
    {
        cout << "U[" << i << "] = " << U[i] << endl;
    }
}
int main()
{
    int n;

    cout << "Enter size of matrix: ";
    cin >> n;

    int B[10][10];
    int U[28] = {0};

    cout << "Enter " << n << " x " << n << " matrix: "<<endl;

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            cin >> B[j][k];
        }
    }
    storeTridiagonal(B, U, n);
    int size = 3 * n - 2;
    displayU(U, size);
    return 0;
}