#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
char stack[MAX];int top=-1;
void push(char c){if(top<MAX-1)stack[++top]=c;}
char pop(){return stack[top--];}
int main(){
    char s[100];
    cin>>s;
    int n=strlen(s);
    for(int i=0;i<n;i++)push(s[i]);
    while(top!=-1)cout<<pop();
}
