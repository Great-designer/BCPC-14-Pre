#include<stdio.h>
#include<string.h>

int n,m,p,k,l;
int a[100010],b[100010],tmp[100010];/*二分答案*/ 

int seq[100010];

int jud(int num)/*判断中间元素函数,将调为上界开区间,不成功返回0，成功返回1*/ 
{
	int i,mx=num*m-1;/*乘法升维，单一坐标变表中元存储位置*/ 
	memset(seq,0,sizeof(seq));
	memset(tmp,0,sizeof(tmp));
	for(i=0;i<l;i++)
	{
		tmp[b[i]]++;/*心仪阵容桶排序*/ 
	}
	for(i=mx;i>=0;i--)
	{
		if(tmp[a[i]])
		{
			seq[i/m]++;/*其中除法降维，只求行数*/ 
			tmp[a[i]]--;
		}
	}
	for(i=0;i<l;i++)/*针对不卖的情况*/ 
	{
		if(tmp[b[i]])
		{
			return 0;
		}
	}
	long long now=p;/*now表示钱数*/ 
	for(i=0;i<num;i++)
	{
		now-=seq[i];
		if(now<0)/*针对钱不够的情况*/ 
		{
			return 0;
		}
		if(now<l)
		{
			now+=now/k+p;
		}
	}
	return 1;
}

int main()
{
	int i,j,q,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&m,&p,&k,&l);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)/*a[i]是可棋子阵容，强行将二维降一维存储*/ 
			{
				scanf("%d",&a[i*m+j]);
			}
		}
		for(i=0;i<l;i++)/*b[i]是心仪棋子阵容*/ 
		{
			scanf("%d",&b[i]);
		}
		int l=0,r=n;/*从这里开始l表示所求回合数下界闭区间，r为上界开区间*/ 
		while(l<r)/*二分离散形式，大于等于最早回合数均可行，小于则均不可行*/ 
		{
			int mid=(l+r)>>1;/*中间*/ 
			if(jud(mid))/*中间可行，改为上界开区间，从下面找*/ 
			{
				r=mid;
			}
			else /*中间不可行，加一后改为下界闭区间，不丢解*/ 
			{
				l=mid+1;
			}
		}
		if(!jud(l))/*至此上下界相等，但是由于每次中间取上界开区间，有可能少一个*/ 
		{
			l++;
		}
		if(l<=n)
		{
			printf("%d\n",l);
		}
		else 
		{
			printf("-1\n");
		}
	}
	return 0;
}
