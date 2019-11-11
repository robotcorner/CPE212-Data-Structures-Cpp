# NOTES for LAB 9

## Help

### Email Note

I was working with a student and they managed to establish 10 arrays of 5 million entries each in global memory. This can make the merge task easier than presented in class. In particular, once you have 10 sorted files you can read the complete file into an array rather than reading the data one word at at time or one block at a time. from each file. You can then do a 10 way merge directly from the data stored in memory, which should make your program much faster. The merge code presented to you is a 2 way merge (two arrays of numbers are merged into 1) but should be extend and able to a 10 way merge. If you are having trouble with that solution then you can do a series of 2 way merges: 1 with 2, 1and2 with 3, 1and2and3 w6ith 4, etc. this will take longer and require careful memory management but the merge code presented in class is then almost directly applicable to your problem.

split -n10 data_in
// this creates 10 new files a1, a2, a3 each with 1/10th of the original file
// it does not delete the orginal file

### Create 10 files each about 5 million long

split original C files
end with new files
use the split command
USE THIS TO SPLIT FILES -n10 sort_revf.cpp

### Sort original file

sort original file to get the verification file. Use the command line sort to test your sorted version against.
time sort <original_file> verification_file

### Verifying you output file is correct

diff your_sorted_file verification_file, should report back no differences
diff xaa xad

### evaluate sorting algorithms

time your-algo using the time command line time program ...

- Algorithms that don't use a lot secondary storage
  - quicksort and bubble sort are in place sort
- compare results using a smaller segment of the dataset - compare using a data set of 10,100, 10,0000-100,000, 1000 commands is enough
- Merge sort needs space as big as the original file - merge sort, would need to change the way the code works in order for it to work on this file.

- Put it on the heap if you can't put on the stack (not enough space on the stack)
- Merge sort is currently allocated on the stack

- our quicksort is bad compared to the linux one

- bubble sort - start at the bottom always, then "bubble up" ,keep bringing up the smallest one. Can be very fast if the list is already in order - short bubble sort - checks if already sorted basically

- given other sorts that you can use, grab some code from the slides.

- read in the first file - call quicksort - write output to a different file output
for each file need to pass in the data into an array?

- algorithms
- time vs space

### merge the inidvidual file into a single firle one word at a time

1) read one value in from each file
2) find the smallest value
3) write the smallest value out to the output file
4) read a replacement value for one just used up
5) repeat until all files are empty

- notes not all files will empty at the same times.
- expect some files to be empty while others still have data.

Some streams may read faster, so read in, store them in a buffer, consume, then read next one
read one value from each file - choose smallest - write to output file / organize
read in multiple values instead though such as 1000-5000 items at once

- read in blocks of data at a time
- process those 4,000 numbers from the stream.

write 10 functions

- read stream 1 = reads 4000 bytes provides a value back
- run each function when you need it
- after inputing a bunch of items call a function that inputs those values, need to call functions a lot!
- readers are the methods 1-10
- he would do it differently , but would probably work

In algorithms can only pass in an array
For sorting operation need all the numbers in memorty, run 10 times if you need
The sort algorithms take whole arrays - sort all the data at once

merge program
