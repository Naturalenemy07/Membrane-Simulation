#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <random>
#include <assert.h>
#include <vector>
using namespace std;
#include "Read.h"
#include "Bead.h"
#include "Box.h"
//#include "Polymer.h"
#include "VTF.h"

int main() {
	mt19937_64 generator{};
	generator.seed(unsigned(time(NULL)));
	uniform_real_distribution<double> dis(0.0, 1.0);

	int number_of_steps;
	Box* box = new Box;
	Read read; 
	string start_file = "C:/Users/David Caruthers/source/repos/CBE579_Membrane Simulation/CBE579_Membrane Simulation/input.txt";
	read.setFileName(start_file);
	read.openFile();
	int number_of_beads;
	double diameter;
	vector<double> line;
	Bead* bead;
	number_of_steps = read.getInt();
	line = read.getLine();
	box->setDimensions(line[0], line[1], line[2]);
	number_of_beads = read.getInt();
	for (int i = 0; i < number_of_beads; i++) {
		diameter = read.getDouble();
		line = read.getLine();
		bead = new Bead;
		bead->setPosition(line[0], line[1], line[2]);
		bead->setDiameter(diameter);
		bead->setIndex(i);
		box->addBead(bead);
	}
	read.closeFile();

	//this code adds beads to a polymer, then when it finishes adding 10 beads to a polymer, it makes a new polymer and repeats
	//Polymer* polymer = new polymer;
	//loop polymer->addBead();

	/* For VTF / VMD output */
	VTFFile* vtf_file;
	string visualization_output_file = "C:/Users/David Caruthers/source/repos/CBE579_Membrane Simulation/CBE579_Membrane Simulation/output.vtf";
	vtf_file = new VTFFile();
	vtf_file->setFileName(visualization_output_file);
	vtf_file->setBoxAndBeads(box);
	vtf_file->writeHeader();
	vtf_file->writeBeadPositions();
	for (int i = 0;i < number_of_steps;i++) {
		box->move(dis, generator);
		vtf_file->writeBeadPositions();
	}
	delete vtf_file;

	return 0;
}