#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll F(ll N,ll P,ll M)
{
	if(P==0) return 1;
	if(P%2==0)
	{
		ll ret=F(N,P/2,M);
		return ((ret%M)*(ret%M))%M;
	}
	else return ((N%M)*(F(N,P-1,M)%M))%M;

}
ll modInverse(ll a, ll m)
{
    a = a%m;
    for (ll x=1; x<m; x++)
        if ((a*x) % m == 1)
            return x;
}

ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll checkPrime(ll n) {
	ll i;
	ll m = n / 2;

	for (ll i = 2; i <= m; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}

int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);*/
    ll p,q,n,z;

    while (1)
    {
        cout<<"P = ";
        cin>>p;
        cout<<"Q = ";
        cin>>q;

        if (!(checkPrime(p) && checkPrime(q)))
            printf("Both P & Q are not prime. Re-enter p and q\n");
        else if (!checkPrime(p))
            printf("P is not prime, re-enter p and q!\n");
        else if (!checkPrime(q))
            printf("Q is not prime, re-enter p and q!\n");
        else
            break;
    }

    n= p*q;
    cout<<"N = "<<n<<endl;
    z=(p-1)*(q-1);
    cout<<"Z = " <<z<<endl;
    ll d=2;
    while (d < z)
    {
        if (gcd(z,d)==1)
            break;
        else
            d++;
    }
    ll e= modInverse(d, z);
    swap(e,d);
    cout<<"Encryption Key : "<<e<<endl;
    cout<<"Decryption Key : "<<d<<endl;
    cout<<"PlainText : ";
    string plaintext;
    cin>>plaintext;
    for (int i=0; i<plaintext.size(); i++)
        plaintext[i]=toupper(plaintext[i]);
    queue <ll> enc;
    cout<<"\nSender's Computation: \n\n";
    cout<<"Symbolic\tNumeric\t\tP^"<<e<<"\t\tP^"<<e<<"(mod "<<n<<")"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    for(int i=0; i<plaintext.size(); i++)
    {
        cout<<plaintext[i]<<"\t\t";
        ll ch=plaintext[i]-64;
        cout<<ch<<"\t\t";
        double en= F(ch,e,1e7) ;
        cout<<en<<"\t\t";
        en= F(ch,e,n) ;
        cout<<en;
        enc.push(en);
        cout<<endl;
    }

    cout<<"\nReceiver's Computation: \n\n";
    cout<<"C^"<<d<<"\t\tC^"<<d<<"(mod "<<n<<")\tSymbolic\n";
    cout<<"----------------------------------------------------------------"<<endl;
    for(int i=0; i<plaintext.size(); i++)
    {
        double en = enc.front();
        enc.pop();
        double result = F(en, d,1e9);
        ll de = result;
        printf("%lld\t\t\t",de);
        de = F(en, d,n);
        if(result<1e7 && de<1e7)
            cout<<"\t";
        printf("%lld\t\t\t",de);
        char v = de + 64;
        cout<<v<<endl;
    }
    return 0;

}
