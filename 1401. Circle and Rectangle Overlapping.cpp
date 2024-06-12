class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = max(x1,min(x2,xCenter)) ; 
        int closestY = max(y1,min(y2,yCenter)) ; 
        closestX = xCenter - closestX ; 
        closestY = yCenter - closestY; 
        int distance = closestX*closestX+closestY*closestY ; 
        return distance <= radius*radius;
    }
};
