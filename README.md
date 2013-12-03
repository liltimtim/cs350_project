<h1>CSCE 350 Project</h1>
<p>
Facial Expression Recognision<Br/>
Authors: Richard Abercrombie, Tim Barrett
</p>
<h2>Notes</h2>

<p>Currently the program runs the similarity calculations for all queries on appropriate templates and prints out the similarity value to the terminal.</p>

<h4>Compiling and running</h4>
<p>To compile and run the program from scratch:</p>

<pre>
make
./FacialRecognition
</pre>

<p>To recompile:</p>

<pre>
#Method 1
make clean
make
./FacialRecognition

#Method 2
./run.sh
</pre>



<h2>To Do</h2>
<ul>
	<li>
		Instead of printing similarity values out to the terminal, each query should have a vector (or map) and the similarity values and the related template line numbers should be pushed to that vector (or map)
	</li>

	<li>
		Output the top 10 similarity values for each query to a file
		<ul>
			<li>
				Sort each queries results vector and send the top ten to DoStuff::write_distances().  Write distances will have to get the following information from the template class:  Query name, Results vector/map (containing both the similarity values and their matching template line numbers)
			</li>
			<li>
				Sample output of AU###_results.txt <br>
<pre>
Similarity value 	Index (line number)
3.125 			2
1.245 			6
(to 10 values) 		..
</pre>

			</li>
		</ul>
	</li>
</ul>

