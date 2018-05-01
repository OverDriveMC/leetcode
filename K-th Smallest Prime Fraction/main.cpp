/**
给一个有序列表A,里面包含1,以及一些其它的素数,对于所有列表中的所有p<q,组成一个分数 p/q
求第K大的分数
Examples:
Input: A = [1, 2, 3, 5], K = 3
Output: [2, 5]
Explanation:
The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, 2/3.
The third fraction is 2/5.

Input: A = [1, 7], K = 1
Output: [1, 7]
*/
/**
如果A={1,7,23,29,47}
那么有:
1/47 < 1/29 < 1/23 < 1/7
7/47 < 7/29 < 7/23
23/47 <23/49
29/47
可以采用优先队列的方法,把第一列先送入队列,因为他们一定是每行的最小,选出最小的之后,加入该行的后续元素
直到找到K-1个最小的元素
维护一个最小堆,每次删除最小的元素,一共删掉K-1个,即得到第K大的元素
*/

#include<bits/stdc++.h>

using namespace std;

struct Frac{
	/**
	除了维护分子分母,还要维护响应的下标
	不然没法找到该行的下一个元素
	*/
    int a,b;
    int idx1,idx2;
    Frac(int a,int b,int idx1,int idx2):a(a),b(b),idx1(idx1),idx2(idx2){}
    bool operator< (const Frac &f)const{
        return this->a*f.b > this->b *f.a;
    }
};

class Solution{
public:
    vector<int>kthSmallestPrimeFraction(vector<int>&vec, int K){
        vector<Frac>fs;
        if( (vec.size()-1)*vec.size()/2 <K ){
            return vector<int>();
        }
        for(int i=0;i<vec.size()-1;i++){
            ///前两个是分子 分母
            ///后两个是分子 分母所对应的下标
            fs.push_back(Frac(vec[i],vec[vec.size()-1],i,vec.size()-1));
        }
        ///less是最大堆,所以这里的 < 其实是重载的>
        make_heap(fs.begin(),fs.end(),less<Frac>());
        for(int i=0;i<K-1;i++){
            Frac f=fs[0];
            pop_heap(fs.begin(),fs.end());
            fs.pop_back();
			/**
			需要判断是否该行的元素已经加完,每次[idx1,idx2-1]即是下一个需要添加的元素
			假如idx1>= idx2-1说明该行已经加完 (因为有条件 p<q,形成的一定是个真分数)
			*/
            if(f.idx2-1 > f.idx1){
                fs.push_back(Frac(vec[f.idx1],vec[f.idx2-1] ,f.idx1,f.idx2-1 ));
                push_heap(fs.begin(),fs.end());
            }
        }
        return {fs[0].a, fs[0].b};
    }

};

int main(){
    Solution s;
    vector<int>v={1,2,3,5};
    vector<int>res=s.kthSmallestPrimeFraction(v,3);
    cout<<res[0]<<"  "<<res[1]<<endl;
    return 0;
}
