/**
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
线段树裸题,注意下标从0开始的
*/

class NumArray {
public:
	void pushup(int o,int l,int r){
		sum[o]=sum[o<<1] + sum[o<<1|1];
	}
	
	void build(int o,int l,int r,vector<int>& nums){
		if(l==r){
			sum[o]=nums[cnt++];
			return ;
		}
		int m=(l+r)>>1;
		build(o<<1,l,m,nums);
		build(o<<1|1,m+1,r,nums);
		pushup(o,l,r);
		//cout<<o<<"  "<<sum[o]<<endl;
	}

    NumArray(vector<int> nums) {
        if(nums.size()==0){
            return ;
        }
		sum.resize(nums.size()<<2);
		cnt=0;
		build(1,1,nums.size(),nums);
	}
    void update(int o,int l,int r,int i, int val){
		if(l==r){
			sum[o]=val;
			return ;
		}
		int m=(l+r)>>1;
		if(i<=m){
			update(o<<1,l,m,i,val);
		}else{
			update(o<<1|1,m+1,r,i,val);
		}
		pushup(o,l,r);
	}
	
    void update(int i, int val) {
		update(1,1,cnt,1+i,val);
    }
    int query(int o,int l,int r, int ql,int qr){
		if(ql<=l && r<=qr){
			return sum[o];
		}
		int ret=0;
		int m=(l+r)>>1;
		if(ql<=m){
			ret+=query(o<<1,l,m,ql,qr);
		}
		if(qr>m){
			ret+=query(o<<1|1,m+1,r,ql,qr);
		}
		return ret;
	}
	
    int sumRange(int i, int j) {
		return query(1,1,cnt,i+1,j+1);
    }
private:
	vector<int>sum;
	int cnt=0;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */