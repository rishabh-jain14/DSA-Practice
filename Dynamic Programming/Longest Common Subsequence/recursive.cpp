#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int lcs(string s1, string s2, int n1, int n2)
{
    if(n1 == 0 || n2 == 0)
    {
        return 0;
    }
    if(s1[n1-1] == s2[n2-1])
    {
        return (1 + lcs(s1, s2, n1-1, n2-1));
    }
    else
    {
        return max(lcs(s1, s2, n1-1, n2), lcs(s1, s2, n1, n2-1));
    }
}

int main()
{
    string s1, s2;
    cin>>s1;
    cin>>s2;
    int n1 = s1.length();
    int n2 = s2.length();

    int l = lcs(s1, s2, n1, n2);
    cout<<l;
    getch();
    return 0;
}