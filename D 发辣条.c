#include<stdio.h>

int p[205],q[205]; 

int main()
{
    int T,n,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&q[i]);
		}
		int all=0,b=0;
		for(i=1;i<=n;i++)
		{
			if((b+q[i])>p[i])
			{
				j=b+q[i];
			}
			else
			{
				j=p[i];
				all+=(p[i]-q[i]-b)*(i-1);
			}
			all+=j;
			b=j;
		}
		printf("%d\n",all);
    }
}
