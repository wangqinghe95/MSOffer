#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

/**
 * @brief 当值特别大的时候，会溢出，换成 long long 也不行，时间会溢出
 * 
 */
class Solution_Num {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> primeHash = getPrime(26);
        unordered_map<int, vector<string>> hash;
        for (auto &s : strs) {
            int cnt = 1;
            for (const char &c : s) {
                cnt *= primeHash[c-'a'];
            }

            hash[cnt].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &tmp : hash) {
            res.push_back(tmp.second);
        }

        return res;
    }
private:
    vector<int> getPrime(int num) {
        int prime = 2;
        vector<int> res;
        while(num > res.size()) {
            if (isPrime(prime)) {
                res.push_back(prime);
            }
            prime++;
        }
        
        return res;
    }
    bool isPrime(int num) {
        for (int i = 2; i <= num/2; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution_word {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;

        for (auto &str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(str);
        }

        for (auto &vec : hash) {
            res.push_back(vec.second);
        }

        return res;
    }
};

int main() {
    Solution_Num a;
    vector<string> s{"eat", "tea", "tan", "ate", "nat", "bat"};
    a.groupAnagrams(s);
    return 0;
}