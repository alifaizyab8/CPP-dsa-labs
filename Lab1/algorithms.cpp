#include <iostream>
using namespace std;

// Algorithm A1: Length
int length(const char s[])
{
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}

// Algorithm A2: Concatenate
void concat(char s1[], const char s2[])
{
    int s1_len = length(s1);
    int s2_len = length(s2);

    int count = 0;

    while (count <= s2_len)
    {
        s1[s1_len] = s2[count];
        s1_len++;
        count++;
    }
}

// Algorithm A3: Substring
char *substr(const char s[], int ip, int len)
{
    static char result[100];

    int count = 0;

    while (count < len && s[ip] != '\0')
    {
        result[count] = s[ip];
        count++;
        ip++;
    }

    result[count] = '\0';

    return result;
}

// Algorithm A4: Index
int index(const char T[], const char P[])
{
    int p = length(P);
    int t = length(T);

    int max = t - p + 1;

    for (int i = 0; i < max; i++)
    {
        int j;

        for (j = 0; j < p; j++)
        {
            if (P[j] != T[i + j])
            {
                break;
            }
        }

        if (j == p)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int choice;

    do
    {
        cout << "\n========== STRING ALGORITHMS ==========\n";
        cout << "1. A1 - Length\n";
        cout << "2. A2 - Concatenate\n";
        cout << "3. A3 - Substring\n";
        cout << "4. A4 - Index\n";
        cout << "5. Exit\n";
        cout << "=======================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        if (choice == 1)
        {
            char s[200];

            cout << "\nEnter a string: ";
            cin.getline(s, 200);

            cout << "Length = " << length(s) << endl;
        }

        else if (choice == 2)
        {
            char s1[200];
            char s2[100];

            cout << "\nEnter first string: ";
            cin.getline(s1, 200);

            cout << "Enter second string: ";
            cin.getline(s2, 100);

            concat(s1, s2);

            cout << "Concatenated string = " << s1 << endl;
        }

        else if (choice == 3)
        {
            char s[200];
            int ip;
            int len;

            cout << "\nEnter string: ";
            cin.getline(s, 200);

            cout << "Enter starting index (ip): ";
            cin >> ip;

            cout << "Enter length: ";
            cin >> len;

            cout << "Substring = " << substr(s, ip, len) << endl;
        }

        else if (choice == 4)
        {
            char T[200];
            char P[100];

            cout << "\nEnter text T: ";
            cin.getline(T, 200);

            cout << "Enter pattern P: ";
            cin.getline(P, 100);

            int result = index(T, P);

            if (result == -1)
            {
                cout << "Pattern not found." << endl;
            }
            else
            {
                cout << "Pattern found at index = " << result << endl;
            }
        }

        else if (choice == 5)
        {
            cout << "\nProgram terminated.\n";
        }

        else
        {
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}





