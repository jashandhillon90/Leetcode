class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int low=0;
        int size=0;
        for(int high=0;high<s.size();high++){
            mp[s[high]]++;
          while(mp[s[high]]>1){
            mp[s[low]]--;
            low++;
          }
          size=max(size,high-low+1);
        }
        return size;
    }
};