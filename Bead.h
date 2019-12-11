class Bead {
public:
	Bead() { } // Constructor
	~Bead() { } // Destructor
public:
	void setPosition(double _x, double _y, double _z) { 
		x = _x; 
		y = _y; 
		z = _z; 
	}
	void setDiameter(double d) { diameter = d; }
	void setIndex(int i) { index = i; }
public:
	void move(uniform_real_distribution<double>& real_dist, mt19937_64& gen) {
		x_old = x;
		y_old = y;
		z_old = z;
		x = x + (real_dist(gen) - 0.5);
		y = y + (real_dist(gen) - 0.5);
		z = z + (real_dist(gen) - 0.5);
	}
	void goBack() {
		x = x_old;
		y = y_old;
		z = z_old;
	}
public:
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
	double getDiameter() { return diameter; }
private:
	double x, y, z;
	double x_old, y_old, z_old;
	double diameter;
	int index;
};
