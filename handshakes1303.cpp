#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:

    long int ncr(int n, int r, map<pair<int, int> , int>& mpi){
        if(mpi.count(make_pair(n,r))){
            return mpi[make_pair(n,r)];
        }
        
        if(n==1 || n==r){
            mpi.insert(make_pair(make_pair(n,r),1));
            return 1;
        }
        if(r==1){
            mpi.insert(make_pair(make_pair(n,r),n));
            return n;
        }
        
        long int out = ncr(n-1,r, mpi) + ncr(n-1,r-1, mpi);
        mpi.insert(make_pair(make_pair(n,r),out));
        return out;
        
    }

    int count(int N){
        map<pair<int, int> , int> mpi;
        return ncr(N, N/2, mpi)/(N/2+1);
        // code here
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends
