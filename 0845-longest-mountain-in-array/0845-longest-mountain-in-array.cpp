class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        int ans = 0;
        int up = 1;
        int down = 1;
        int i = 1;
        while(i<n){
            if(arr[i] <= arr[i-1]) {i++; continue;}
            int start = i-1;
            while(i<n && arr[i] > arr[i-1]) ++i;
            if(i==n || arr[i] == arr[i-1]) continue;
            while( i< n && arr[i] < arr[i-1]) i++;
            ans = max(ans, i-start);
        }
          return ans;
    }
};

