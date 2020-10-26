#include<bits/stdc++.h>
using namespace std;
typedef int ll;
#define fr(i,k,n) for(ll i = k;i<n;i++)
#define mo map<ll,ll> 
vector<ll> ms[200001];
ll dep[200001];
ll answer = 0;
ll fians = 0;
ll depth(ll parent,ll src){
	ll ans = 0;
	for(ll child:ms[parent]){
		if(child != src){
					depth(child,parent);
		ans = max(ans,1 + dep[child]);
		}
 
	}
	dep[parent] = ans;
	return dep[parent];
	
	}
ll sol(ll parent,ll src){
	vector<ll> as;
//	vector<ll> childs;
//	childs.push_back(parent);
	for(ll child:ms[parent]){
		if(child != src){
			
				sol(child,parent);
				
			//	childs.push_back(child);
				
		}
	
	}
	for(ll child:ms[parent]){
		if(child != src){
		
				as.push_back(dep[child]);
				
			//	childs.push_back(child);
				
		}
	
	}
	sort(as.begin(),as.end());
	if(as.size() == 1){
	
		answer = 1 + as[0];
	}
	if(as.size() >= 2){
		ll c = as.size() - 1;
		
		answer = 2 + as[c] + as[c-1];
	}
/*	else{
	ll c = as.size() - 1;
 
		answer = 2 + as[c] + as[c-1];
	
}*/
		
	fians = max(answer,fians);
return 0;
 
}
int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a,b;
    fr(i,0,n-1){
    	cin>>a>>b;
    	ms[a].push_back(b);
    	ms[b].push_back(a);
    }
    depth(1,0);
    sol(1,0);
    
    cout<<fians<<"\n";
    
 
}