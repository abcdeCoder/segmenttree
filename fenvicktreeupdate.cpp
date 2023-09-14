class Fentree{
public:
    vector<int>fenvicktree;
    vector<int> original;
    int n;
   
    Fentree(vector<int>& nums) {
        n = nums.size();
        fenvicktree.resize(n + 1, 0);
        original.resize(n, 0);

        for (int i = 0; i < n; i++) {
            update(i, nums[i]);
        }
    }
   
    
   
      void update(int i, int val) {
        int diff = val - original[i];
        original[i] = val;
        i++;
        while (i <= n) {
            fenvicktree[i] += diff;
            i += i & -i;
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
        return (sum(end+1) - sum(start));
    }  
};

class NumArray {
public:
    Fentree f;

    NumArray(vector<int>& nums) : f(nums) {}

    void update(int index, int val) {
        f.update(index, val);
    }

    int sumRange(int left, int right) {
        return f.findsum(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
