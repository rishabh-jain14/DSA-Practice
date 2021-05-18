#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

int find(vector<int> &v, int chance, int start)
{   
    if(chance == 1)
    {
        while(start<v.size())
        {
            if(v[start] < 0)
            {
                return start;            
            }
            start++;
        }
    }
    else
    {
        while(start<v.size())
        {
            if(v[start] >= 0)
            {
                return start;
            }
            start++;
        }
    }
    return -1;
}

void rotate(vector<int> &v,int temp1, int start, int end)
{
    for(int i = end; i>=start; i--)
    {
        if(i == start)
        {
            v[i] = temp1;
        }
        else
        {
            v[i] = v[i-1];
        }
    }
}

int main()
{
    vector<int> v;
    cout<<"Enter the values in the array for reversal. Press Q/q to stop entering values.\n";
    string st;
    while(true)
    {
        cin>>st;
        if(st.compare("q") == 0 or st.compare("Q") == 0)
        {
            break;
        }
        else
        {
            v.push_back(stoi(st));
        }
    }
    int temp1, temp2, chance = 1, fixation;
    int i, ind;
    for(i = 0; i<v.size(); i++)
    {
        ind = find(v, chance, i);
        if(ind == i)
        {
            chance = (chance+1)%2;
            continue;
        }
        else if(ind == -1)
        {
            break;
        }
        else
        {
            temp1 = v[i];
            v[i] = v[ind];
            rotate(v, temp1, i+1, ind);
            chance = (chance+1)%2;
        }
    }
    for(i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<'\t';
    }
    getch();
    return 0;
}