#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;cin>>n;vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        int ans=-1;
        for(int j=i-1;j>=0;j--){
            if(a[j]<a[i]){ans=a[j];break;}
        }
        cout<<ans<<" ";
    }
}
