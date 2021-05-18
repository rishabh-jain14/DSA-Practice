//CPP Program to buy and sell stock

#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

int main()
{
    vector<int> v;
    cout<<"Enter the values in the array for reversal. Press Q/q to stop entering values.\n";
    string st;
    int i = 0;
    int min_ = INT_MAX;
    int temp, ans = 0;
    while(true)
    {
        cin>>st;
        if(st.compare("q") == 0 or st.compare("Q") == 0)
        {
            break;
        }
        else
        {
            temp = stoi(st);
            min_ = min(min_, temp);
            ans = max(ans, temp - min_);
            v.push_back(temp);
        }
    }
    if(v.size() <= 1)
    {
        ans = 0;
    }
    cout<<ans;
    getch();
    return 0;
    
}