#include<stdio.h>
#include<string.h>

int n,m,p,k,l;
int a[100010],b[100010],tmp[100010];/*���ִ�*/ 

int seq[100010];

int jud(int num)/*�ж��м�Ԫ�غ���,����Ϊ�Ͻ翪����,���ɹ�����0���ɹ�����1*/ 
{
	int i,mx=num*m-1;/*�˷���ά����һ��������Ԫ�洢λ��*/ 
	memset(seq,0,sizeof(seq));
	memset(tmp,0,sizeof(tmp));
	for(i=0;i<l;i++)
	{
		tmp[b[i]]++;/*��������Ͱ����*/ 
	}
	for(i=mx;i>=0;i--)
	{
		if(tmp[a[i]])
		{
			seq[i/m]++;/*���г�����ά��ֻ������*/ 
			tmp[a[i]]--;
		}
	}
	for(i=0;i<l;i++)/*��Բ��������*/ 
	{
		if(tmp[b[i]])
		{
			return 0;
		}
	}
	long long now=p;/*now��ʾǮ��*/ 
	for(i=0;i<num;i++)
	{
		now-=seq[i];
		if(now<0)/*���Ǯ���������*/ 
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
			for(j=0;j<m;j++)/*a[i]�ǿ��������ݣ�ǿ�н���ά��һά�洢*/ 
			{
				scanf("%d",&a[i*m+j]);
			}
		}
		for(i=0;i<l;i++)/*b[i]��������������*/ 
		{
			scanf("%d",&b[i]);
		}
		int l=0,r=n;/*�����￪ʼl��ʾ����غ����½�����䣬rΪ�Ͻ翪����*/ 
		while(l<r)/*������ɢ��ʽ�����ڵ�������غ��������У�С�����������*/ 
		{
			int mid=(l+r)>>1;/*�м�*/ 
			if(jud(mid))/*�м���У���Ϊ�Ͻ翪���䣬��������*/ 
			{
				r=mid;
			}
			else /*�м䲻���У���һ���Ϊ�½�����䣬������*/ 
			{
				l=mid+1;
			}
		}
		if(!jud(l))/*�������½���ȣ���������ÿ���м�ȡ�Ͻ翪���䣬�п�����һ��*/ 
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
