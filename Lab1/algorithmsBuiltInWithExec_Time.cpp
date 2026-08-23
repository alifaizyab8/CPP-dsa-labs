#include <iostream>
#include <chrono>
#include<cstring>
using namespace std;

template <typename Function>
void measureTime(Function anyFunction)
{
    auto start = chrono::high_resolution_clock::now();

    anyFunction();

    auto end = chrono::high_resolution_clock::now();

    auto duration =
        chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "Execution time: "
         << duration.count()
         << " nanoseconds\n";
}

// A1: Length using standard library
int length(const char s[])
{
    return strlen(s);
}

// A2: Concatenate using standard library
void concat(char s1[], const char s2[])
{
    strcat(s1, s2);
}

// A3: Substring using standard library
char *substr(const char s[], int ip, int len)
{
    static char result[100];

    strncpy(result, s + ip, len);

    result[len] = '\0';

    return result;
}

// A4: Index using standard library
int index(const char T[], const char P[])
{
    const char *position = strstr(T, P);

    if (position == nullptr)
    {
        return -1;
    }

    return position - T;
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

            int len;

            measureTime([&]()
                        {
                            len = length(s);
                        });

            cout << "Length = " << len << endl;
        }

        else if (choice == 2)
        {
            char s1[200];
            char s2[100];

            cout << "\nEnter first string: ";
            cin.getline(s1, 200);

            cout << "Enter second string: ";
            cin.getline(s2, 100);

            measureTime([&]()
                        {
                            concat(s1, s2);
                        });

            cout << "Concatenated string = "
                 << s1 << endl;
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

            cin.ignore();

            char *substrr;

            measureTime([&]()
                        {
                            substrr = substr(s, ip, len);
                        });

            cout << "Substring = "
                 << substrr << endl;
        }

        else if (choice == 4)
        {
            char T[200];
            char P[100];

            cout << "\nEnter text T: ";
            cin.getline(T, 200);

            cout << "Enter pattern P: ";
            cin.getline(P, 100);

            int result;

            measureTime([&]()
                        {
                            result = index(T, P);
                        });

            if (result == -1)
            {
                cout << "Pattern not found." << endl;
            }
            else
            {
                cout << "Pattern found at index = "
                     << result << endl;
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