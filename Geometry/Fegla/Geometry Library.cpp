// Check if you need long double.
// Try to handle the Corner Cases.

#include <bits/stdc++.h>
using namespace std;

typedef complex<long double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine

enum STATE {
	IN, OUT, BOUNDRY
};


point projectOnLine(point p, point a, point b) {
    return a + vec(a, b) * dot(vec(a, p), vec(a, b)) / length(vec(a, b));
}

bool intersect(const point &a, const point &b, const point &p, const point &q,
              point &ret) {
    //handle degenerate cases (2 parallel lines, 2 identical lines,   line is 1 point)
    ld d1 = cross(p - a, b - a);
    ld d2 = cross(q - a, b - a);
    ret = (d1 * q - d2 * p) / (d1 - d2);
    if(fabs(d1 - d2) > EPS) return 1;
    return 0;
}
//int intersect(const point &a, const point &b, const point &p, const point &q,
//              point &ret) {
//    //handle degenerate cases (2 parallel lines, 2 identical lines,   line is 1 point)
//    ld d1 = cross(p - a, b - a);
//    ld d2 = cross(q - a, b - a);
//    ret = (d1 * q - d2 * p) / (d1 - d2);
//    if(fabs(d1 - d2) > EPS) return 1;
//    if ( !d1 && !d2 )
//        return (same( a , p ) || same( a , q ) || same( b , p ) || same( b , q ) ? -2 : -1 ) ;
//    //sum of sames == 4 -->> identical points
//    //( same(a,p) & same(b,q) ) || ( same(a,q) & same(b,p) )== 1 -->> identical lines
//    return 0;
//}

bool pointOnLine(const point& a, const point& b, const point& p) {
    // degenerate case: line is a point
    return fabs(cross(vec(a,b),vec(a,p))) < EPS;
}

bool pointOnRay(const point& a, const point& b, const point& p) {
    //IMP NOTE: a,b,p must be collinear
    return dot(vec(a,p), vec(a,b)) > -EPS;
}

bool pointOnSegment(const point& a, const point& b, const point& p) {
    if(!colliner(a,b,p)) return 0;
    return pointOnRay(a, b, p) && pointOnRay(b, a, p);
}

ld pointLineDist(const point& a, const point& b, const point& p) {
	// handle degenrate case: (a,b) is point

	return fabs(cross(vec(a,b),vec(a,p)) / length(vec(a,b)));
}

ld pointSegmentDist(const point& a, const point& b, const point& p) {
	if (dot(vec(a,b),vec(a,p)) < EPS)
		return length(vec(a,p));
	if (dot(vec(b,a),vec(b,p)) < EPS)
		return length(vec(b,p));
	return pointLineDist(a, b, p);
}
point projectedPointOnLine(point &A,point &B,point &p){
  	point e1 = B-A;
  	point e2 = p-A;
  	double val = dot(e1, e2);
  	double len = dot(e1,e1);
  	point ret = A + val*e1/len;
  	return ret + ret - p ;
}

int segmentLatticePointsCount(int x1, int y1, int x2, int y2) {
	return abs(__gcd(x1 - x2, y1 - y2)) + 1;
}

ld triangleAreaBH(ld b, ld h) {
	return b * h / 2;
}

ld triangleArea2sidesAngle(ld a, ld b, ld t) {
	return fabs(a * b * sin(t) / 2);
}

ld triangleArea2anglesSide(ld t1, ld t2,
		ld s) {
	return fabs(s * s * sin(t1) * sin(t2) / (2 * sin(t1 + t2)));
}

ld triangleArea3sides(ld a, ld b, ld c) {
	ld s((a + b + c) / 2);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

ld triangleArea3points(const point& a, const point& b, const point& c) {
	return fabs(cross(a,b) + cross(b,c) + cross(c,a)) / 2;
}

//count interior
int picksTheorm(int a, int b) {
	return a - b / 2 + 1;
}

//get angle opposite to side a
ld cosRule(ld a, ld b, ld c) {
        // Handle denom = 0
	ld res = (b * b + c * c - a * a) / (2 * b * c);
	if ( fabs(res-1)<EPS)
                res = 1;
        if ( fabs(res+1)<EPS)
                res = -1;
	return acos(res);
}

ld sinRuleAngle(ld s1, ld s2, ld a1) {
        // Handle denom = 0
	ld res = s2 * sin(a1) / s1;
	if ( fabs(res-1)<EPS)
                res = 1;
        if ( fabs(res+1)<EPS)
                res = -1;
	return asin(res);
}

ld sinRuleSide(ld s1, ld a1, ld a2) {
        // Handle denom = 0
	ld res = s1 * sin(a2) / sin(a1);
	return fabs(res);
}

int circleLineIntersection(const point& p0, const point& p1, const point& cen,
		ld rad, point& r1, point & r2) {

	// handle degenerate case if p0 == p1
	ld a, b, c, t1, t2;
	a = dot(p1-p0,p1-p0);
	b = 2 * dot(p1-p0,p0-cen);
	c = dot(p0-cen,p0-cen) - rad * rad;
	ld det = b * b - 4 * a * c;
	int res;
	if (fabs(det) < EPS)
		det = 0, res = 1;
	else if (det < 0)
		res = 0;
	else
		res = 2;
	det = sqrt(det);
	t1 = (-b + det) / (2 * a);
	t2 = (-b - det) / (2 * a);
	r1 = p0 + t1 * (p1 - p0);
	r2 = p0 + t2 * (p1 - p0);
	return res;
}



/*
 *        u
 *       /|\
 *      / | \
 *    a/  |  \b
 *    /   |m  \
 *   /____|____\
 *  p  h   c-h  q
 */

int dcmp(const ld &a, const ld &b) {
    if (fabs(a - b) < EPS)
        return 0;
    return ((a > b) << 1) - 1;
}

int triangleThirdPoint(const point &p, const point &q, const ld &a,
                       const ld &b, point &u1, point &u2) {
    point pq = vec(p, q);
    ld c = length(pq);
    ld arr[] = { a, b, c };
    sort(arr, arr + 3);
    if (dcmp(arr[0] + arr[1], arr[2]) < 0)
        return false;

    //m^2=a^2-h^2
    //m^2=b^2-(c-h)^2
    //m^2=b^2-(c^2-2ch+h^2)
    //m^2=b^2-c^2+2ch-h^2
    //a^2-h^2=b^2-c^2+2ch-h^2
    //0=b^2-c^2+2ch-h^2-a^2+h^2
    //0=b^2-c^2+2ch-a^2
    //2ch=a^2-b^2+c^2
    //h=(a^2-b^2+c^2)/2c
    ld h = (a * a - b * b + c * c) / (2.0 * c);
    ld sq=a * a - h * h;
    if(!dcmp(sq,0))sq=0;
    ld m = sqrt(sq);
    point npq = normalize(pq);
    point prp = perp(npq);
    u1 = p + (npq * h) + m * prp;
    u2 = p + (npq * h) - m * prp;
    return 1 + (dcmp(arr[0] + arr[1], arr[2]) != 0);
}

int circleCircleIntersection(const point &c1, const ld&r1,
		const point &c2, const ld&r2, point &res1, point &res2) {
	if (same(c1,c2) && fabs(r1 - r2) < EPS) {
		res1 = res2 = c1;
		return fabs(r1) < EPS ? 1 : OO;
	}
	ld len = length(vec(c1,c2));
	if (fabs(len - (r1 + r2)) < EPS || fabs(fabs(r1 - r2) - len) < EPS) {
		point d, c;
		ld r;
		if (r1 > r2)
			d = vec(c1,c2), c = c1, r = r1;
		else
			d = vec(c2,c1), c = c2, r = r2;
		res1 = res2 = normalize(d) * r + c;
		return 1;
	}
	if (len > r1 + r2 || len < fabs(r1 - r2))
		return 0;
	ld a = cosRule(r2, r1, len);
	point c1c2 = normalize(vec(c1,c2)) * r1;
	res1 = rotate(c1c2,a) + c1;
	res2 = rotate(c1c2,-a) + c1;
	return 2;
}

void circle2(const point& p1, const point& p2, point& cen, ld& r) {
	cen = mid(p1,p2);
	r = length(vec(p1,p2)) / 2;
}

bool circle3(const point& p1, const point& p2, const point& p3, point& cen,
		ld& r) {
	point m1 = mid(p1,p2);
	point m2 = mid(p2,p3);
	point perp1 = perp(vec(p1,p2));
	point perp2 = perp(vec(p2,p3));
	bool res = intersect(m1, m1 + perp1, m2, m2 + perp2, cen);
	r = length(vec(cen,p1));
	return res;
}

STATE circlePoint(const point & cen, const ld & r, const point& p) {
	ld lensqr = lengthSqr(vec(cen,p));
	if (fabs(lensqr - r * r) < EPS)
		return BOUNDRY;
	if (lensqr < r * r)
		return IN;
	return OUT;
}

int tangentPoints(const point & cen, const ld & r, const point& p,
		point &r1, point &r2) {
	STATE s = circlePoint(cen, r, p);
	if (s != OUT) {
		r1 = r2 = p;
		return s == BOUNDRY;
	}
	point cp = vec(cen,p);
	ld h = length(cp);
	ld a = acos(r / h);
	cp = normalize(cp) * r;
	r1 = rotate(cp,a) + cen;
	r2 = rotate(cp,-a) + cen;
	return 2;
}

typedef pair<point, point> segment;

void getCommonTangents(point c1, ld r1, point c2, ld r2, vector<segment> &res) {
  if (r1 < r2) swap(r1, r2), swap(c1, c2);
  ld d = length(c1 - c2);
  ld theta = acos((r1 - r2) / d);
  point v = c2 - c1;
  v = v / hypot(v.imag(), v.real());
  point v1 = v * exp(point(0, theta));
  point v2 = v * exp(point(0, -theta));
  res.clear();
  res.push_back(segment(c1 + v1 * r1, c2 + v1 * r2));
  res.push_back(segment(c1 + v2 * r1, c2 + v2 * r2));
  theta = acos((r1 + r2) / d);
  v1 = v * exp(point(0, theta));
  v2 = v * exp(point(0, -theta));
  res.push_back(segment(c1 + v1 * r1, c2 - v1 * r2));
  res.push_back(segment(c1 + v2 * r1, c2 - v2 * r2));
}

ld calcArc(point p1, point p2) {
	ld d = length(vec(p1, p2));
	ld ang = (angle(vec(cen, p1)) - angle(vec(cen, p2))) * 180 / M_PI;
	if (ang < 0)
		ang += 360;
	ang = min(ang, 360 - ang);
	return r * ang * M_PI / 180;
}
// minimum enclosing circle
//init p array with the points and ps with the number of points
//cen and rad are result circle
//you must call random_shuffle(p,p+ps); before you call mec
#define MAXPOINTS 100000
point p[MAXPOINTS], r[3], cen;
int ps, rs;
ld rad;

void mec() {
	if (rs == 3) {
		circle3(r[0], r[1], r[2], cen, rad);
		return;
	}
	if (rs == 2 && ps == 0) {
		circle2(r[0], r[1], cen, rad);
		return;
	}
	if (!ps) {
		cen = r[0];
		rad = 0;
		return;
	}
	ps--;
	mec();
	if (circlePoint(cen, rad, p[ps]) == OUT) {
		r[rs++] = p[ps];
		mec();
		rs--;
	}
	ps++;

}

//to check if the points are sorted anti-clockwise or clockwise
//remove the fabs at the end and it will return -ve value if clockwise
ld polygonArea(const vector<point>&p) {
	ld res = 0;
	for (int i = 0; i < sz(p); i++) {
		int j = (i + 1) % sz(p);
		res += cross(p[i],p[j]);
	}
	return fabs(res) / 2;
}

// return the centroid point of the polygon
// The centroid is also known as the "centre of gravity" or the "center of mass". The position of the centroid
// assuming the polygon to be made of a material of uniform density.
/*
point polyginCentroid(vector<point> &polygon) {
	point res(0, 0);
	ld a = 0;
	for (int i = 0; i < (int) polygon.size(); i++) {
		int j = (i + 1) % polygon.size();
		res.X += (polygon[i].X + polygon[j].X) * (polygon[i].X * polygon[j].Y
				- polygon[j].X * polygon[i].Y);
		res.Y += (polygon[i].Y + polygon[j].Y) * (polygon[i].X * polygon[j].Y
				- polygon[j].X * polygon[i].Y);
		a += polygon[i].X * polygon[j].Y - polygon[i].Y * polygon[j].X;
	}
	a *= 0.5;
	res.X /= 6 * a;
	res.Y /= 6 * a;
	return res;
}
*/

int picksTheorm(vector<point>& p) {
	ld area = 0;
	int bound = 0;
	for (int i = 0; i < sz(p); i++) {
		int j = (i + 1) % sz(p);
		area += cross(p[i],p[j]);
		point v = vec(p[i],p[j]);
		bound += abs(__gcd((int) v.X, (int) v.Y));
	}
	area /= 2;
	area = fabs(area);
	return round(area - bound / 2 + 1);
}

void polygonCut(const vector<point>& p, const point&a, const point&b, vector<
		point>& res) {
	res.clear();
	for (int i = 0; i < sz(p); i++) {
		int j = (i + 1) % sz(p);
		bool in1 = cross(vec(a,b),vec(a,p[i])) > EPS;
		bool in2 = cross(vec(a,b),vec(a,p[j])) > EPS;
		if (in1)
			res.push_back(p[i]);
		if (in1 ^ in2) {
			point r;
			intersect(a, b, p[i], p[j], r);
			res.push_back(r);
		}
	}
}

//assume that both are anti-clockwise
void convexPolygonIntersect(const vector<point>& p, const vector<point>& q,
		vector<point>& res) {
	res = q;
	for (int i = 0; i < sz(p); i++) {
		int j = (i + 1) % sz(p);
		vector<point> temp;
		polygonCut(res, p[i], p[j], temp);
		res = temp;
		if (res.empty())
			return;
	}
}

void voronoi(const vector<point> &pnts, const vector<point>& rect, vector<
		vector<point> > &res) {
	res.clear();
	for (int i = 0; i < sz(pnts); i++) {
		res.push_back(rect);
		for (int j = 0; j < sz(pnts); j++) {
			if (j == i)
				continue;
			point p = perp(vec(pnts[i],pnts[j]));
			point m = mid(pnts[i],pnts[j]);
			vector<point> temp;
			polygonCut(res.back(), m, m + p, temp);
			res.back() = temp;
		}
	}
}

STATE pointInPolygon(const vector<point>& p, const point &pnt) {
	point p2 = pnt + point(1, 0);
	int cnt = 0;
	for (int i = 0; i < sz(p); i++) {
		int j = (i + 1) % sz(p);
		if (pointOnSegment(p[i], p[j], pnt))
			return BOUNDRY;
		point r;
		if(!intersect(pnt, p2, p[i], p[j], r))
		        continue;
		if (!pointOnRay(pnt, p2, r))
			continue;
		if (same(r,p[i]) || same(r,p[j]))
			if (fabs(r.Y - min(p[i].Y, p[j].Y)) < EPS)
				continue;
		if (!pointOnSegment(p[i], p[j], r))
			continue;
		cnt++;
	}
	return cnt & 1 ? IN : OUT;
}

struct cmp {
	point about;
	cmp(point c) {
		about = c;
	}
	bool operator()(const point& p, const point& q) const {
		ld cr = cross(vec(about, p), vec(about, q));
		if (fabs(cr) < EPS)
			return make_pair(p.Y, p.X) < make_pair(q.Y, q.X);
		return cr > 0;
	}
};

void sortAntiClockWise(vector<point>& pnts) {
	point mn(1 / 0.0, 1 / 0.0);
	for (int i = 0; i < sz(pnts); i++)
		if (make_pair(pnts[i].Y, pnts[i].X) < make_pair(mn.Y, mn.X))
			mn = pnts[i];

	sort(all(pnts), cmp(mn));
}

void convexHull(vector<point> pnts, vector<point> &convex) {
	sortAntiClockWise(pnts);
	convex.clear();
	convex.push_back(pnts[0]);
	if (sz(pnts) == 1)
		return;
	convex.push_back(pnts[1]);
	if (sz(pnts) == 2) {
		if (same(pnts[0], pnts[1]))
			convex.pop_back();
		return;
	}
	for (int i = 2; i <= sz(pnts); i++) {
		point c = pnts[i % sz(pnts)];
		while (sz(convex) > 1) {
			point b = convex.back();
			point a = convex[sz(convex) - 2];
			if (cross(vec(b, a), vec(b, c)) < -EPS)
				break;
			convex.pop_back();
		}
		if (i < sz(pnts))
			convex.push_back(pnts[i]);
	}
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    int t; cin >> t; while(t--){


    }

}
