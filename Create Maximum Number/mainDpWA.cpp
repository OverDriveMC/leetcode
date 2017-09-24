#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void mergeVector(vector<int>& nums1, vector<int>& nums2,vector<int>& res){
        if(nums1.size()==0){
            for(int i=nums2.size()-1;i>=0;i--){
                res.push_back(nums2[i]);
            }
            return ;
        }
        if(nums2.size()==0){
            for(int i=nums1.size()-1;i>=0;i--){
                res.push_back(nums1[i]);
            }
            return;
        }

        int pos1=nums1.size()-1,pos2=nums2.size()-1;
        while(pos1>=0 || pos2>=0){
            res.push_back(compare(nums1,pos1,nums2,pos2) ? nums1[pos1--] : nums2[pos2--]      );
        }

    }
    bool compare(vector<int>& nums1, int pos1, vector<int>& nums2, int pos2){
        while( pos1 >=0  && pos2 >=0 &&  nums1[pos1] == nums2[pos2]){
            pos1--;
            pos2--;
        }
        if(pos2<0 || (pos1>=0 && nums1[pos1] >nums2[pos2]) ){
            return true;
        }else{
            return false;
        }

    }


    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        //cout<<"----------------------"<<endl;
        vector<int>res,Maxn;
        for(int i=0;i<=k;i++){
            res.clear();
            vector<int>temp1;
            vector<int>temp2;
            if(i>nums1.size()){
                temp1=findMax(nums1,nums1.size());
                temp2=findMax(nums2,k-nums1.size());
                break;
            }else if((k-i)>nums2.size()){
                temp1=findMax(nums1,k-nums2.size());
                temp2=findMax(nums2,nums2.size());
                i=k-nums2.size();
            }else{
                temp1=findMax(nums1,i);
                temp2=findMax(nums2,k-i);
            }


            mergeVector(temp1,temp2,res);

/*
            cout<<res.size()<<"  "<<res[0]<<"   "<<res[1]<<endl;


            cout<<"Maxn:"<<endl;
            for(int i=0;i<Maxn.size();i++){
                cout<<Maxn[i]<<"  ";
            }
            cout<<endl;
*/


            if(Maxn.size()==0){
                Maxn.insert(Maxn.begin(),res.begin(),res.end());
            }else{
                for(int i=0;i<Maxn.size();i++){
                    if(Maxn[i] < res[i]){
                        Maxn.clear();
                        Maxn.insert(Maxn.begin(),res.begin(),res.end());
                        break;
                    }else if(Maxn[i] > res[i]){
                        break;
                    }
                }
            }
        }
        //cout<<"----------------------"<<endl;
        return Maxn;
    }
    vector<int> findMax(const vector<int>& nums,int cnt){
        vector<int>res;
        if(cnt==0){
            return res;
        }else if(cnt==nums.size()){

            /*
            for(int i=nums.size()-1;i>=0;i--){
                res.push_back(nums[i]);
            }
            return res;
            */
        }


        int **dp=new int*[nums.size()+1];
        for(int i=0;i<=nums.size();i++){
            dp[i]=new int[cnt+1];
        }
        for(int i=0;i<nums.size();i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=cnt;i++){
            dp[0][i]=nums[0];
        }
/**
* 这里dp 会越界
*/
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=cnt;j++){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]*10+nums[i] );
            }
        }
        /**
        * 这里取nums.size()-1
        * 所以数组为0要特判
        */
        int result=dp[nums.size()-1][cnt];
        delete[]dp;

        cout<<"in:"<<cnt<<endl;
        while(result){
            cout<<result%10<<" ";
            res.push_back(result%10);
            result/=10;
        }
        int cnums=res.size();
        while(cnums<cnt){
            res.push_back(0);
            cnums++;
        }
        cout<<endl;
        return res;
    }

};
int main(){
    vector<int>nums1;
    vector<int>nums2;
    nums1.push_back(3);
    nums1.push_back(4);
    nums1.push_back(6);
    nums1.push_back(5);
    nums2.push_back(9);
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(8);
    nums2.push_back(3);
    Solution s;

    vector<int>result=s.maxNumber(nums1,nums2,5);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;

    nums1.clear();
    nums1.push_back(6);
    nums1.push_back(7);
    nums2.clear();
    nums2.push_back(6);
    nums2.push_back(0);
    nums2.push_back(4);
    result=s.maxNumber(nums1,nums2,5);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;


    nums1.clear();
    nums1.push_back(3);
    nums1.push_back(9);
    nums2.clear();
    nums2.push_back(8);
    nums2.push_back(9);
    result=s.maxNumber(nums1,nums2,3);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;


    nums1.clear();
    nums2.clear();
    nums2.push_back(1);
    result=s.maxNumber(nums1,nums2,1);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;

    cout<<"-------------------------------------"<<endl;
    nums1.clear();
    nums1.push_back(2);
    nums1.push_back(5);
    nums1.push_back(6);
    nums1.push_back(4);
    nums1.push_back(4);
    nums1.push_back(0);
    nums2.clear();
    nums2.push_back(7);
    nums2.push_back(3);
    nums2.push_back(8);
    nums2.push_back(0);
    nums2.push_back(6);
    nums2.push_back(5);
    nums2.push_back(7);
    nums2.push_back(6);
    nums2.push_back(2);
    result=s.maxNumber(nums1,nums2,15);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;
    cout<<"-------------------------------------"<<endl;
    nums1.clear();
    nums2.clear();
    nums1.push_back(1);
    nums1.push_back(2);
    result=s.maxNumber(nums1,nums2,2);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;
    cout<<"-------------------------------------"<<endl;

    nums1.clear();
    nums1.push_back(6);
    nums1.push_back(5);
    nums1.push_back(4);
    nums1.push_back(6);
    nums1.push_back(3);
    nums1.push_back(7);
    nums1.push_back(5);
    nums1.push_back(6);
    nums1.push_back(4);
    nums1.push_back(5);
    nums1.push_back(6);
    nums1.push_back(4);
    nums2.clear();
    nums2.push_back(8);
    nums2.push_back(8);
    nums2.push_back(6);
    nums2.push_back(0);
    result=s.maxNumber(nums1,nums2,16);
    cout<<"res:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;
    cout<<"-------------------------------------"<<endl;


    return 0;
}
