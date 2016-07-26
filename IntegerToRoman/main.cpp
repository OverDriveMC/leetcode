
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        char* c[4][10]={
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };
        /**
        */
        string res;
        res.append(c[3][num/1000%10]);
        res.append(c[2][num/100%10]);
        res.append(c[1][num/10%10]);
        res.append(c[0][num%10]);
        return res;
    }
};
int main(){
    Solution s;
    cout<<s.intToRoman(1976)<<endl;
    cout<<s.intToRoman(1984)<<endl;
    cout<<s.intToRoman(1990)<<endl;
    return 0;
}
