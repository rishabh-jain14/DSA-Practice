#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <conio.h>


using namespace std;

int T[101][101];
vector<char> res;

void reconstruct(string s1, string s2, int i, int j)
{
    if(i == -1 || j== -1)
    {
        return;
    }
    else if(s1[i-1] == s2[j-1])
    {
        reconstruct(s1, s2, i-1, j-1);
        res.push_back(s1[i]);
    }
    else if(T[i][j] == T[i-1][j])
    {
        reconstruct(s1, s2, i-1, j);
    }
    else
    {
        reconstruct(s1, s2, i, j-1);
    }
}
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
    cout<<T[n1][n2]<<'\n';
    reconstruct(s1, s2, n1, n2);
    for(i = 0; i<res.size(); i++)
    {
        cout<<res[i];
    }
    getch();
    return 0;
}