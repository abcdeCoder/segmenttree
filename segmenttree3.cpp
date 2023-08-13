#include<bits/stdc++.h>
using namespace std;
class info{
    public:
    int open,close,full;
    info(int open,int close,int full){
        this->open = open;
        this->close = close;
        this->full = full; 
    }
    info(){
        open = 0;
        close =0;
        full =0;
    }
};
info merge(info s1, info s2){
    info ans =  info(0,0,0);
    ans.full = s1.full + s2.full + min(s1.open,s2.close);
    ans.open =  s1.open +s2.open - min(s1.open,s2.close);
    ans.close = s1.close + s2.close - min(s1.open,s2.close);
    return ans;
}
void build(int idx,int low,int end,vector<info>& sg,string s){
    if(low == end){
        sg[idx].open = (s[low]=='(');
        sg[idx].close = (s[end]== ')');
        sg[idx].full = 0;
        return;
    }
    int mid = (low+end)/2;
    build(2*idx+1,low,mid,sg,s);
    build(2*idx+2,mid+1,end,sg,s);
   sg[idx] =  merge(sg[2*idx+1],sg[2*idx+2]);
}
info quries(int idx,int low,int end,int l,int r,vector<info>& sg){
    if(r<low || end<l) return info();
     if(low>=l && end<=r){
          return sg[idx];
      }
    int mid = (low+end)/2;
      info left = quries(2*idx+1,low,mid,l,r,sg);
      info right = quries(2*idx+2,mid+1,end,l,r,sg);
      return merge(left,right);
} 
void slove(){
  string s;
  cin>>s;
  int n = s.size();
  vector<info>sg(4*n);
  build(0,0,n-1,sg,s); 
  int q;
  cin>>q;
  while(q--){
      int l,r;
      cin>>l>>r;
      l--;
      r--;
      info ans = quries(0,0,n-1,l,r,sg);
      cout<<ans.full*2<<endl;
  }  
}

int main() {
    slove();

    return 0;
}
