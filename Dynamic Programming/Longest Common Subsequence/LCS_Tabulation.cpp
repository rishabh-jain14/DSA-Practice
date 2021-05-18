#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>


using namespace std;

int T[101][101];

// int find_lcs(string s1, string s2, int n1, int n2)
// {
//     if(n1 == 0 || n2 == 0)
//     {
//         return 0;
//     }
//     if(T[n1][n2] != -1)
//     {
//         return T[n1][n2];
//     }
//     if(s1[n1] == s2[n2])
//     {
//         return T[n1][n2] = 1 + find_lcs(s1, s2, n1-1, n2-1);
//     }
//     else
//     {
//         return T[n1][n2] = max(find_lcs(s1, s2, n1-1, n2), find_lcs(s1, s2, n1, n2-1));
//     }
// }

int main()
{
    int n1, n2;
    string s1, s2;
    cin>>s1;
    cin>>s2;
    n1 = s1.length();
    n2 = s2.length();
    int i, j;
    for(i = 0; i<=n1; i++)
    {
        for(j = 0; j <= n2; j++)
        {
            if(i==0 || j == 0)
            {
                T[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1])
            {
                T[i][j] = 1 + T[i-1][j-1];
            }
            else
            {
                T[i][j] = max(T[i-1][j], T[i][j-1]);
            }
        }
    }
    cout<<T[n1][n2];
    getch();
    return 0;
}