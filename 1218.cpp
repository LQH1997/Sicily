#include <cstdio>
#include <cmath>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int len = sqrt(2*m)+1;//��ʵ���ǵȲ�������͵Ĺ�ʽ�������󳤶� 
    while(--len)
    {
        int l = m/len-len/2+!(len&1); //�����С����ֵ m/len��ƽ��ֵ len/2��ƽ��ֵ�������ֵĸ����� 
		                             //��len&1)�����ڼ���Ƿ�Ϊż���������ż������Сֵ��Ҫ��һ�������������ܹ���ֵ����len��ֵ 
		                             //ԭ����ż�������Ժ������len/m�Ӽ�������len��ֵ���࣬����Ϊlen/m��ʱ����1�Ĳ����ǲ���ģ����ԣ���ƽ��ֵ
									 //��ಹ��1������������ 
        int r = m/len+len/2;
        if(l < 1 || r > n) continue;
        if((l+r)*(r-l+1)/2 == m)
            printf("[%d,%d]\n",l,r);
    }
}                                 
