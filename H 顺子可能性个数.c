#include<stdio.h>

char a[8];
int x[150];

int main()
{
	int t,i,j,k;
	x['A']=1,x['2']=2,x['3']=3,x['4']=4,x['5']=5,x['6']=6,x['7']=7,x['8']=8,x['9']=9,x['T']=10,x['J']=11,x['Q']=12,x['K']=13;
	scanf("%d",&t);
	while(t--)
	{
		int t[25]={0},ans=0;
		int used[60]={0},num[20]={0};
		scanf("%s",a);
		for(i=0;i<5;i++)
		{
			int s=x[a[i]];
			t[s]++;/*��¼��������*/
			used[s*4+num[s]++]++;/*��¼�����飬��AAAA2222��˳���¼*/ 
			if(a[i]=='A')
			{
				t[14]++;
			}
		}
		for(i=4;i<56;i++)/*��һö�ٵ�һ����,i�����������е�λ��*/ 
		{
			if(used[i])
			{
				continue;
			}
			t[i/4]++;
			for(j=i+1;j<56;j++)/*��һö�ٵڶ����ƣ�j�����������е�λ��*/
			{
				if(used[j])
				{
					continue;
				}
				t[j/4]++;
				int flag=0;/*���*/ 
				for(k=1;k<=13;k++)
				{
					if(t[k]&&t[k+1]&&t[k+2]&&t[k+3]&&(t[k+4]||(k+4==14&&t[1])))
					{
						flag=1;
						break;/*����˳�Ӽ�����ѭ��*/ 
					}
				}
				if(flag)
				{
					ans++;
				}
				t[j/4]--;
			}
			t[i/4]--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
