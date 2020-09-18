/*
    HW4a - Vec3d
    Author: Joseph Kuhn
    Cite: Worked with John Brescia
    Cite: Received help from Graduate Support Center
    I pledge my honor that I have abided by the Stevens Honor System.
*/

#include <iostream>
#include <math.h>
using namespace std;

class Vec3d {

private:
    double x, y, z;
public:
    Vec3d() : Vec3d(0, 0, 0) {}
    Vec3d(double x) : Vec3d(x, 0, 0) {}
    Vec3d(double x, double y) : Vec3d(x, y, 0) {}
    Vec3d(double x, double y, double z) : x(x), y(y), z(z) {}

    double getX() const;

    double setX() const;

	double getY() const;

	double setY() const;

	double getZ() const;

	double setZ() const;

    Vec3d operator +(Vec3d r) const {
        return Vec3d(x + r.x, y + r.y, z + r.z);
    }

    friend Vec3d operator -(Vec3d a, Vec3d b) {
        return Vec3d(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    friend Vec3d operator -(Vec3d r) {
        return Vec3d(-r.x, -r.y, -r.z);
    }

    double dot(Vec3d a) const {
        return a.x * x + a.y * y + a.z + z;
    }

    double mag() const {
        return sqrt(x * x + y * y + z * z);
    }

    double magSq() const {
        return x * x + y * y + z * z;
    }

    double dist(Vec3d a) const {
        return sqrt(((x - a.x) * (x - a.x)) + ((y - a.y) * (y - a.y)) + ((z - a.z) * (z - a.z)));
    }

    friend ostream& operator <<(ostream& s, Vec3d V);

};

double dot (Vec3d a, Vec3d b) {
    return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
}


ostream& operator <<(ostream& s, Vec3d V) {
    s << "(" << V.x << ", " << V.y << ", " << V.z << ")";
    return s;
}

double Vec3d::getX() const {
    return x;
}

/*void Vec3d::setX(double x) {
    Vec3d::x = x;
}*/

double Vec3d::getY() const {
    return y;
}

/*void Vec3d::setY(double y) {
    Vec3d::y = y;
}*/

double Vec3d::getZ() const {
    return z;
}

/*void Vec3d::setZ(double z) {
    Vec3d::z = z;
}*/

int main() {
	// use friend operators
	const Vec3d a(1.0,2.5,3.5); // double precision!
	const Vec3d b(2.0);         //(2,0,0)
	const Vec3d c(2.0,3.5);     //(2,3.5,0)
	const Vec3d e;              //(0,0,0)

	const Vec3d f = a + e;
	const Vec3d g = b - c; // d is not an object, pick a different one
	double x = dot(f, g); // regular function  f.x*g.x + f.y*g.y + f.z*g.z
	//	double y = Vec3d::dot(f,g); // static function
	double z = f.dot(g); // method
	const Vec3d h = -b;

	double dist = f.mag(); // square root of sum of square
	double dist2 = f.magSq(); // sum of square
	double dist3 = f.dist(g); // sqrt or sum of square of diff
	//dx = f.x-g.x  dy = f.y - g.y      dx*dx + dy*dy...
	cout << a << '\n';
	cout << b << '\n';
	cout << c << '\n';
	cout << e << '\n';
	cout << f << '\n';
	cout << g << '\n';
	cout << h << '\n';
	cout << dist << '\n';
	cout << dist2 << '\n';
	cout << dist2 << '\n';
}