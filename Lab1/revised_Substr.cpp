
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
char *substr(const char s[], int ip, int len)
{
    static char result[100];

    int strLen = length(s);

    // Error checking
    if (ip < 0 || ip >= strLen)
    {
        cout << "Error: Starting index is out of range." << endl;
        result[0] = '\0';
        return result;
    }

    if (len < 0 || ip + len > strLen)
    {
        cout << "Error: Substring length is out of range." << endl;
        result[0] = '\0';
        return result;
    }

    int count = 0;

    while (count < len)
    {
        result[count] = s[ip];
        count++;
        ip++;
    }

    result[count] = '\0';

    return result;
}