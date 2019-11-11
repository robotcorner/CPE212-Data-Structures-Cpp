
#include <sys/time.h>   // get some definitions
#include <unistd.h>     // get some more definitions
#include <iostream>
using namespace std;

//for more information check man gettimeofday

int main ()
{
  struct timeval start, end;
  int seconds, useconds;

  gettimeofday(&start, NULL); // get start time
  sleep(10);   // sleep 10 seconds
  gettimeofday(&end, NULL); // get end time
  
  seconds = end.tv_sec - start.tv_sec; // find elapsed time
  useconds = end.tv_usec  - start.tv_usec;
  cout << " total time was " << seconds << " seconds and " << useconds << "microseconds " <<endl;
}
