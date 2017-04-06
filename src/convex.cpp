#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int64_t N;
const long double pi = M_PI,
				  M = 20000000,
			 	  r = M - 10.0;

struct Point {
	int64_t x, y;

	bool operator<(const Point &rhs) const {
		return x == rhs.x ? y < rhs.y : x < rhs.x;
	}
};

vector<Point> ps;


// Check orientation of point triplets
int64_t orient(Point p, Point q, Point r) {
	int64_t v = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);
	if(v == 0) return 0;
	return v < 0 ? -1 : 1;
}

//Convex Hull
vector<Point> convex_hull() {
    int n = ps.size(), k = 0;
    vector<Point> hull(2 * n);

    sort(ps.begin(), ps.end());

    for(int i = 0; i < n; i++) {
        while(k >= 2 && orient(hull[k - 2], hull[k - 1], ps[i]) <= 0) k--;
        hull[k++] = ps[i];
    }

    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && orient(hull[k - 2], hull[k - 1], ps[i]) <= 0) k--;
        hull[k++] = ps[i];
    }

    hull.resize(k - 1);
    return hull;
}

int main() {
	cout << "HUH" << endl;
	cin >> N;
	vector<Point> hull;
	double eps = 0.01;
	cout << "wtf" << endl;
	while(hull.size() < min(N,(int64_t)400000) ){
		for (int i = 0; i < N; i++) {
			long double x = M + r * cos(2 * pi * i / N),
						y = M + r * sin(2 * pi * i / N);
			int64_t		px = (int64_t)round(x),
						py = (int64_t)round(y);
			if((px - x)*(px - x) + (py - y)*(py - y) < eps){
				ps.push_back({px,py});
			}
			// ps[i] = { (int64_t)round(x), (int64_t)round(y) };
			// ps[4 * i + 1] = { (int64_t)floor(x), (int64_t)ceil(y) };
			// ps[4 * i + 2] = { (int64_t)ceil(x) , (int64_t)floor(y) };
			// ps[4 * i + 3] = { (int64_t)ceil(x) , (int64_t)ceil(y) };

			// if (x >= 0 && y >= 0) ps[4 * i + 3] = { (int64_t)M, (int64_t)M };
			// if (x < 0 && y >= 0) ps[4 * i + 1] = { (int64_t)M, (int64_t)M };
			// if (x >= 0 && y < 0) ps[4 * i + 2] = { (int64_t)M, (int64_t)M };
			// if (x < 0 && y < 0) ps[4 * i] = { (int64_t)M, (int64_t)M };
		}

		hull = convex_hull();
		cout << hull.size() << endl;
		eps *= 2;
		N *= 2;
	}

	// for (int i = 0 ; i < hull.size(); i++) {
	// 	cout << "(" << hull[i].x << "," << hull[i].y << "), ";
	// }

	return 0;
}