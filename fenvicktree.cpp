#include<bits/stdc++.h>
using namespace std;

class Fentree{
public:
    vector<int>fenvicktree;
    int n;
   
    Fentree(int n){
        this->n = n;
        fenvicktree.resize(n + 1, 0);  
    }
   
    void build(vector<int> arr){
        for(int i = 1; i <= n; i++){
            int idx = i;
            while(idx <= n){
                this->fenvicktree[idx] += arr[i - 1];
                idx = idx + (idx & (-idx)); 
            } 
        }
    }
   
    void update(int i, int add){
        while(i <= n){
            this->fenvicktree[i] += add;
            i = i + (i & (-i)); 
        }
    }
   
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += this->fenvicktree[i];
            i = i - (i & (-i));
        }
        return s;
    }
   
    int findsum(int start, int end){
        return (sum(end) - sum(start - 1));
    } 
    int lower_bound_sum(int k){
        int ans=0,nums=0,curr=0;
        for(int i=log(n);i>=0;i--){
            if(fenvicktree[curr+ (1<<i)]+nums<k){
                curr = curr + (1<<i);
                nums = nums+ fenvicktree[curr];
            }
        }
        return (curr+1);
    } 
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
   
    Fentree f(n);
    f.build(arr);
    cout<<f.lower_bound_sum(11)<<endl;
    return 0;
}
