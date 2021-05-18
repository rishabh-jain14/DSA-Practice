//CPP Program to shift all the negative numbers on the left side of the array without changing their relative order

#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v, v_out;    
    cout<<"Please enter the elements for inserting in the array. Press q/Q to stop entering.";
    string st;
    int i, temp, j;
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
    for(i = 0; i<v.size(); i++)
    {
        if(v[i] < 0)
        {
            v_out.push_back(v[i]);
        }
    }
    for(i = 0; i<v.size(); i++)
    {
        if(v[i] >= 0)
        {
            v_out.push_back(v[i]);
        }
    }
    cout<<"The sorted array:\t";
    for(i = 0; i<v_out.size(); i++)
    {
        cout<<v_out[i]<<'\t';
    }
    getch();
    return 0;
}