#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        strOrigin = s;
        vector<string> res;
        dfs(res, "", 0, "", 0);
        return res;
    }
private:
    void dfs(vector<string>& res ,string seg, int segCount ,string strIp, int index){
        if(segCount == 3 && index == strOrigin.size() && isValidSeg(seg)){
            res.push_back(strIp+seg);
            return;
        }

        if(index < strOrigin.size() && segCount <= 3){
            string tmp = seg+strOrigin[index];

            // 将当前的字符继续添加到当前的ip分段中
            if(isValidSeg(tmp)) {
                dfs(res, tmp, segCount, strIp, index+1);
            }

            // 开一个新的分段，把当前字符当做第一个字符，并且ip加上当前的分段
            if(seg.size() > 0 && segCount < 3) {
                string str{strOrigin[index]};
                dfs(res, str, segCount+1, strIp+seg+".", index+1);
            }
        }
    }
    bool isValidSeg(string& seg){
        return stoi(seg) <= 255 && (seg == "0" || seg[0] != '0');
    }
private:
    string strOrigin;
};

class Solution_1 {
public:
    vector<string> restoreIpAddresses(string s) {
        strOrigin = s;
        n = s.size();

        init();

        vector<string> res;
        for(auto& vec : vecPointOrder) {
            string strFirst = s.substr(0, vec[0]);
            string strSecond = s.substr(vec[0],vec[1]-vec[0]);
            string strThird = s.substr(vec[1], vec[2]-vec[1]);
            string strForth = s.substr(vec[2],n-vec[2]);
            res.push_back(strFirst+"."+strSecond+"."+strThird+"."+strForth);
        }   
        return res;
    }
private:
    void init(){
        for(int i = 1; i <= 3; ++i) {
            for (int j = i+1; j <= i+3; ++j) {
                for(int k = j+1; k <= j+3; ++k) {
                    if(isValid(i,j,k)){
                        vecPointOrder.push_back({i,j,k});
                    }
                }
            }
        }

    }
    bool isValid(int i, int j, int k) {
        if(k < n-3 || k > n-1) {
            return false;
        }

        if(i > 1 && strOrigin[0] == '0') {
            return false;
        }
        if(j-i > 1 && strOrigin[i] == '0') {
            return false;
        }
        if(k-j > 1 && strOrigin[j] == '0') {
            return false;
        }
        if(n-k > 1 && strOrigin[k] == '0') {
            return false;
        }

        if(isValidNumber(0,i) && isValidNumber(i,j) && isValidNumber(j,k) && isValidNumber(k,n)){
            return true;
        }
        return false;
    }
    bool isValidNumber(int startIndex, int endIndex) {
        int number = 0;
        for (int i = startIndex; i < endIndex; ++i) {
            if(strOrigin[i] < '0' || strOrigin[i] > '9') {
                return false;
            }
            number = number * 10 + (strOrigin[i] - '0');
        }
        if(number >= 0 && number <= 255) {
            return true;
        }

        return false;
    }
    int getNumber(string& s, int startIndex, int nWidth) {
        if(s[startIndex] = '0' && nWidth != 1) {
            return -1;
        }

        int number = stoi(s.substr(startIndex, nWidth));
        if(number >= 0 && number <= 255) {
            return number;
        }

        return -1;
    }
private:
    vector<vector<int>> vecPointOrder;
    vector<int> STEP = {1,2,3};
    string strOrigin;
    int n;
};

int main()
{
    // string s = "255255255255";
    // string s = "010010";
    // string s = "1111";
    // string s = "010010";
    string s = "10203040";

    Solution a;
    vector<string> res = a.restoreIpAddresses(s);
    for(auto& s : res) {
        cout << s << endl;
    }

    return 0;
}