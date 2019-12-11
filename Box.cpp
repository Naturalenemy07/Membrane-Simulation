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
#include "Bead.h"
//#include "Polymer.h"
#include "Box.h" // must be after #include “Bead.h”


void Box::move(uniform_real_distribution<double>& dist, mt19937_64& gen)
{
	for (int i = 0;i < beads.size();i++) {
		beads[i]->move(dist, gen); //need to use the -> operator when working with pointers, synonymous to the " . " operator
		if (check(i)) {
			acceptMove();
		}
		else {
			rejectMove(i);
		}
	}
}

bool Box::check(int index)
{
	double dx, dy, dz;
	for (int i = 0;i < beads.size();i++) {
		if (i != index) {
			if (beads[index]->getX() > x / 2.0) 
			{
				beads[index]->setPosition(beads[index]->getX() - x, beads[index]->getY(), beads[index]->getZ());
			}
			if (beads[index]->getY() > y / 2.0)
			{
				beads[index]->setPosition(beads[index]->getX(), beads[index]->getY() - y, beads[index]->getZ());
			}
			if (beads[index]->getZ() > z / 2.0) 
			{
				beads[index]->setPosition(beads[index]->getX(), beads[index]->getY(), beads[index]->getZ() - z);
			}
			if (beads[index]->getX() < -x / 2.0) 
			{
				beads[index]->setPosition(beads[index]->getX() + x, beads[index]->getY(), beads[index]->getZ());
			}
			if (beads[index]->getY() < -y / 2.0)
			{
				beads[index]->setPosition(beads[index]->getX(), beads[index]->getY() + y, beads[index]->getZ());
			}
			if (beads[index]->getZ() < -z / 2.0) 
			{
				beads[index]->setPosition(beads[index]->getX(), beads[index]->getY(), beads[index]->getZ() + z);
			} 
			dx = fabs(beads[i]->getX() - beads[index]->getX());
			dy = fabs(beads[i]->getY() - beads[index]->getY());
			dz = fabs(beads[i]->getZ() - beads[index]->getZ());
			if (dx > (x / 2.0)) {
				dx = fabs(dx - x);
			}
			if (dy > (y / 2.0)) {
				dy = fabs(dy - y);
			}
			if (dz > (z / 2.0)) {
				dz = fabs(dz - z);
			}
			if (sqrt(pow(dx, 2.0) + pow(dy, 2.0) + pow(dz, 2.0)) < (beads[i]->getDiameter() / 2.0 + beads[index]->getDiameter() / 2.0)) return false;
		}
	}
	return true;
}

//check function for the polymer, measuring the distance between beads and to prevent overlap between beads in the polymer

/*bool Box::check(int index)
{
	double dx, dy, dz;
	for (int i = 0;i < polymer.size();i++) {
		if (i != index) {
			if (distance(polymer[i], polymer[index]) < 1) { //can i use the distance function here?
				//reject
			}
			if (distance(polymer[i], polymer[index]) > 1.2) {
				// reject
			}
		}
	}

			//min distance between beads in a Polymer is 1
			//max distance between beads IN A polymer is 1.2
		
*/
void Box::acceptMove()
{
	// do nothing
}

void Box::rejectMove(int i)
{
	beads[i]->goBack();
}
