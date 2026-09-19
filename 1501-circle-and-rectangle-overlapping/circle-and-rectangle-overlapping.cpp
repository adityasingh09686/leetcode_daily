class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                          int x2, int y2) {
            if (x1 > x2)
                swap(x1, x2);
            if (y1 > y2)
                swap(y1, y2);
            int closeX = max(x1, min(xCenter, x2));
            int closeY = max(y1, min(yCenter, y2));

            int dx = closeX - xCenter;
            int dy = closeY - yCenter;

            return (dx * dx + dy * dy) <=1LL* radius * radius;
        }
};