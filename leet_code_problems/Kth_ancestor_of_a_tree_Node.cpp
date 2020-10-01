#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

class TreeAncestor {
public:
	int par[50000][25];
    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0;i<n;i++)
            for(int j=0;j<25;j++)
                par[i][j]=-1;
        for(int i=0;i<parent.size();i++)
            par[i][0]=parent[i];
        
        for(int i=1;i<25;i++)
            for(int j=0;j<n;j++)
                if(par[j][i-1]!=-1)
                    par[j][i]=par[par[j][i-1]][i-1];
    }
    
    int getKthAncestor(int node, int k) {
        int ans=node,i=0;
        while(k)
        {
            if(k%2==1 && ans!=-1)
                ans=par[ans][i];
            i++;
            k/=2;
            
        }
        return ans;
    }
};

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
    	vector<int> parent(N);
    	for(int i=0;i<N;i++)
    		cin>>parent[i];

    	TreeAncestor obj(N,parent);
    	int Q;
    	cin>>Q;
    	while(Q--)
    	{
    		int node,K;
    		cin>>node>>K;
    		cout<<obj.getKthAncestor(node,K)<<endl;
    	}
    }
}
