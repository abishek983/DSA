// https://leetcode.com/problems/reorganize-string/submissions/

// a_a_a_ 6/2 (3+1)
// a_a 3/2 (1+1)
// a_a_a 5/2 (2+1)
class Solution {
public:
    string reorganizeString(string s) {
        int arr[26] = {};
        int count = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            char c = s[i];
            if(arr[c-'a']==0){
                count++;
            }
            arr[c-'a']++;
        }
        string ans = "";
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++){
            if(arr[i])
                pq.push({arr[i],'a'+i});
        }
        pair<int,char> p; p = pq.top();
        if(p.first>(n+1)/2)
            return ans;
        while(!pq.empty()){
            pair<int,char> f = pq.top(); pq.pop();
            ans.push_back(f.second);
            f.first--;
            if(!pq.empty()){
                pair<int,char> s = pq.top(); pq.pop();
                ans.push_back(s.second);
                s.first--;
                if(s.first!=0)
                    pq.push(s);
            }
            if(f.first!=0)
                    pq.push(f);
                
        }
        return ans;
    }
};
