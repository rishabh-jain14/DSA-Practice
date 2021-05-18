#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

int binary(int arr[], int num, int beg, int end)
{
    int flag = 0;
    while(beg<=end)
    {
        int mid = beg + (end-beg)/2;
        if(arr[mid] == num)
        {
            return 1;
        }
        else if(arr[mid] > num)
        {
            end =  mid - 1;
        }
        else
        {
            beg = mid+1;
        }
    }
    return 0;
}

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector<int> v;
    int f = 0, i;
    int x = 0;
    char ch;
    int b1, b2, b3;
    if(A[0] >= B[0] && A[0] >= C[0])
    {
        ch  = 'a';
        b1 = 0;
        for(i = 0; i<n2; i++)
        {
            if(B[i]>=A[0])
            {
                b2 = i;
                break;
            }
        }
        for(i = 0; i<n3; i++)
        {
            if(C[i]>=A[0])
            {
                b3 = i;
                break;
            }
        }
    }
    else if(B[0] >= A[0] && B[0] >= C[0])
    {
        ch  = 'b';
        b2 = 0;
        for(i = 0; i<n1; i++)
        {
            if(A[i]>=B[0])
            {
                b1 = i;
                break;
            }
        }
        for(i = 0; i<n3; i++)
        {
            if(C[i]>=B[0])
            {
                b3 = i;
                break;
            }
        }
    }
    else
    {
        ch = 'c';
        b3 = 0;
        for(i = 0; i<n1; i++)
        {
            if(A[i]>=C[0])
            {
                b1 = i;
                break;
            }
        }
        for(i = 0; i<n2; i++)
        {
            if(B[i]>C[0])
            {
                b2 = i-1;
                break;
            }
        }
    }
    switch(ch)
    {
        case 'a':   for(i = 0; i<n1; i++)
                    {
                        if(binary(B, A[i], b2, n2-1))
                        {
                            if(binary(C, A[i], b3, n3-1))
                            {
                                if(x != 0 && v[x-1] != A[i])
                                {
                                    v.push_back(A[i]);
                                }
                                else if(x == 0)
                                {
                                    v.push_back(A[i]);
                                }
                                else
                                {
                                    continue;    
                                }
                                x++;
                            }
                        }
                    }
                    break;
        case 'b':   for(i = 0; i<n2; i++)
                    {
                        if(binary(A, B[i], b1, n1-1))
                        {
                            if(binary(C, B[i], b3, n3-1))
                            {
                                if(x != 0 && v[x-1] != B[i])
                                {
                                    v.push_back(B[i]);
                                }
                                else if(x == 0)
                                {
                                    v.push_back(B[i]);
                                }
                                else
                                {
                                    continue;    
                                }
                                x++;
                            }
                        }
                    }
                    break;
        case 'c':   for(i = 0; i<n3; i++)
                    {
                        if(binary(A, C[i], b1, n1-1))
                        {
                            if(binary(B, C[i], b2, n2-1))
                            {
                                if(x != 0 && v[x-1] != C[i])
                                {
                                    v.push_back(C[i]);
                                }
                                else if(x == 0)
                                {
                                    v.push_back(C[i]);
                                }
                                else
                                {
                                    continue;    
                                }
                                x++;
                            }
                        }
                    }
                    break;
    }
    return v;
}

int main ()
{
    int n1, n2, n3;
    cout<<"enter the sizes of all three arrays : \n";
    cin >> n1 >> n2 >> n3;
    int A[n1];
    int B[n2];
    int C[n3];

    cout<<"\nEnter the values of all three arrays one by one.\n";

    cout<<"First array : \n";
    for (int i = 0; i < n1; i++) cin >> A[i];

    cout<<"Second array : \n";
    for (int i = 0; i < n2; i++) cin >> B[i];

    cout<<"Third array : \n";
    for (int i = 0; i < n3; i++) cin >> C[i];    

    vector <int> res = commonElements(A, B, C, n1, n2, n3);
    if (res.size() == 0)
    {
        cout << -1;
    }
    for (int i = 0; i < res.size (); i++)
    {
        cout << res[i] << " ";
    }
    getch();
    return 0;
}