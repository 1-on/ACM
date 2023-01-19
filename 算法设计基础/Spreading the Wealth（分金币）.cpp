#include "bits/stdc++.h"
using namespace std;
int n;
int a[1000005];
int C[1000005];
int main()
{
    while(cin>>n)
    {
        long long sum=0;

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        int M=sum/n;
        C[0]=0;
        for(int i=1;i<=n;i++)
        {
            C[i]=C[i-1]+a[i]-M;
        }
        sort(C+1,C+n+1);
        long long int x1=C[n/2];
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(x1>C[i]) ans+=(x1-C[i]);
            else ans+=(C[i]-x1);
        }
        cout<<ans<<endl;
    }
}
