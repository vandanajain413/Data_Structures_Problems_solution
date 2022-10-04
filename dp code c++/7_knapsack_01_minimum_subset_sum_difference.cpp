#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long int

const int N=1e3+10;
static int t[N][N];

bool knapsack(int arr[],int sum,int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j] = 0;
            }
            if(j == 0){
                t[i][j] = 1;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=sum){
               t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    

    return t[n][sum];
}

int main()
{
    int arr[] = {1,5,7,9};
    
    int n=4;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+= arr[i];
    }

    knapsack(arr, sum, n);
    vector<int> v;
    for(int col=0;col<sum/2;col++){
        if(t[n][col] == 1)
        v.push_back(col);

    }

    cout<<sum -2*(*(--v.end()))<<endl;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
}