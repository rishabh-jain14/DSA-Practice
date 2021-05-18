//CPP Program to cyclically rotate an array

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
    vector<int> v, v_out;
    cout<<"Enter the values in the array assortment. Press Q/q to stop entering values.\n";
    string st;
    int n;
    cin>>n;
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
    int i, j = 0, k;
    for(i = 0; i<3; i++)
    {
        j = 0;
        while(j != v.size())
        {
            if(v[j] == i)
            {
                v_out.push_back(v[j]);
                v.erase(v.begin()+j);
            }
            else
            {
                j++;
            }
        }
    }
    
    cout<<"The sorted array:\t";
    for(i = 0; i<v_out.size(); i++)
    {
        cout<<v_out[i]<<'\t';
    }
    getch();
}