
#include <sys/time.h>   // get some definitions
#include <unistd.h>     // get some more definitions
#include <iostream>
using namespace std;
//
//for more information check man gettimeofday
//
int main ()
{
 struct timeval start, end;
int seconds, useconds;
// get start time
//
gettimeofday(&start,NULL);
// sleep for 10 seconds
//
 sleep(10);   // sleep 10 seconds
// get end time
//
gettimeofday(&end,NULL);
// find elapsed time
//
seconds = end.tv_sec - start.tv_sec;
useconds = end.tv_usec  - start.tv_usec;
cout << " total time was " << seconds << " seconds and " << useconds << "microseconds " <<endl;
}