#include <cstdio>
#include <cmath>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int len = sqrt(2*m)+1;//其实就是等差数列求和的公式，求出最大长度 
    while(--len)
    {
        int l = m/len-len/2+!(len&1); //求出最小的面值 m/len是平均值 len/2是平均值左侧的数字的个数， 
		                             //（len&1)是用于检测是否为偶数，如果是偶数，最小值需要加一才能满足最后的总共的值等于len的值 
		                             //原因是偶数除二以后会再与len/m加减，会让len的值增多，又因为len/m的时候不满1的部分是不算的，所以，在平均值
									 //左侧补上1，来消除错误。 
        int r = m/len+len/2;
        if(l < 1 || r > n) continue;
        if((l+r)*(r-l+1)/2 == m)
            printf("[%d,%d]\n",l,r);
    }
}                                 
