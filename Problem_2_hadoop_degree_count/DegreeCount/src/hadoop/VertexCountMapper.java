package hadoop;

import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

class VertexCountMapper extends Mapper<LongWritable, Text, Text, IntWritable> {
	private final static IntWritable valueOne = new IntWritable(1);
	private Text vertex = new Text();

	public void map(LongWritable key, Text value, Context context)
			throws IOException, InterruptedException {
		String line = value.toString();
		StringTokenizer tokenizer = new StringTokenizer(line);
		while (tokenizer.hasMoreTokens()) {
			vertex.set(tokenizer.nextToken());
			context.write(vertex, valueOne);
		}
	}
}
