class Solution {
public:
    void Insert(int num)
    {
        if( (maxn.size() + minn.size())%2==1 ){
            //均分元素,添加进minn中
            if(*(maxn.begin() ) > num ){
                minn.insert( *(maxn.begin() ));
                maxn.erase( maxn.begin() );
                maxn.insert(num);
            }else{
                minn.insert(num);
            }
        }else{
            //添加进maxn中,将num与 minn[0]小的添加进maxn中
            if( minn.size()>0 &&  num> *(minn.begin())){
                maxn.insert(*(minn.begin())  );
                minn.erase( *(minn.begin() ) );
                minn.insert(num );
            }else{
                maxn.insert(num);
            }
        }
    }

    double GetMedian()
    { 
        if(maxn.size()+ minn.size() ==0){
            return -1;
        }
        if((maxn.size()+minn.size())%2==1 ){
            return *(maxn.begin());
        }else{
            return (*(maxn.begin()) +*(minn.begin()))/2.0;
        }
    }

private:
	//最大的在前面
    multiset<int, greater<int>>maxn;
	//最小的在前面
    multiset<int, less<int>>   minn;
};