#include<stdio.h>

int k[105],p[105];

int comp(const void*a,const void*b)
{
	return *(int*)b>*(int*)a?1:-1;
}

int main()
{
    int T,n,m,a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
        int level=1,exp;
		int i,j,q=0;
		for(i=1;i<=99;i++)
		{
			k[i]=((i*a)+b)%c;
		}
		for(i=1;i<=99;i++)
		{
			exp=m;
			p[i-1]=k[i];
			qsort(p,i,sizeof(int),comp);
			if(n==100)
			{
				q=100;
				break;
			}
			if(i<n)
			{
				continue;
			}
			for(j=n;j<=i-1;j++)
			{
				if(exp>=p[j])
				{
					exp=exp-p[j];
				}
				else
				{
					q=i;
					break;
				}
			}
			if(q!=0)
			{
				break;
			}
			if(j==i&&i!=99)
			{
				continue;
			}
			if(j==i&&i==99)
			{
				q=100;
			}
		}
		printf("%d\n",q);
    }
}
