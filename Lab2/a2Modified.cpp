#include <iostream>
using namespace std;
#include "algorithms.cpp"
void del_all_occurence(char T[], const char P[])
{
    int L = length(P);
    int ip = index(T, P);
    while (ip != -1)
    {
        del(T, ip, L);
        ip = index(T, P); // Find next occurrence
    }
}
int main()
{
    cout << "========== LAB 2 EXERCISE SHEET ==========\n\n";

    // --- Q1(a): Test Algorithm A1 ---
    // Note: arrays sized to 1000 to prevent out-of-bounds errors when appending
    char T1[1000] = "The founder of our country was Quaid-e-Azam";
    cout << "Q1(a) Insertion Test:\n";
    cout << "Original T: " << T1 << "\n";
    ins(T1, 12, "and first Governor General "); // Added a trailing space for readability
    cout << "Result T  : " << T1 << "\n\n";

    // --- Q1(b): Test Algorithm A2 ---
    char T2[1000] = "Database Management Systems";
    cout << "Q1(b) Deletion Test:\n";
    cout << "Original T: " << T2 << "\n";
    del(T2, 9, 10);
    cout << "Result T  : " << T2 << "\n\n";

    // --- Q2: Test Delete All Occurrences ---
    char T3[1000] = "apple banana apple orange apple mango peach apple pineapple ";
    cout << "Q2 Delete All Occurrences Test:\n";
    cout << "Original T: " << T3 << "\n";
    cout << "Deleting pattern 'apple '\n";
    del_all_occurence(T3, "apple ");
    cout << "Result T  : " << T3 << "\n\n";

    return 0;
}