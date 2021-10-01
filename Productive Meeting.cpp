#include<bits/stdc++.h>
using namespace std;
int t,n,a,ans;
priority_queue<pair<int,int>> q; 
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		vector<int> l,r;
		for(int i=1;i<=n;i++){
			cin>>a;
			if(a>0) q.push({a,i});
		}
		while(q.size()>1){
			auto x=q.top();q.pop();
			auto y=q.top();q.pop();
			ans++;
			l.push_back(x.second),r.push_back(y.second);
			if(--x.first) q.push(x);
			if(--y.first) q.push(y);
		}
		if(!q.empty()) q.pop();
		cout<<ans<<endl;
		for(int i=0;i<ans;i++) printf("%d %d\n",l[i],r[i]);
	}
	return 0;
}
