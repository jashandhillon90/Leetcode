class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i=0,j=letters.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(letters[mid]<=target) i=mid+1;
            else j=mid-1;
        }if(i==letters.size()) return letters[0];//low last me pahunch gya or ele. found nhi hua
        return letters[i];
    }
};