/*
 * Worker.cpp
 *
 *  Created on: 18-Sep-2014
 *      Author: rg_kavodkar
 */
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Worker.h"
#include "Utilities.h"

using namespace std;

namespace mapreduce {

Worker::Worker(long array_size, long edge_count) {
	if(array_size > edge_count) {
		array_size = edge_count;
	}
	size = array_size;
	vertices = new long*[size];
	v_degree = new long[edge_count];
	index = 0;
	for (long i = 0; i < size; i++) {
		vertices[i] = new long[2];
	}
}

Worker::~Worker() {
	// TODO Auto-generated destructor stub
}

void Worker::add_to_vertices(long vertex_1, long vertex_2) {
	vertices[index][0] = vertex_1;
	vertices[index][1] = vertex_2;
	index++;
}

void Worker::display() {
	for(long i = 0; i < index; i++) {
		cout << i << ". " <<  vertices[i][0] << ", " << vertices[i][1] << "\n";
	}
}

void Worker::enter_into_map(long vertex_id) {
	v_degree[vertex_id]++;
}

void Worker::perform_mapping() {
	for(long i = 0; i < index; i++) {
		enter_into_map(vertices[i][0]);
		enter_into_map(vertices[i][1]);
	}
}

long Worker::get_vertices_count() {
	return index;
}

long* Worker::get_vertices_degrees() {
	return v_degree;
}

long* perform_reducing(Worker **workers, int no_of_workers, long no_of_vertices) {

	long* vertex_degrees;
	vertex_degrees = new long[no_of_vertices];
	for(int i = 0; i < no_of_workers; i++) {
		long* map = workers[i]->get_vertices_degrees();

		for(long j = 0; j < no_of_vertices; j++) {
			vertex_degrees[j] += map[j];
		}
	}
	return vertex_degrees;
}

} /* namespace mapreduce */
