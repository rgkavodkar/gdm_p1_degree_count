=======================================================================================
Source Code:
=======================================================================================
The source code is contained in the folder named DegreeCount. It can be directly imported to Eclipse or any other IDE
=======================================================================================

=======================================================================================
JAR file:
=======================================================================================
The jar file VertexCount.jar is included here. It is needed to run the program in Hadoop
=======================================================================================


=======================================================================================
Running the program
=======================================================================================
From your Hadoop_Home directory, run the below command to execute the program
bin/hadoop jar VertexCount.jar hadoop.VertexCount graph.file.path hdfs.output.dir
Eg. bin/hadoop jar VertexCount.jar hadoop.VertexCount /stanford/roadNet-PA.graph /output/roadNet-vc-pa
=======================================================================================