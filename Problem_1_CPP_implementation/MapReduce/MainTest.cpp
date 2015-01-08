/*
 * MainTest.cpp
 *
 *  Created on: 18-Sep-2014
 *      Author: rg_kavodkar
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "Worker.h"
#include "Utilities.h"

using namespace mapreduce;
using namespace std;

int main(int argc, char* argv[]) {

	long threshold = 400000;
	string filename = argv[1];
		//	"/home/rg_kavodkar/Documents/GDM/Project_1/Graphs/youtube.graph.original";
		//	"/home/rg_kavodkar/Documents/GDM/Project 1/Graphs/amazon.graph.original";
		//	"/home/rg_kavodkar/Documents/GDM/Project 1/Graphs/my.graph.small";
	long edge_count = get_no_of_edges(filename);
	long vertex_count = get_no_of_vertices(filename);
	int number_of_workers = ceil((float) (edge_count / threshold)) + 1;

	ifstream file;
	file.open(filename.c_str());
	string line;

	Worker* workers[number_of_workers];
	for (int i = 0; i < number_of_workers; i++) {
		workers[i] = new Worker(threshold, edge_count);
	}
	int worker_id = 0;
	long line_count = 0;

	cout << "Reading vertices from the input file..." << endl;

	string word;
	long word_count = 0;
	while (file >> word) {
		word_count++;
		if (word_count < 3) {
			continue;
		}
		long vertex_1 = atoi(word.c_str());
		file >> word;
		long vertex_2 = atoi(word.c_str());
		line_count++;
		//File contains the line
		if (line_count % threshold == 0) {
			worker_id++;
		}
		workers[worker_id]->add_to_vertices(vertex_1, vertex_2);
	}

	file.close();
	cout << "Completed reading the input..." << endl;

	cout << "Performing mapping process for each worker..." << endl;
	for (int i = 0; i < number_of_workers; i++) {
		workers[i]->perform_mapping();
	}
	cout << "Completed mapping process for each worker..." << endl;

	cout << "Performing reduction process..." << endl;
	long* degrees = perform_reducing(workers, number_of_workers, vertex_count);
	cout << "Completed reduction process..." << endl;

	cout << "Writing the result of reduction process to a file..." << endl;
	//write the reduction to a file
	string output_filename = filename + ".degrees";
	ofstream outfile (output_filename.c_str());


	for (long i = 0; i < vertex_count; i++){
		outfile << i << " " << degrees[i] << endl;
	}
	outfile.close();
	cout << "Completed writing the result of reduction process to a file..." << endl;

	return 0;
}
