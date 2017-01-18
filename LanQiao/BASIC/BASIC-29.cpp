#include <iostream>
#include <cstring>
#include <memory.h>
#define MAX 110  
using namespace std;  

int num1[MAX];
int num2[MAX];  
int num[MAX];  
char temp[MAX];  
  
void carry()  
{  
    for(int i = 0; i < MAX-1; i++)  
    {  
        if(num[i]>9)  
        {  
            num[i + 1] += num[i] / 10;  
            num[i] %= 10;  
        }  
    }  
}  
  
void sum()  
{  
    for(int i = 0; i < MAX; i++)  
    {  
        num[i] = num1[i] + num2[i];  
    }  
    carry();  
}  
  
void output()  
{  
    int i;  
    for(i = MAX - 1; i >= 0; i--)  
    {  
        if(num[i] != 0)  
            break;  
    }  
    for(; i >= 0; i--)  
    {  
        cout << num[i];  
    }  
    cout << endl;  
}  
  
void init()  
{  
    memset(num1, 0, sizeof(num1));  
    memset(num2, 0, sizeof(num2));  
    memset(num, 0, sizeof(num));  
}  
  
int main()  
{  
    int i,len;  
    init();  
    cin >> temp;  
    len = strlen(temp);  
    for(i = 0; i < len; i++) {  
        num1[i] = temp[len - 1 - i] - '0';  
    }  
    cin >> temp;
    len = strlen(temp);  
    for(i = 0; i < len; i++) {  
        num2[i] = temp[len - 1 - i] - '0';  
    }  
    sum();  
    output();  
    return 0;  
}