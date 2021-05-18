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
    vector<int> v1, v2, union_v, intersection_v;
    string s;
    int i = 0, j = 0;
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
            v1.push_back(stoi(s));
        }
    }
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
            v2.push_back(stoi(s));
        }
    }

    Quicksort(v1, 0, v1.size()-1);
    Quicksort(v2, 0, v2.size()-1);

    while(i<v1.size() && j<v2.size())
    {
        if(v1[i] < v2[j])
        {
            union_v.push_back(v1[i]);
            i++;
        }
        else if(v1[i] == v2[j])
        {
            intersection_v.push_back(v1[i]);
            union_v.push_back(v1[i]);
            i++;
            j++;
        }
        else
        {
            union_v.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size())
    {
        union_v.push_back(v1[i]);
        i++;
    }
    while(j<v2.size())
    {
        union_v.push_back(v2[j]);
        j++;
    }
    cout<<"The Union of the two arrays:\t";
    for(i = 0; i<union_v.size(); i++)
    {
        cout<<union_v[i]<<'\t';
    }
    cout<<"\nThe Intersection of the two arrays:\t";
    for(i = 0; i<intersection_v.size(); i++)
    {
        cout<<intersection_v[i]<<'\t';
    }

    getch();
    return 0;
}