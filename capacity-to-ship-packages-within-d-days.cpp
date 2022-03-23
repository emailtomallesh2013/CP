#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        
        vector<long int> prev(N+1);
        vector<long int> current(N+1);
        vector<long int> cumsum(N+1);
        cumsum[0]=arr[0];
        for(int i=1; i<N; i++){
            cumsum[i] = cumsum[i-1]+arr[i];
        }
        cumsum[N]=cumsum[N-1];
        prev[N]=0;
        for(int i=N-1; i>=0; i--){
            prev[i]= prev[i+1]+arr[i];
        }
        
        int m =D-1;
        current = prev; // just to cover edge case M=1
        while(m){
            for(int i=N-1; i>=0; i--){
                int min= INT_MAX;
                //current[N-1] = 
                for(int j=i; j<=N-1; j++){
                    long int firstVal;
                    if(i>0){
                        firstVal = cumsum[j]-cumsum[i-1];
                    }
                    else{
                        firstVal = cumsum[j];
                    }
                    long int secondVal = prev[j+1];
                    long int weight = max(firstVal,secondVal);
                    
                    if(weight<min){
                        min=weight;
                    }
                }
                current[i]=min;
            }
            prev = current;
            m--;
        }
        return current[0];
    }
        // code here
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends
