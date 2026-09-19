class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int max_x = max(x1,x2);
        int min_x = min(x1,x2);
        int max_y = max(y1,y2);
        int min_y = min(y1,y2);
        int x = max(min_x, min(xCenter, max_x));
        int y = max(min_y, min(yCenter, max_y));
        pair<int, int>p = {x, y};
        pair<int, int>p2 = {xCenter, yCenter};
        return dist(p, p2) <= radius*radius;
    }
    int dist(pair<int,int>p1, pair<int,int>p2){
        return (p1.first - p2.first)* (p1.first - p2.first) + (p1.second - p2.second) *(p1.second - p2.second);
    }
};