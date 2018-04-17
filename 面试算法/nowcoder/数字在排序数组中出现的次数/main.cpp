/**
统计一个数字在排序数组中出现的次数。
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int idx=lower_bound(data.begin(),data.end(),k)-data.begin();
        int idx2=upper_bound(data.begin(),data.end(),k)-data.begin();
        return idx2-idx;
    }
};

int main(){
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(3);
    //0
    cout<<lower_bound(vec.begin(),vec.end(),1)-vec.begin()<<endl;
    //2
    cout<<upper_bound(vec.begin(),vec.end(),1)-vec.begin()<<endl;
    //0
    cout<<lower_bound(vec.begin(),vec.end(),0)-vec.begin()<<endl;
    //0
    cout<<upper_bound(vec.begin(),vec.end(),0)-vec.begin()<<endl;
    //2
    cout<<lower_bound(vec.begin(),vec.end(),2)-vec.begin()<<endl;
    //2
    cout<<upper_bound(vec.begin(),vec.end(),2)-vec.begin()<<endl;
    //4
    cout<<lower_bound(vec.begin(),vec.end(),4)-vec.begin()<<endl;
    //4
    cout<<upper_bound(vec.begin(),vec.end(),4)-vec.begin()<<endl;
    return 0;
}
