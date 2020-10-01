#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    map<int,int> M;
    for(int i=0;i<arr.size();i++)
        M[arr[i]]++;
    vector<pair<int,int>> A;
    for(auto it=M.begin();it!=M.end();it++)
        A.push_back({it->second,it->first});
    sort(A.begin(),A.end());
    int i=0;
    while(i<A.size() && A[i].first<=k)
    {
        k-=A[i].first;
        i++;
    }
    
    int ans=A.size()-i;
    return ans;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
    {
    	int N,K;
    	cin>>N>>K;
    	vector<int> arr(N);
    	for(int i=0;i<N;i++)
    		cin>>arr[i];
    	cout<<findLeastNumOfUniqueInts(arr,K)<<endl;
    }
    
}
