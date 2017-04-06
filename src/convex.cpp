#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int64_t N, P = 4000000;
const long double pi = M_PI;

int64_t M = 20000000,
		r = M - 10.0;

double lb, ub;

struct Point {
	int64_t x, y;

	bool operator<(const Point &rhs) const {
		return x == rhs.x ? y < rhs.y : x < rhs.x;
	}
};

Point mid = { M, M }, curr;
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

bool valid(const Point& C) {
	const Point A = curr,
				B = mid;

	Point 	BA = { B.x - A.x, B.y - A.y },
			CA = { C.x - A.x, C.y - A.y };

	int64_t dot = BA.x * CA.x + BA.y * CA.y,
			pcross = BA.x * CA.y - BA.y * CA.x;

	long double rad = atan2(pcross, dot),
				angle = abs(rad * 180.0 / pi);

	return angle < ub && angle > lb;
}

int main() {
	cin >> N;

	lb = 80,
	ub = 90.0;

	cout << setprecision(20) << lb << " " << ub << endl;

	ps.push_back({ M + r, M });
	curr = ps[0];

	for (int i = 1; i < P; i++) {
		long double x = M + r * cos(2 * pi * i / P),
					y = M + r * sin(2 * pi * i / P);

		Point a = { (int64_t)floor(x), (int64_t)floor(y) };
		if (valid(a)) {
			curr = a;
			ps.push_back(a);
		}

		Point b = { (int64_t)floor(x), (int64_t)ceil(y) };
		if (valid(b)) {
			curr = b;
			ps.push_back(b);
		}

		Point c = { (int64_t)ceil(x) , (int64_t)floor(y) };
		if (valid(c)) {
			curr = c;
			ps.push_back(c);
		}

		Point d = { (int64_t)ceil(x) , (int64_t)ceil(y) };
		if (valid(d)) {
			curr = d;
			ps.push_back(d);
		}
	}


	cout << ps.size() << endl;
	vector<Point> hull = convex_hull();
	cout << hull.size() << endl;

	// for (int i = 0 ; i < N; i++) {
	// 	cout << "(" << hull[i].x << "," << hull[i].y << "), ";
	// }

	return 0;
}