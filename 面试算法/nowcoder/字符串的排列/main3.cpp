class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string>res;
        permutation(res,0,str);
        return res;
    }
    void permutation(vector<string>&res, int pos, string str){
        if(pos==str.size()-1){
            res.push_back(str);
            return;
        }
        unordered_set<char>us;
        sort(str.begin()+pos,str.end());
        for(int i=pos;i<str.size();i++){
            if(us.find(str[i])!= us.end() ){
                continue;
            }
            us.insert(str[i]);
            swap(str[i],str[pos]);
            permutation(res, pos+1,str);
            swap(str[i],str[pos]);
        }
    }
    
};

/**
都可以
每次保证 [pos,end)是有序的,然后开始交换？
原理不太懂。。。
*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string>res;
        permutation(res,0,str);
        return res;
    }
    void permutation(vector<string>&res, int pos, string str){
        if(pos==str.size()-1){
            res.push_back(str);
            return;
        }
        sort(str.begin()+pos,str.end());
        for(int i=pos;i<str.size();i++){
            if(i!=pos && str[i]==str[pos]){
                continue;
            }
            swap(str[i],str[pos]);
            permutation(res, pos+1,str);
            swap(str[i],str[pos]);
        }
    }
};
