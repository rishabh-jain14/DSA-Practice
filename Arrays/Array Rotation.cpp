#include<iostream>
#include<conio.h>
#include<vector>

using namespace std;

int main()
{
    vector<int> arr;
    int temp, i, j;
    long n;
    vector<int> atemp;
    while(true)
    {
        cin>>temp;
        if(temp == -1)
        {
            break;
        }
        arr.push_back(temp);
    }

    cout<<"The entered array is : \n";
    int l = arr.size();
    int k = l-1;
    for(i = 0; i<l; i++)
    {
        cout<<arr[i]<<'\t';
    }
    cout<<"\n\nEnter the number of rotations you want : ";
    cin>>n;
    n = n%l;
    for(i = l-n; i<l; i++)
    {
        atemp.push_back(arr[i]);
    }
    for(i = l-n-1; i>=0; i--)
    {
        arr[k--] = arr[i];
    }
    for(i = 0; i<atemp.size(); i++)
    {
        arr[i] = atemp[i];
    }
    cout<<"\n\nThe rotated Array is : \n";
    for(i = 0; i<l; i++)
    {
        cout<<arr[i]<<'\t';
    }
    getch();
    return 0;
}