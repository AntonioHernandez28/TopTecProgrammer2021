#include <iostream> 
using namespace std;
 
int main()
{
	int n,u,r,d,l;
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>u>>r>>d>>l;
		
		int a=0,b=0;
		int res=1;
		a=(u==n)+(d==n);
		b=(u==n-1)+(d==n-1);
		if((l<a)||(r<a)||(l+r<b+2*a)) res=0;
		
		a=(l==n)+(r==n);
		b=(l==n-1)+(r==n-1);
		if((u<a)||(d<a)||(u+d<b+2*a)) res=0;	
		
		if(res) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
} 