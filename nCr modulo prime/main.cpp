#include <iostream>

using namespace std;
typedef long long int ll;
ll M = 100000;

ll modpow(int a,int n){	// calc a^n (mod M)
	int r=1;
	for(ll x=a;n;n>>=1,x=(x*x)%M) if(n&1) r=(r*x)%M;
	return r;
}

int inv(int a){	// find x s.t. a*x=1 (mod M) (M:prime)
	return modpow(a,M-2);
}

ll modnCr(ll n,ll r){	// calc nCr (mod M) (M:prime)
	if(n<r)		return 0;
	if(n-r<r)	r=n-r;

	ll res=1;
	for(int i=r;i>0;i--){
		res=(res*((n-i+1)%M))%M;
		res=(res*inv(i))%M;
	}
	return res;
}

int main()
{
  ll a = 5;
  cout<<a<<endl;
  if(2&6)
  {
      cout<<"sd";
  }
  else
  {
      cout<<"asdad";
  }
}
