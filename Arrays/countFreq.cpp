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
}