#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100
char stack[MAX];int top=-1;
void push(char c){stack[++top]=c;}
char pop(){return stack[top--];}
int main(){
    char exp[100];
    cin>>exp;
    int n=strlen(exp);
    for(int i=0;i<n;i++){
        if(exp[i]=='(')push('(');
        else if(exp[i]==')'){if(top==-1){cout<<"Not Balanced";return 0;}pop();}
    }
    if(top==-1)cout<<"Balanced";else cout<<"Not Balanced";
}
