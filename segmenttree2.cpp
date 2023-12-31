#include<bits/stdc++.h>
using namespace std;
class SGtree{
public:
  vector<int>sg;
   SGtree(int n){
       sg.resize(4*n +1);
   }
   void build(int idx,int low,int high,vector<int>arr){
       if(low == high){
           sg[idx] = arr[low];
           return;
       }
       int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        sg[idx] = sg[2*idx+1]+sg[2*idx+2];    
   }
   int qurie(int idx,int low , int high,int l, int h){
      if(h<low || high<l){
          return 0;
      }
      if(low>=l && high<=h){
          return sg[idx];
      }
      int mid = (low+high)/2;
      int left = qurie(2*idx+1,low,mid,l,h);
      int right = qurie(2*idx+2,mid+1,high,l,h);
      return left+right;
   }
   void update(int idx,int low, int high,int i,int value){
       if(low == high){
           sg[idx] = value;
           return;
       }
       int mid = (low+high)>>1;
       if(i<=mid) update(2*idx+1,low,mid,i,value);
       else update(2*idx+2,mid+1,high,i,value);
       sg[idx] = sg[2*idx+1]+sg[2*idx+2];
   }
};
int main(){
    int n1;
    cin>>n1;
    vector<int>arr1(n1);
    for(int i=0;i<n1;i++) cin>>arr1[i];
    SGtree* s1 = new SGtree(n1);
    s1->build(0,0,n1-1,arr1);
    //cout<<s1->sg[0];
    //int n2;
    //cin>>n2;
    //vector<int>arr2(n2);
    //for(int i=0;i<n2;i++) cin>>arr2[i];
   // SGtree* s2 = new SGtree(n2);
    //s2->build(0,0,n2-1,arr2);
    //cout<<s2->sg[0];
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type ==1){
            int l1,h1;
            //int l2,h2;
            cin>>l1>>h1;
            //cin>>l2>>h2;
            int ans1 = s1->qurie(0,0,n1-1,l1,h1);
            //int ans2 = s2->qurie(0,0,n2-1,l2,h2);
            //int ans = max(ans1,ans2);
            cout<<ans1<<endl;
        }
        else if(type ==2){
            int arrno;
            cin>>arrno;
            int i,value;
            cin>>i>>value;
            if(arrno ==1){
                s1->update(0,0,n1-1,i,value);
            }
            else{
                 //s2->update(0,0,n2-1,i,value);
            }
        }
    }
    delete s1;
    //delete s2;
    return 0;
}
//5
//1 2 3 4 5
//1
//1
//2 3 
