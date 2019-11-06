#include <iostream>
#include <assert.h>
using namespace std;

class Bead {
public:
	void setPosition(double _x, double _y, double _z) {
		x = _x;
		y = _y;
		z = _z;
	}
private:
	double x, y, z;
};

int main() {
	Bead *bead1 = new Bead;
	bead1->setPosition(0.0, 0.0, 0.0);
	cout << bead1->getX() << " " << bead1->getY() << " " << bead1->getZ() << endl;
	
	Bead *bead2 = new Bead;
	bead2->setPosition(1.0, 0.0, 0.0);
	cout << bead2->getX() << " " << bead2->getY() << " " << bead1->getZ() << endl;

	return 0;
}

class Bead {
public:
	void setPosition(double _x, double _y, double _z) {
		assert(_x > -10.0 && _x < 10.0);
		assert(_y > -10.0 && _y < 10.0);
		assert(_z > -10.0 && _z < 10.0);
		x = _x;
		y = _y;
		z = _z;
	}
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
private:
	double x, y, z;
};
