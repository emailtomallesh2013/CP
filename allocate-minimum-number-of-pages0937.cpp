// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

#include<algorithm>
class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool validate(int A[], int N, int M, int capacity){
        int sum=0;
        int index=0;
        int students=0;
        if(A[0]>capacity) return false;
        while( index<N && students <=M){
            sum+=A[index];
            if(sum==capacity){
                sum=0;
                students+=1;
                index+=1;
            }
            else if(sum>capacity){
                sum=0;
                students+=1; 
            }
            else{
                index+=1;
            }
        }
		if (index >= N && sum > 0) {
			students += 1;
		}
		if (students > M) return false;
		return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        if(M>N) return -1;
        long int cumsum=0;
        for(int i=0; i<N ; i++){
            cumsum+=A[i];
        }
        
        long int mid, cmin=0;
        long int cmax;
        cmax =cumsum;
        
        while(cmin< cmax-1){
            //cout<< "(cmin, cmax)=" << make_pair(cmin,cmax) << endl;
            
            mid = cmin + (cmax - cmin)/2;
            //cout<< mid << ": validate: " << validate(A, N, M, mid) << endl;
            if(!validate(A, N, M, mid)){
                cmin = mid;
            }
            else{
                cmax=mid;
            }
        }
        
        
        return cmax;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
