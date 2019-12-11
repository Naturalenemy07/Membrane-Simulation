class Read {
public:
	Read() { }
	void setFileName(string name) { filename = name; }
	void openFile();
	vector<double> getLine();
	double getDouble();
	int getInt();
	void skipLine();
	void closeFile();
private:
	string filename;
	FILE* stream;
};

