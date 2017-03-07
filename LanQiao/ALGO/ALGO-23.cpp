#include <iostream>  
#include <iomanip>
#include <cmath>  
using namespace std;

float a,b,c,d;  
float f0(float x){return a*x*x*x+b*x*x+c*x+d;}  
float f1(float x){return 3*a*x*x+2*b*x+c;}  
float f2(float x){return 6*a*x+2*b;}  
float (*f[3])(float)={f0,f1,f2};  

float biSearch(float x1,float x2,int item){  
	if(item==2)return (-1*b/(3*a));  
	if(fabs((*f[item])(x1))<0.01)  
    	return x1;  
	if(((*f[item])(x1))*((*f[item])((x1+x2)/2))<0)  
    	return biSearch(x1,(x1+x2)/2,item);  
	else  
    	return biSearch((x1+x2)/2,x2,item);  
}  

int main()
{  
	float x21;  
	float x11,x12;  
	float x1,x2,x3;  
	cin >> a >> b >> c >> d;  
	x21=biSearch(-100,100,2);  
	x11=biSearch(-100,x21,1);  
	x12=biSearch(x21,100,1);  
	x1=biSearch(-100,x11,0);  
	x2=biSearch(x11,x12,0);  
	x3=biSearch(x12,100,0);  
	cout << fixed << setprecision(2) << x1 << " " << x2 << " " << x3 << endl;
	return 0;
}