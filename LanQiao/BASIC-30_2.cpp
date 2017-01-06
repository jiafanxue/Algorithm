#include <iostream>
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#define PI 3.141592654  
#define E 2.71828182846  
#define MAX 30000
using namespace std;
  
int Len(int n)  
{  
    int s = 1;  
    if(n > 3)  
        s = log10(2 * PI * n) / 2 + n * log10(n / E) + 1;  
    return s;  
}  
  
int main()  
{  
    int a[MAX], i, j, n;  
    int c = 0;                                   //进位  
    int s;  
    int len;  
    memset(a, 0, sizeof(a));                     //初始化字串   
    scanf("%d", &n);  
    a[0] = 1;  
    for (i = 2; i <= n; i++) {                     //乘数    
        len = Len(i);
        for (j = 0; j<len; j++) {  
            s = a[j] * i + c;  
            a[j] = s % 10;  
            c = s / 10;  
        }  
    }  
    for (j = Len(n) - 1; j >= 0; j--) {  
        cout << a[j];  
    }
    cout << endl;
    return 0;  
}  