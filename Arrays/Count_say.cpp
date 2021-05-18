#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

string count_say(int num)
{
    string temp, str = "", occur, spare;
    int l, i, j, lch;
    int start = 0;
    char ch;
    if(num == 1)
        return "1";
    else
    {
        temp = count_say(num-1);
        l = temp.size();
        ch = temp[0];
        j = 1;          ///no. of ooccurences of ch
        for(i = 1; i<l; i++)
        {
            if(ch == temp[i])
            {
                j++;
            }
            else
            {
                occur = to_string(j);
                lch = occur.size();
                str.insert(start, occur);
                spare = ch;
                str.insert(start+ lch, spare);
                occur.clear();
                spare.clear();
                start = start + lch + 1;
                ch = temp[i];
                j = 1;
            }
        }
        occur = to_string(j);
        lch = occur.size();
        str.insert(start, occur);
        spare = ch;
        str.insert(start+ lch, spare);
        return str;
    }
}

int main()
{
    vector<int> v, v_out;
    int n;
    cout<<"Enter the number.\n";
    cin>>n;
    string ans;
    ans = count_say(n);
    cout<<ans;
    getch();
    return 0;
}