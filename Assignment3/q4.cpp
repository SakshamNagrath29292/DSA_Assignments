#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
char stack[MAX];int top=-1;
void push(char c){stack[++top]=c;}
char pop(){return stack[top--];}
int prec(char c){if(c=='+'||c=='-')return 1;if(c=='*'||c=='/')return 2;return 0;}
int main(){
    char infix[100],postfix[100];cin>>infix;
    int k=0,n=strlen(infix);
    for(int i=0;i<n;i++){
        char c=infix[i];
        if(isalnum(c))postfix[k++]=c;
        else if(c=='(')push(c);
        else if(c==')'){while(top!=-1&&stack[top]!='(')postfix[k++]=pop();top--;}
        else{while(top!=-1&&prec(stack[top])>=prec(c))postfix[k++]=pop();push(c);}
    }
    while(top!=-1)postfix[k++]=pop();
    postfix[k]='\0';
    cout<<postfix;
}
