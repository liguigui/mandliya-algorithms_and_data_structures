#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int minDays(vector<int>& bloomDay, int m, int k) {
    int s=0,e=1000000000,ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        int N=bloomDay.size();
        bool mark[N];
        for(int i=0;i<N;i++)
            if(bloomDay[i]<=mid)
                mark[i]=1;
            else
                mark[i]=0;
        
        int b=0,curr=0;
        for(int i=0;i<N;i++)
        {
            if(mark[i]==0)
                curr=0;
            else
                curr++;
            if(curr==k)
            {
                b++;
                curr=0;
            }
        }
        if(b>=m)
        {
            ans=mid;
            e=mid-1;
        }
        else
            s=mid+1;
    }
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
    	int N,M,K;
    	cin>>N>>M>>K;
    	vector<int> arr(N);
    	for(int i=0;i<N;i++)
    		cin>>arr[i];
    	cout<<minDays(arr,M,K)<<endl;
    }
    
}
