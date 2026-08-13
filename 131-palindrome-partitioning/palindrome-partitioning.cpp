class Solution {
public:
  bool ispalin(string s){
    string s2=s;
    reverse(s2.begin(),s2.end());
    return s==s2;
  }
  void getAllparts(string s,vector<string>& partitions,vector<vector<string>>& ans){
    if(s.size()==0){
        ans.push_back(partitions);
        return;
    }
    for(int i=0;i<s.size();i++){
     string part=s.substr(0,i+1);    //i+1 is length of substr
     if(ispalin(part)){
        partitions.push_back(part);
        getAllparts(s.substr(i+1),partitions,ans); //agle char pr cut lagayege
        partitions.pop_back();        //backtracking nya ele store krne k liye piche wale ko delete krna hoga
     }   
    }
  }
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        vector<vector<string>> ans;
        getAllparts(s,partitions,ans);
        return ans;
    }
};