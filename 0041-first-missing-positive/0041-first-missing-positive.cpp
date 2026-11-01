class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int n=nums.size();
      //sabhi elements ko apne correct index pr place krenege isme 1 se n+1 tak element honge
      for(int i=0;i<n;i++){
              while(nums[i]>=1&&nums[i]<=n&&nums[nums[i]-1]!=nums[i]){//yeh 3rd wali condition infinite hone se bchati h loop ko samj exp.2 se index o pr 3 hai then nums[0]-1yani 2 or nums[2] pr -1 toh yeh swap hojayegi
                swap(nums[i],nums[nums[i]-1]);
              }
      }
      //find krenge pehla misplaced elemt wahi ans hoga
      for(int i=0;i<n;i++){
        if(nums[i]!=i+1) return i+1;
      }  
      return n+1;//agar koi misplace nhi mil rha toh next element ans hoga
    }
};