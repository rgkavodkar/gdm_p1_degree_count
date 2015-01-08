package degreedistribution;

import java.io.IOException;
import java.net.URI;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.input.TextInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.mapreduce.lib.output.TextOutputFormat;

public class DegreeDistribution {
	public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
		
		String intermediateResultStoragePath = "tempStorage";
		Configuration conf = new Configuration();
		Job job = new Job(conf, "vertexcount");

		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(IntWritable.class);

		job.setMapperClass(DegreeCountMapper.class);
		job.setReducerClass(DegreeCountReducer.class);

		job.setInputFormatClass(TextInputFormat.class);
		job.setOutputFormatClass(TextOutputFormat.class);
		
		FileInputFormat.addInputPath(job, new Path(args[0]));
		FileOutputFormat.setOutputPath(job, new Path(intermediateResultStoragePath));
		
		job.setJarByClass(DegreeDistribution.class);
		job.waitForCompletion(true);
		
		conf = new Configuration();
		Job job_2 = new Job(conf, "degreedistribution");

		job_2.setOutputKeyClass(Text.class);
		job_2.setOutputValueClass(IntWritable.class);

		job_2.setMapperClass(DegreeDistributionMapper.class);
		job_2.setReducerClass(DegreeDistributionReducer.class);

		job_2.setInputFormatClass(TextInputFormat.class);
		job_2.setOutputFormatClass(TextOutputFormat.class);
		
		FileInputFormat.addInputPath(job_2, new Path(intermediateResultStoragePath));
		FileOutputFormat.setOutputPath(job_2, new Path(args[1]));
		
		job_2.setJarByClass(DegreeDistribution.class);
		job_2.waitForCompletion(true);
		
		FileSystem fs = FileSystem.get(URI.create(intermediateResultStoragePath), conf);
		fs.deleteOnExit(new Path(intermediateResultStoragePath));
		

	}
}
