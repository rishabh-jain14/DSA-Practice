//CPP Pogram to print the factorial of a big integer

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

vector<int> factorial(int n)
{
    int x[3000];
    x[0] = 1;
    int x_size = 1;
    int carry, res, i, j;
    for(i = 2; i<=n; i++)
    {
        carry = 0;
        for(j = 0; j<x_size; j++)
        {
            res = x[j]*i + carry;
            x[j] = res%10;
            carry = res/10;
        }
        while(carry)
        {
            x[x_size] = carry%10;
            carry = carry/10;
            x_size++;
        }
    }
    vector<int> ans;
    for(i = x_size-1; i>=0; i--)
    {
        ans.push_back(x[i]);
    }
    return ans;
}


int main()
{
    int n;
    cout<<"Enter the value of the number : ";
    cin>>n;
    cout<<"\nThe factorial is : ";
    vector<int> v = factorial(n);
    for(int i = 0; i<v.size(); i++)
    {   
        cout<<v[i];
    }
    getch();
}