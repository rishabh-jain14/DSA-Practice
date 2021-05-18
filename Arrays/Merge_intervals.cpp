#include<iostream>
#include<conio.h>
#include<vector>
#include <string>
#include <algorithm>

using namespace std;

static bool sortfunc(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}

int main()
{
    vector<vector <int>> v;
    vector<vector <int>> ans;
    cout<<"Enter the values in the array for reversal. Press Q/q to stop entering values.\n";
    string st;
    int i = 1, j;
    vector<int> temp;
    while(true)
    {
        cin>>st;
        if(st.compare("q") == 0 or st.compare("Q") == 0)
        {
            break;
        }
        else
        {
            if(i%2 != 0)
            {
                i++;
                temp.push_back(stoi(st));
            }
            else
            {
                temp.push_back(stoi(st));
                v.push_back(temp);
                temp.clear();
                i = 1;
            }
            
        }
    }

    sort(v.begin(), v.end(), sortfunc);

    for(i = 0; i<v.size(); i++)
    {
        for(j = 0; j<2; j++)
        {
            cout<<v[i][j]<<'\t';
        }
        cout<<'\n';
    }
    cout<<"\n\n\n";
    int start = v[0][0], end = v[0][1];
    vector<int> pot;
    for(i = 1; i<v.size(); i++)
    {
                                                    //start = v[i-1][0]
        if(v[i][0] <= end)                          //end = v[i-1][1]
        {
            if(v[i][1] > end)
            {
                end = v[i][1];
            }
        }
        else
        {
            pot.push_back(start);
            pot.push_back(end);
            ans.push_back(pot);
            pot.clear();
            start = v[i][0];
            end = v[i][1];
        }
    }
    pot.push_back(start);
    pot.push_back(end);
    ans.push_back(pot);

    for(i = 0; i<ans.size(); i++)
    {
        for(j = 0; j<2; j++)
        {
            cout<<ans[i][j]<<'\t';
        }
        cout<<'\n';
    }
    getch();
    return 0;
}


//end of program