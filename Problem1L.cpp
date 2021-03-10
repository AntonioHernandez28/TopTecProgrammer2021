#include <iostream> 
#include <algorithm> 
#include <vector>
using namespace std;
int main() {
	long n,i,j,a,sal[1005],par[1005],last[1005];
	vector<pair<long,pair<long,long>>>v;
	cin>>n;
	for(i=1;i<=n;i++){
		last[i]=i;
		for(j=1;j<i;j++) cin>>a;
		cin>>sal[i];
		for(j=i+1;j<=n;j++){
			cin>>a;
			v.push_back({a,{i,j}});
		}
	}
	sort(v.begin(),v.end());
	for(auto k:v){
		if(sal[last[k.second.first]]<k.first&&sal[last[k.second.second]]<k.first){
			sal[++n]=k.first;
			par[last[k.second.first]]=n,last[k.second.first]=n;
			par[last[k.second.second]]=n,last[k.second.second]=n;
		}
		else if(sal[last[k.second.first]]<k.first){
			par[last[k.second.first]]=last[k.second.second];
			last[k.second.first]=last[k.second.second];
		}
		else{
			par[last[k.second.second]]=last[k.second.first];
			last[k.second.second]=last[k.second.first];
		}
	}
	cout<<n<<endl;
	for(i=1;i<=n;i++) cout<<sal[i]<<' ';
	cout<<endl<<n<<endl;
	for(i=1;i<n;i++){
		cout<<i<<' '<<par[i]<<endl;
	}
}