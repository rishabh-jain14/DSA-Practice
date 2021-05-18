//CPP Arrays #1 Array Reversal

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

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
    int i;
    for(i = 0; i<v.size()/2; i++)
    {   
        swap(v[i], v[v.size()-1-i]);
    }
    cout<<"the reverse array is as follows:\n";
    for(i = 0; i<v.size(); i++)
    {   
        cout<<v[i]<<'\t';
    }
    getch();
}