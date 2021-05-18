/*CPP Arrays #2 Get minimum and maximum element of an array using minimum number of comparisons.
*/

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
    int i, j, k;
    cout<<"Enter the value of K: ";
    cin>>k;
    for(i = 0; i<v.size()-1; i++)
    {
        for(j = 0; j<v.size()-1-i; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j+1], v[j]);
            }
        }
    }
    cout<<"Maximum element is: "<<v[v.size()-1-(k-1)]<<'\n';
    cout<<"Minimum element is: "<<v[k-1]<<'\n';
    getch();
}