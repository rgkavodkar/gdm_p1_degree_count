/*
 * Utilities.h
 *
 *  Created on: 18-Sep-2014
 *      Author: rg_kavodkar
 */
#include <vector>
#ifndef UTILITIES_H_
#define UTILITIES_H_

using namespace std;

namespace mapreduce {

long get_no_of_edges(string filename);
long get_no_of_vertices(string filename);
//void mapper(long vertices[][2], Worker worker, long number_of_edges);
void reducer();
vector<string> tokenize(string str);
} /* namespace mapreduce */

#endif /* UTILITIES_H_ */
