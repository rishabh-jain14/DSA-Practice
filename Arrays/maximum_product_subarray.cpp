//CPP Pogram to print the factorial of a big integer

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

long long maxPro(vector<int> &v, int n)
{
    long long maxVal = v[0];
    long long minVal = v[0];
    long long maxProduct = v[0];
    
    for(int i = 1; i < n; i++)
    {
        if(v[i] < 0)
        {
            swap(maxVal, minVal);
        }
        maxVal = max((long long)v[i], v[i] * maxVal);
        minVal = min((long long)v[i], v[i] * minVal);
        
        maxProduct = max(maxProduct, maxVal);
    }
    return maxProduct;
}

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

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
    long long maxProduct = maxPro(v, v.size());
    cout<<"\nThe maximum product is : "<<maxProduct;
    getch();
    return 0;
}