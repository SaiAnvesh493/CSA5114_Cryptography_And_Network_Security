#include<stdio.h>
#include <math.h>
int main()
{
	int xa,xb,ya,yb,temp1,temp2,temp3,temp4,k1,k2,q,b;
	printf("Enter the value of q:");
	scanf("%d",&q);
	printf("Enter the value of alpha:");
	scanf("%d",&b);
	printf("Enter the value of Xa:");
	scanf("%d",&xa);
	printf("Enter the value of Xb:");
	scanf("%d",&xb);
	temp1=(pow(b,xa));
	ya=temp1%q;
	printf("ya=%d",ya);
	temp1=(pow(b,xb));
	ya=temp2%q;
	printf("yb=%d",yb);
	temp3=(pow(yb,xa));
	k1=temp3%q;
	temp4=(pow(ya,xb));
	k2=temp4%q;
	if(k1==k2)
	{
		printf("The value of k=%d",k1);
	}
	return 0;
	
}
