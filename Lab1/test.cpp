#include<iostream>
using namespace std;
int length(const char s[])
{
    cout<<"Function evaluated"<<endl;
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}
int main(){
    char s[15] = "World Hello";
    for (int i = 0; i < length(s) -1; i++)
    {
        cout<<"Loop ran "<<i<<endl;
    }
    

}