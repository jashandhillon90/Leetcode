class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        // vector<int> ans;
        // for(int i=0;i<arr.size();i++){
        //     ans.push_back(arr[i]);
        //     if(arr[i]==0){
        //         ans.push_back(0);
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     arr[i]=ans[i];
        // }
     
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr.insert(arr.begin()+i,0);
                arr.pop_back();
                i++;
            }
        }
    }
};