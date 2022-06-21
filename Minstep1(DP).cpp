#include <bits/stdc++.h>
using namespace std;

int countStepsToOne_helper(int n,int *ans){
    if(n<=1){
        return 0;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int x = countStepsToOne_helper(n-1,ans);
    int y=INT_MAX,z=INT_MAX;
    if(n%2==0){
        y=countStepsToOne_helper(n/2,ans);
    }
    if(n%3==0){
        z=countStepsToOne_helper(n/3,ans);
    }
    int output = min(x,min(y,z))+1;
    ans[n]=output;
    return ans[n];
}
int countStepsToOne(int n)
{
	//Write your code here
    int *ans = new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return countStepsToOne_helper(n,ans);
}
int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
