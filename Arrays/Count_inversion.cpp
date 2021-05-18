// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return mergesort(arr, temp, 0, N-1);
    }
    
    long long int mergesort(long long arr[], long long temp[], long long start, long long end)
    {
        long long int inv_count  = 0;
        long long mid = start + (end - start)/2;
        if(start < end)
        {
            inv_count += mergesort(arr, temp, start, mid);
            inv_count += mergesort(arr, temp, mid+1, end);
            
            inv_count += merge(arr, temp, start, mid, end);
        }
        return inv_count;
    }
    
    long long int merge(long long arr[], long long temp[], long long start, long long mid, long long end)
    {
        long long i, j, k;
        long long int inv_count = 0;
        i = start;
        j = mid + 1;
        k = start;
        
        while(i<=mid && j<=end)
        {
            if(arr[i] > arr[j])
            {
                temp[k++] = arr[j++];
                inv_count += (mid - i + 1);
            }
            else
            {
                temp[k++] = arr[i++];
            }
        }
        while(i<=mid)
        {
            temp[k++] = arr[i++];
        }
        while(j<=end)
        {
            temp[k++] = arr[j++];
        }
        
        for(i = start; i<=end; i++)
        {
            arr[i] = temp[i];
        }
        
        return inv_count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends