class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=0;
        int n=heights.size();
        vector<int> rp(n);
        vector<int> lp(n);
        stack <int> st;
        // left smaller value
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) lp[i]=-1;
            else lp[i]=st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
     for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) rp[i]=n;
            else rp[i]=st.top();
            st.push(i);
        }
      for(int i=0;i<n;i++){
            int area=heights[i]*(rp[i]-lp[i]-1);
            maxarea = max(maxarea,area);
            
        }
        return maxarea;
        
    }
};