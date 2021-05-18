//CPP Program to implement Quick sort technique

#include<iostream>
#include<conio.h>
#include<vector>
#include<string>

using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &v, int l, int h)
{
    int pivot = v[l];
    int i = l;
    int j = h+1;
    int temp;
    while(i<j)
    {
        do
        {
            i++;
        } while (v[i]<=pivot);
        do
        {
            j--;
        } while (v[j]>pivot);
        if(i<j)
        {
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[l], &v[j]);
    return j;
}

void Quicksort(vector<int> &v, int low, int high)
{
    if(low<high)
    {
        int part = partition(v, low, high);
        Quicksort(v, low, part-1);
        Quicksort(v, part+1, high);
    }
}


int main()
{
    vector<int> v;
    string s;
    int i;
    cout<<"Enter the values for the array. Press Q/q to Stop entering.\n";
    while(true)
    {
        cin>>s;
        if(s.compare("q") == 0 || s.compare("Q") == 0)
        {
            break;
        }
        else
        {
            v.push_back(stoi(s));
        }
    }

    Quicksort(v, 0, v.size()-1);

    cout<<"The sorted array:\t";
    for(i = 0; i<v.size(); i++)
    {
        cout<<v[i]<<'\t';
    }
    getch();
    return 0;
}