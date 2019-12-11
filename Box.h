class Box {
public:
	void setBeads(vector <Bead*> b) {
		beads = b;
	}
	void addBead(Bead* b) {
		beads.push_back(b);
	}
	void setDimensions(double _x, double _y, double _z) {
		x = _x;
		y = _y;
		z = _z;
	}
public: 
	void move(uniform_real_distribution<double>&, mt19937_64&);
private:
	bool check(int);
	void acceptMove();
	void rejectMove(int); //why is there an int?
public:
	vector<Bead*> getBeads() { return beads; }
	double getX() { return x; }
	double getY() { return y; }
	double getZ() { return z; }
private:
	vector<Bead*> beads; // not sure what these do or why they are at the end of the file
	double x, y, z;
};