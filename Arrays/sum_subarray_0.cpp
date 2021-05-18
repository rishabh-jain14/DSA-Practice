//CPP Program to print 'Yes' if any subarray has a sum of 0

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <unordered_set>
using namespace std;

int main()
{
    vector<int> v;
    cout<<"Enter the values in the array for finding the subarray with a sum of zero. Press Q/q to stop entering values.\n";
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
    unordered_set<int> sumSet;
    int i , sum = 0;
    for(i = 0; i<v.size(); i++)
    {
        sum += v[i];
        if(v[i] == 0 || sum == 0 || sumSet.find(sum) != sumSet.end())
        {
            cout<<"Yes";
            getch();
            return 0;
        }
        sumSet.insert(sum);
    }
    cout<<"No";
    getch();
    return 0;
    }