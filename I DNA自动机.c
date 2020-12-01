#include<stdio.h>

int n,k,t,i;
char p[1000005],q[]={'A','T','C','G'};
int D[1000005][2];

int id(char a)
{
	if(a=='A')
	{
		return 1;
	}	
	if(a=='T')
	{
		return 3;
	}	
	if(a=='C')
	{
		return 5;
	}
	if(a=='G')
	{
		return 7;
	}	
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",p);
		for(i=0;i<n;++i)
		{
			D[i][0]=id(p[i]);
		}	
		int m,c=0;
		while(k)
		{
			int y=(k&(-k));
			k-=y;
			for(i=0;i<n;i++)
			{
				m=i+y;
				m%=n;
				D[i][c^1]=(D[m][c]*D[i][c])%8;
			}
			c^=1;
		}
		for(i=0;i<n;i++)
		{
			putchar(q[(D[i][c]-1)/2]);
		}	
		putchar('\n');
	}
	return 0;
}

