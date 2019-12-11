class VTFFile {
public:
	VTFFile() { }
	~VTFFile();
public:
	void setFileName(string fn) { filename = fn; }
	void setBoxAndBeads(Box* _box) { box = _box; beads = box->getBeads(); }
public:
	void writeHeader();
	void writeBeadPositions();
private:
	vector<Bead*> beads;
	Box* box;
	FILE* stream;
	string filename;
};
