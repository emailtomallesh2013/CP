#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:

    long int ncr(int n, int r, map<pair<int, int> ,long int>& mpi){
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
    
	int helper(int n, map<int, int>& m) {
		if (m.count(n)) {
			return(m[n]);
		}
		int sum = 0;
		for (int i = 0; i <= n - 1; i++) {
			int t = helper(i, m);
			int p = helper(n - 1 - i, m);
			//cout << i << ":" << t*p << endl;
			sum += t*p;
		}
		m.insert(make_pair(n, sum));
		return sum;
	}

    int count(int N){
        map<int,int> m;
        m.insert(make_pair(0,1));
        m.insert(make_pair(1,1));
        
        return helper(N/2,m);
        //map<pair<int, int> ,long int> mpi;
        //return ncr(N, N/2, mpi)/(N/2+1);
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
