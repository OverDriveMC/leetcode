#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        for(int i=0,k,l;i<words.size();i+=k){
            //每次添加k的单词,先判断第k个单词能否添加,然后再去添加第k个单词
			//后面取 =maxWidth
            for(k=l=0;i+k<words.size() && l+words[i+k].size()+k<=maxWidth;k++){
                l+=words[i+k].size();
            }
            //这里不能写成ss(words[i])会有问题,直接初始化只是会初始化一个大小,
			//后续通过<<不会保留初始化的字符串
            stringstream ss;
            ss<<words[i];
            for(int j=1;j<k;j++){
                int num=1;
                //要求最后一行每个单词之间只能相隔一个空格
                if(i+k<words.size()){
                    // 前 (L-l) % (k-1) 隔板之间需要一个额外的空格
					/**
					例如  O   O    O  O
					3个空格,假如有11个blank: 
						11/3=3
						11%3=2
					每个gap至少要插入3个空格,然后0,1两个gap要多插一个空格
					这里j从1开始 所以 j<=  blank % gap 的时候,需要多插一个空格
					*/
                    num=(maxWidth-l)/(k-1) +(j<=((maxWidth-l)%(k-1)));
                }
                string blank=string(num,' '  );
                ss<<blank;
                ss<<words[i+j];
            }
			//在最后一个单词后面,补上剩余的空格
            ss<<string(maxWidth- ss.str().size(),' ');
            res.push_back(ss.str());
        }
        return res;
    }
};



int main(){
    Solution s;
    string sa[]={"What","must","be","acknowledgment","shall","be"};
    vector<string> words(sa,sa+6);
    cout<<words.size()<<endl;
    vector<string>res=s.fullJustify( words, 16);
    for(auto s: res){
        cout<<s<<endl;
    }
    return 0;
}
