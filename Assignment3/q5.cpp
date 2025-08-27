#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
int stack[MAX];int top=-1;
void push(int x){stack[++top]=x;}
int pop(){return stack[top--];}
int main(){
    char exp[100];cin>>exp;int n=strlen(exp);
    for(int i=0;i<n;i++){
        char c=exp[i];
        if(isdigit(c))push(c-'0');
        else{
            int b=pop(),a=pop();
            if(c=='+')push(a+b);
            else if(c=='-')push(a-b);
            else if(c=='*')push(a*b);
            else if(c=='/')push(a/b);
        }
    }
    cout<<pop();
}
