#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>


using namespace std;

int T[100][100];

int find_lcs(string s1, string s2, int n1, int n2)
{
    if(n1 == 0 || n2 == 0)
    {
        return 0;
    }
    if(T[n1][n2] != -1)
    {
        return T[n1][n2];
    }
    if(s1[n1] == s2[n2])
    {
        return T[n1][n2] = 1 + find_lcs(s1, s2, n1-1, n2-1);
    }
    else
    {
        return T[n1][n2] = max(find_lcs(s1, s2, n1-1, n2), find_lcs(s1, s2, n1, n2-1));
    }
}

int main()
{
    memset(T, -1, sizeof(T));
    int n1, n2;
    string s1, s2;
    cin>>s1;
    cin>>s2;
    n1 = s1.length();
    n2 = s2.length();
    int l = find_lcs(s1, s2, n1, n2);
    cout<<l;
    getch();
    return 0;
}