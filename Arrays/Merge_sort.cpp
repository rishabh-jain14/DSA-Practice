//CPP Program to implemented Merge Sort

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

void Merge(vector<int> &v, int beg, int mid, int end)
{
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int i, j, k;
    vector<int> v_l, v_r;
    for(i = 0; i<n1; i++)
    {
        v_l.push_back(v[beg + i]);
    }
    for(j = 0; j<n2; j++)
    {
        v_r.push_back(v[mid+1+j]);
    }
    i = 0;
    j = 0;
    k = beg;
    while(i < n1 && j < n2)
    {
        if(v_l[i] <= v_r[j])
        {
            v[k] = v_l[i];
            i++;
        }
        else
        {
            v[k] = v_r[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        v[k] = v_l[i];
        k++;
        i++;
    }
    while(j < n2)
    {
        v[k] = v_r[j];
        k++;
        j++;
    }
}

void MergeSort(vector<int> &v, int beg, int end)
{
    if(beg >= end)
    {
        return;
    }
    int mid = (beg+end)/2;
    MergeSort(v, beg, mid);
    MergeSort(v, mid+1, end);
    Merge(v, beg, mid, end);
}

int main()
{
    vector<int> v;
    int i;
    cout<<"Enter the values in the array for Merge sort. Press Q/q to stop entering values.\n";
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
    
    MergeSort(v, 0, v.size()-1);

    cout<<"The sorted array:\t";
    for(i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<'\t';
    }
    getch();
    return 0;
}