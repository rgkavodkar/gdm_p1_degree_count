=======================================================================================
Source Code:
=======================================================================================
The source code is contained in the folder named MapReduce
=======================================================================================

=======================================================================================
Makefile:
=======================================================================================
To build it normally, use 'make all'
To build it and to use the profiler, use 'make profile' (has the -pg option)
To clean it, use 'make clean'
=======================================================================================


=======================================================================================
Running the program
=======================================================================================
After building, run 'MapReduce' and pass it the location of the graph file. 
Eg. $ MapReduce /opt/graphs/amazon.graph
The computation will be done and the output will be written in a file to the same location as above with the output file name being 'amazon.graph.degrees'
Eg. /opt/graphs/amazon.graph.degrees
=======================================================================================