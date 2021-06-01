#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

void find_sum(int arr[], vector<int> &v, int num)
{
    int i, j, k;
    for(i = 0; i<v.size(); i++)
    {
        for(j = i+1; j<v.size();j++)
        {
            for(k = j+1; k < v.size(); k++)
            {
                if(num == (v[i] + v[j] + v[k]))
                {
                    arr[0] = v[i];
                    arr[1] = v[j];
                    arr[2] = v[k];
                    return;
                }
            }
        }
    }

}

int main()
{
    vector<int> v;
    cout<<"Enter the values in the array. Press Q/q to stop entering values.\n";
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
    cout<<"\nEnter the value of the sum that needs to be analyzed.\n";
    int x;
    cin>>x;
    int arr[3];
    find_sum(arr, v, x);
    for(int i = 0; i<3; i++)
    {
        cout<<arr[i]<<'\t';
    }
    getch();
    return 0;
}