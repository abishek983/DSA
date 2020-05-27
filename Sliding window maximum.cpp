// https://leetcode.com/problems/minimum-window-substring/submissions/

class Solution {
public:
    bool isMatch(int a[],int b[]){
        for(int i=0;i<256;i++){
            if(b[i]<a[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int a[257]={},b[257]={};
        for(char c:t)
            a[(int)c]++;
        int j=0; int count = INT_MAX;
        string temp="";
        for(int i=0;i<s.length();i++){
            b[s[i]]++;
            while(isMatch(a,b)){
                if(count>i-j+1){
                    temp = s.substr(j,i-j+1);
                    count = i-j+1;
                }

                b[s[j]]--;
                j++;
            }
        }
        return temp;
    }
};
