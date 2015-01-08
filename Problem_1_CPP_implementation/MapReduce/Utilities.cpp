/*
 * Utilities.cpp
 *
 *  Created on: 18-Sep-2014
 *      Author: rg_kavodkar
 */
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<cstdlib>
#include "Utilities.h"
#include "Worker.h"

using namespace std;

namespace mapreduce {
long get_no_of_edges(string filename) {
	long no_of_edges = 0;
	string first_line;
	ifstream file(filename.c_str());

	if (file.good()) {
		getline(file, first_line);
		vector<string> tokens = tokenize(first_line);
		no_of_edges = atoi(tokens.back().c_str());
	}

	file.close();
	return no_of_edges;
}

long get_no_of_vertices(string filename) {
	long no_of_vertices = 0;
	string first_line;
	ifstream file(filename.c_str());

	if (file.good()) {
		getline(file, first_line);
		vector<string> tokens = tokenize(first_line);
		no_of_vertices = atoi(tokens.front().c_str());
	}

	file.close();
	return no_of_vertices;
}


void mapper(Worker &worker) {

}

void reducer() {

}

vector<string> tokenize(string str) {
	string buf; // Have a buffer string
	stringstream ss(str); // Insert the string into a stream

	vector<string> tokens; // Create vector to hold our words
	while (ss >> buf) {
		tokens.push_back(buf);
	}
	return tokens;
}
}
