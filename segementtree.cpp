#include<bits/stdc++.h>
using namespace std;
class SGtree{
  vector<int>sg;
   SGtree(int n){
       sg.resize(4*n +1);
   }
   void build(int idx,int low,int high,vector<int>arr){
       if(low == high){
           sg[idx] = arr[low];
       }
       int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);
        sg[idx] = min(sg[2*idx+1],sg[2*idx+2]);    
   }
   int qurie(int idx,int low , int high,int l, int h){
      if(h<low || high>l){
          return INT_MAX;
      }
      if(low>=l && high<=h){
          return sg[idx];
      }
      int mid = (low+high)/2;
      int left = qurie(2*idx+1,low,mid,l,h);
      int right = qurie(2*idx+2,mid+1,high,l,h);
      return min(left,right);
   }
   void update(int idx,int low, int high,int i,int value){
       if(low == high){
           sg[idx] = value;
           return;
       }
       int mid = (low+high)/2;
       if(i<=mid) update(2*idx+1,low,mid,i,value);
       else update(2*idx+2,low,high,i,value);
       sg[idx] = min(sg[2*idx+1],sg[2*idx+2]);
   }
};