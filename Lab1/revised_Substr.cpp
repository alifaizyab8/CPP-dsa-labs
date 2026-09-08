
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
int main()
{
    const char str[] = "Hello World";

    // 1. Valid
    cout << substr(str, 0, 5) << endl;

    // 2. Starting index is negative
    cout << substr(str, -1, 5) << endl;

    // 3. Starting index is equal to string length
    cout << substr(str, 11, 2) << endl;

    // 4. Length is negative
    cout << substr(str, 2, -5) << endl;

    // 5. Substring goes beyond the string
    cout << substr(str, 8, 10) << endl;

    return 0;
}