---------------------------------------------------------------------------
			ReadMe file for Assignment 1;
			By: Kassim Izuagbe; 100129353;
---------------------------------------------------------------------------

The code extracts the data from a <file> into a 1-dimensional vector/array, 'data'. The file must be in the same folder as the code (or you can indicate the path of the file. i.e path/to/file.txt). The code currently opens and extracts data from a file called 'tester.txt', which is included in the zipped folder. 

In a while loop, parts of the data is copied into another 1-D vector/array, 'iter'. The parts copied are the sets of polyline points; one set at a time.

'pointer' in the code stores the index of the number of pionts in the current polyline set. 'data[pointer]' should always point to the number of points in a polyline set.