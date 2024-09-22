#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

string checkCollinear(vector<Point> &points) {
    int n = points.size();
    
    if (n == 2) {
        // If there are only two points, they always form a line
        int x1 = points[0].x, y1 = points[0].y;
        int x2 = points[1].x, y2 = points[1].y;
        if (x1 == x2) {
            return "x = " + to_string(x1);
        } else {
            double m = double(y2 - y1) / (x2 - x1);
            double c = y1 - m * x1;
            return "y = " + to_string(m) + "x + " + to_string(c);
        }
    }
    
    // General case for more than two points
    int x1 = points[0].x, y1 = points[0].y;
    int x2 = points[1].x, y2 = points[1].y;
    
    for (int i = 2; i < n; ++i) {
        int x3 = points[i].x, y3 = points[i].y;
        
        if ((y2 - y1) * (x3 - x1) != (y3 - y1) * (x2 - x1)) {
            return "0";
        }
    }
    
    // All points are collinear
    if (x1 == x2) {
        return "x = " + to_string(x1);
    } else {
        double m = double(y2 - y1) / (x2 - x1);
        double c = y1 - m * x1;
        return "y = " + to_string(m) + "x + " + to_string(c);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> points(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    
    string result = checkCollinear(points);
    cout << result << endl;
    
    return 0;
}
