#include <iostream>
#include <conio.h>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr;
    cout<<"Enter the values in the array for reversal. Press Q/q to stop entering values.\n";
    string st;
    unordered_set<int> S;
    while(true)
    {
        cin>>st;
        if(st.compare("q") == 0 or st.compare("Q") == 0)
        {
            break;
        }
        else
        {
            arr.push_back(stoi(st));
            S.insert(stoi(st));
        }
    }
    int ans = 0;

    for(int i = 0; i<arr.size(); i++)
    {
        if(S.find(arr[i] - 1)== S.end())
        {
            int j = arr[i];
            while(S.find(j+1) != S.end())
            {
                j++;
            }
            ans = max(ans, j - arr[i] + 1);
        }
    }
    cout<<ans;
    getch();
}