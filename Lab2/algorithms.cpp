#include <iostream>
using namespace std;

char *substr(const char s[], int ip, int len)
{
    // Increased size to handle larger strings safely
    static char result[1000];

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

// Question 1: A1, A2
void ins(char T[], int ip, const char P[])
{
    // 1. Initialize Array
    char temp1[1000] = "";
    char temp2[1000] = "";
    // 2. Concatenating used to copy into temp
    concat(temp1, substr(T, 0, ip));
    concat(temp2, substr(T, ip, length(T) - ip + 1));
    // 3. concatenate(temp1, P)
    concat(temp1, P);
    // 4. concatenate(temp1, temp2)
    concat(temp1, temp2);
    // 5. Copy temp1 into T
    T[0] = '\0';
    concat(T, temp1);
}

void del(char T[], int ip, int L)
{
    char temp1[1000] = "";
    char temp2[1000] = "";

    // 1 & 2: copy substrings
    concat(temp1, substr(T, 0, ip));
    concat(temp2, substr(T, ip + L, length(T) - ip - L + 1));

    // 3. Concatenate Temp1 and Temp2 and Copy to T
    concat(temp1, temp2);

    T[0] = '\0';
    concat(T, temp1);
}
