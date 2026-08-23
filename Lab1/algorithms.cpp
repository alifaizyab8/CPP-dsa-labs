#include <iostream>
using namespace std;

int length(const char s[])
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

void concat(char s1[], const char s2[])
{
    int s1_len = length(s1);
    int s2_len = length(s2);
    int count = 0;
    while (count <= s2_len)
    {
        s1[s1_len] = s2[count++];
        s1_len++;
    }
}
char *substr(char s[], int ip, int len)
{
    int start = ip;
    int count = 0;
    static char st[100];
    while (count < len)
    {
        st[count++] = s[start++];
    }
    st[count] = '\0';
    return st;
}
int index(char s1[], char substr[])
{
    int substr_len = length(substr);
    int last = length(s1) - substr_len + 1;
    for (int i = 0; i < last; i++)
    {
        int j;
        for (j = 0; j < substr_len; j++)
        {
            if (s1[i + j] != substr[j])
            {
                break;
            }
        }
        if (j == substr_len)
        {
            return i;
        }
    }
    return -1;
}
int main() {}
