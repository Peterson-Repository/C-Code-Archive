#include <iostream>
#include <dirent.h>
#include <fstream>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdio.h>


using namespace std;

int main(){
  struct timeval t;
  
  gettimeofday(&t, NULL);

  long time;

  cout << endl;
  cout <<"sec: " << t.tv_sec <<endl;
  cout <<"mil sec: " << t.tv_usec <<endl;

  time = (t.tv_sec *1000000) + t.tv_usec;

  cout << endl;
  cout <<"total: " << time << "           " <<endl;
  cout << endl;

}


