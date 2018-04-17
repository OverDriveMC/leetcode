/**
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/
/**
将数排序,前一半组成一个最大堆,后一半组成一个最小堆(前一半元素大于等于后一半元素)
这样,当数据为奇数的时候,直接返回最大堆中的堆顶元素
当数据为偶数的时候,返回最大堆的堆顶元素和最小堆的堆顶元素的平均值
例如5,2,3,4,1,6,7,0,8
5进来时:  maxn,minn都为空,偶数个数,直接放入最大堆maxn里面,返回中间的数时,因为是奇数个数,所以返回maxn堆顶元素 5
2进来时: maxn={5},minn空,奇数个数, 需要将2与maxn的堆顶元素比较,然后将5放入最小堆,2放入最大堆, 
		maxn={2},minn={5}  返回(2+5)/2.0
3进来时,个数为偶数,所以需要往maxn里面添加元素, 先和minn的堆顶元素比较,发现没有5大,那么直接添加进maxn里面
		maxn={3,2}  minn={5}
4进来时,个数为奇数,需要往minn里面添加元素,将4和maxn[0]比较,将大的元素添加进minn里面
		maxn={3,2} minn={4,5}
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void Insert(int num)
    {
		//当前个数为奇数个
        if((maxn.size()+ minn.size())%2==1){
			/**
			需要两边平分元素,所以需要往minn里面添加元素
			maxn一定是有值的,不需要判是否为空(因为当前奇数个数,maxn里元素一定比minn里面多)
			将num与maxn[0]大的添加进minn里面
			*/
            if(num< maxn[0]){
				/**
				假如num没有maxn[0]大,先将maxn[0]添加进minn里面
				再从maxn里面删除maxn[0],然后将num添加进去
				*/
                minn.push_back(maxn[0]);
				/**
				greater是最小堆
				less是最大堆
				*/
                push_heap(minn.begin(),minn.end(),greater<int>() );
                pop_heap(maxn.begin(),maxn.end(),less<int>());
                maxn.pop_back();
                maxn.push_back(num);
                push_heap(maxn.begin(),maxn.end(),less<int>());
            }else{
                minn.push_back(num);
                push_heap(minn.begin(),minn.end(),greater<int>());
            }
        }else{
            if(minn.size()>0 && num >minn[0]){
                maxn.push_back(minn[0]);
                push_heap(maxn.begin(),maxn.end(),less<int>());
                pop_heap(minn.begin(),minn.end(), greater<int>() );
                minn.pop_back();
                minn.push_back(num);
                push_heap(minn.begin(),minn.end(),greater<int>());
            }else{
                maxn.push_back(num);
                push_heap(maxn.begin(),maxn.end(),less<int>());
            }
        }
    }

    double GetMedian()
    {
        if(maxn.size()+minn.size() ==0){
            return -1;
        }
        if( (maxn.size()+minn.size())%2==1  ){
            return maxn[0];
        }else{
            return (maxn[0]+minn[0])/2.0;
        }
    }
private:
    vector<int>maxn;
    vector<int>minn;
};

int main(){
    Solution s;
    vector<int> v{5,2,3,4,1,6,7,0,8};
    for(int i=0;i<v.size();i++){
        s.Insert(v[i]);
        cout<<s.GetMedian()<<endl;
    }
    return 0;
}
