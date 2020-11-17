#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        nums[i]=sum;
        
    }
    return nums;
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
    	int N;
    	cin>>N;
    	vector<int> nums(N);
    	for(int i=0;i<N;i++)
    		cin>>nums[i];
    	vector<int> ans=runningSum(nums);
    	for(int i=0;i<N;i++)
    		cout<<ans[i]<<" ";
    	cout<<endl;
    	
    }
    
}
