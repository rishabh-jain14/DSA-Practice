//CPP Program to implement Insertion sort

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
    vector<int> v;
    cout<<"Enter the values in the array for Insertion sort. Press Q/q to stop entering values.\n";
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
    int i, j, temp, key;
    for(i = 1; i<v.size(); i++)
    {
        key = v[i];
        if(v[i] < v[i-1])
        {
            for(j = i-1; j >= 0; j--)
            {
                if(v[j] > key)
                {
                    v[j+1] = v[j];
                }
            }
            v[j+1] = key;
        }
    }
    cout<<"The sorted array:\t";
    for(i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<'\t';
    }
    getch();
    return 0;
}