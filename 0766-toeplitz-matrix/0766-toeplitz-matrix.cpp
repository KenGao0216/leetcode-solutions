class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i<m; ++i){
            int sx = i, sy = 0;
            int num = matrix[sx][sy];
            while(sx<m && sy < n){
                if(matrix[sx][sy] != num) return false;
                sx++;
                sy++;
            }
        }
        for(int i = 0; i<n; ++i){
            int sx = 0, sy = i;
            int num = matrix[sx][sy];
            while(sx<m && sy < n){
                if(matrix[sx][sy] != num) return false;
                sx++;
                sy++;
            }
        }
        return true;
    }
};