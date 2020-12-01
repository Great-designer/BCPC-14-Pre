#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct PQR
{
	long long stant,expe;
}yyy[65636];

int Comp(const void*p1,const void*p2)
{
	return(*(struct PQR*)p2).expe>(*(struct PQR*)p1).expe?1:-1;
}

int i,j;

long long qmulti(long long M, long long N, long long P)
{
    long long ans=0;
    while(N)
    {
        if(N&1)
            ans+=M;
        M=(M+M)%P;
        M%=P;
        ans%=P;
        N>>=1;
    }
    return ans;
}

long long qpow(long long y,long long z,long long P)
{
	int q;
	y%=P;
	long long ans=1;
	for(q=z;q;q>>=1,y=y*y%P)
		if(q&1)	ans=ans*y%P;
	return ans;
}

long long aj[100006];

long long cm(long long N,long long M,long long P)
{
	if(M>N)	return 0;
	return (aj[N]*qpow(aj[M],P-2,P))%P*qpow(aj[N-M],P-2,P)%P;
}

long long lucas(long long N,long long M,long long P)
{
	if(M==0)	return 1;
	return cm(N%P,M%P,P)*lucas(N/P,M/P,P)%P;	
}

long long exgcd(long long a,long long b,long long *x,long long *y)
{
	if(b==0)
	{
		*x=1,*y=0;
		return a;
	}
	long long gcd=exgcd(b,a%b,x,y);
	long long t=*x;
	*x=*y;
	*y=t-(a/b)*(*y);
	return gcd;
}

long long p[15];
long long B[23];
long long k;

long long chi()
{
	long long x,y,a=0,M,N=1;
	for(i=1;i<=k;i++)
		N*=p[i];
	for(i=1;i<=k;i++)
	{
		M=N/p[i];
		exgcd(p[i],M,&x,&y);
		long long jkl=qmulti(y,M,N);
		a=(a+qmulti(jkl,B[i],N))%N;
	}
	if(a>0)
		return a;
	else
		return a+N;
}

long long v[23],n,m,cnt;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		memset(yyy,0,sizeof(yyy));
		for(i=1;i<=n;i++)
			scanf("%lld",&v[i]);
		for(i=1;i<=k;i++)
			scanf("%lld",&p[i]);
		int oto=1;
		yyy[oto].stant=-1;
		yyy[oto++].expe=v[1]+1;
		yyy[oto].stant=1;
		yyy[oto++].expe=0;
		for(i=2;i<=n;i++)
		{
			int K=oto-1;
			for(j=1;j<=K;j++)
			{
				yyy[oto].stant=yyy[j].stant*(-1);
				yyy[oto++].expe=yyy[j].expe+v[i]+1;
			}
		}
		oto--;
		qsort(yyy+1,oto,sizeof(struct PQR),Comp);
		long long lasexpe=yyy[1].expe;
		cnt=1;
		for(i=2;i<=oto;i++) 
		{
			if(yyy[i].expe==lasexpe)
				yyy[cnt].stant+=yyy[i].stant;
			else
			{
				cnt++;
				lasexpe=yyy[i].expe;
				yyy[cnt].expe=lasexpe;
				yyy[cnt].stant=yyy[i].stant;
			}
		}
		for(i=1;i<=k;++i)
		{
			long long tem=0;
			memset(aj,0,sizeof(aj));
			aj[0]=1;
			for(j=1;j<=p[i];j++)
			{
				aj[j]=(aj[j-1]*j)%p[i];
			}
			for(j=1;j<=cnt;++j)
			{
				long long expe=yyy[j].expe;
				long long stant=yyy[j].stant;
				if(n-1+m-expe>=0)
				{
					tem+=stant*lucas(n-1+m-expe,n-1,p[i]);
					tem%=p[i];
				}
			}
			while(tem<0)
			{
				tem+=p[i];
			}	
			B[i]=tem;
		}
		printf("%lld\n",chi());
	}
}
