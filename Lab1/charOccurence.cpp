#include<iostream>
using namespace std;
void charOccurrences(const char S[], char a)
{
    int i = 0;
    cout << "Occurences found at: ";
    while (S[i] != '\0')
    {
         
        if (S[i] == a)
        {
            cout << i << " ";
        }

        i++;
    }
    cout << " indicies.";
}
int main()
{
    charOccurrences("Hello World, how are you ?", 'o');
}