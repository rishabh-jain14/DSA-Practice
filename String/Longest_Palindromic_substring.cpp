#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
    string S;
    cout<<"Please enter a string : ";
    cin>>S;

    int i, j = 0;
    int maximum = 1;
    int start_ind = 0;
    int len = S.length();
    int begin, end;
    for(i = 1; i<=len; i++)
    {
        begin = i-1;
        end = i;
        while(S[begin] == S[end] && begin >= 0 && end < len)
        {
            j = end - begin + 1;
            if(maximum < j)
            {
                maximum = j;
                start_ind = begin;
            }
            end++;
            begin--;
        }
        begin = i-1;
        end = i+1;
        while(S[begin] == S[end] && begin >= 0 && end < len)
        {
            j = end - begin + 1;
            if(maximum < j)
            {
                maximum = j;
                start_ind = begin;
            }
            end++;
            begin--;
        }
    }
    cout<<S.substr(start_ind, maximum);
    getch();
    return 0;
}

//End of program