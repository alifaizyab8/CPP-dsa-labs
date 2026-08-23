#include <iostream>
#include <cmath>
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
void copyStr(char *destination, const char *source)
{
    while ((*destination++ = *source++))
        ;
}
int numberOfConcats(int parent_len, int required_len)
{
    
    return ceil((double)(required_len) / parent_len) - 1;
}
void repeatedConcat(char str[], int req_len)
{
    char s[100];
    copyStr(s, str);
    int concatNumber = numberOfConcats(length(str), req_len);
    for (int i = 0; i < concatNumber; i++)
    {
        concat(str, s);
    }
    cout << str << endl;
    cout << length(str) << "<<-- achieved lenght, " << req_len << "<<-- required length" << endl;
}
int main()
{
    char s[100] = "Hello World";
    repeatedConcat(s, 12);
}