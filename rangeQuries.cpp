#include<bits/stdc++.h>
using namespace std;
class STtree{
    public:
    vector<int>seg;
    vector<int>lazy;
    STtree(int n){
        seg.resize(n);
        lazy.resize(n);
    } 
    void build(int idx,int low,int end,vector<int>arr){
        if(low == end){
            this ->seg[idx] = arr[low];
            return;
        }
        int mid = (low+end)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,end,arr);
        this->seg[idx] = (this->seg[2*idx+1] + this->seg[2*idx+2]);
    }
    void update(int idx,int low,int end,int l,int r,int value){
           if(this->lazy[idx]!=0){
               this->seg[idx] += (end - low+1) * this->lazy[idx]; 
               if(low !=end){
               this->lazy[2*idx+1] += this->lazy[idx];
               this->lazy[2*idx+2] += this->lazy[idx];
           }
                 this->lazy[idx] =0;  
           }
           
           
           // low end l r low  end
           if(l>end || r<low){
               return ;
           }
           // l low end r
           if(low>=l && end<= r){
               this->seg[idx] += ((end-low)+1)*value;
               if(low != end){
                   this->lazy[2*idx+1] +=value;
                   this->lazy[2*idx+2] +=value;
               }
               return;
           }
           int mid = (low+end)/2;
           update(2*idx+1,low,mid,l,r,value);
           update(2*idx+2,mid+1,end,l,r,value);
           this->seg[idx] = (this->seg[2*idx+1] + this->seg[2*idx+2]);
    }
    int quries(int idx,int low , int end,int l,int r){
        if(this->lazy[idx] !=0){
            this->seg[idx] = ((end-low)+1)*this->lazy[idx];
            
            if(low != end){
            this->lazy[2*idx+1] += this->lazy[idx];
            this->lazy[2*idx+2] += this->lazy[idx];
        }
            this->lazy[idx] =0;  
          
        }
       
       
        if(l>end || r<low){
               return 0;
           }
        if(low>=l && end<= r){
               return this->seg[idx];
         }
         int mid = (low+end)/2;
         int left = quries(2*idx+1,low,mid,l,r);
         int right = quries(2*idx+2,mid+1,end,l,r);
         return (left+right);
    }
};

void slove(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    STtree s1(4*n);
    s1.build(0,0,n-1,arr);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type ==1){
            int l,r;
            cin>>l>>r;
            cout<<s1. quries(0,0,n-1,l,r)<<endl;
        }
        else{
            int l,r,value;
            cin>>l>>r>>value;
            s1.update(0,0,n-1,l,r,value);
        }
       
    }
}
int main() {
    slove();
    return 0;
}
