class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        // Convert all integers into strings
        for(int num : nums){
            arr.push_back(to_string(num));
        }
        // Custom sorting
        sort(arr.begin(), arr.end(), [](string a, string b){
            return a+b>b+a;
        });
        // If all numbers are zero
        if(arr[0]=="0"){
            return "0";
        }
        // Join all strings
        string ans = "";
        for(string s:arr){
            ans+=s;
        }
        return ans;
    }
};