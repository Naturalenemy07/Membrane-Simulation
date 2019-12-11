#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <time.h>
#include <vector>
#include <math.h>
#include <assert.h>
#include <random>
using namespace std;
#include "Bead.h"
#include "Box.h"
//#include "Polymer.h"
#include "VTF.h"

void VTFFile::writeHeader()
{
	stream = fopen(filename.c_str(), "w");
	assert(stream);
	fprintf(stream, "unitcell %lf %lf %lf\n", box->getX(), box->getY(), box->getZ());
	fprintf(stream, "atom %d:%d\tradius %lf segid 0\n", 0, beads.size()-1, beads[0]->getDiameter()/2.0);
}

void VTFFile::writeBeadPositions()
{    
	fprintf(stream, "\ntimestep\n");
	fprintf(stream, "unitcell %lf %lf %lf\n", box->getX(), box->getY(), box->getZ());
	for (int i=0;i<beads.size();i++) {
		fprintf(stream, "%lf\t %lf\t %lf\n", beads[i]->getX(), beads[i]->getY(), beads[i]->getZ());
	}
}

VTFFile::~VTFFile()
{
	fclose(stream);
}