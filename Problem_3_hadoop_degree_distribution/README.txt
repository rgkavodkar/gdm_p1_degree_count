=======================================================================================
Source Code:
=======================================================================================
The source code is contained in the folder named DegreeDistribution. It can be directly imported to Eclipse or any other IDE
=======================================================================================

=======================================================================================
JAR file:
=======================================================================================
The jar file DegreeDistribution.jar is included here. It is needed to run the program in Hadoop
=======================================================================================


=======================================================================================
Running the program
=======================================================================================
From your Hadoop_Home directory, run the below command to execute the program
bin/hadoop jar DegreeDistribution.jar degreedistribution.DegreeDistribution graph.file.path hdfs.output.dir
Eg. bin/hadoop jar DegreeDistribution.jar degreedistribution.DegreeDistribution /stanford/roadNet-PA.graph /output/roadNet-dd-pa
=======================================================================================