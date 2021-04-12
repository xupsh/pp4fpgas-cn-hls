#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <complex>
#include <complex.h>
#include "fm.h"
//#include "fm.cpp"

using namespace std;

int main () {
  
  float samplesr[SIZE];
  float samplesi[SIZE];
  float z_out[SIZE/50];

  ifstream file("complex.txt");
  string line;
  double s1;
  double s2;
  int i=0;
  while(getline(file,line) && (i < SIZE))
  {
    istringstream sin(line);
    sin >> s1 >> s2;
    samplesr[i] = (double)s1;
    samplesi[i] = (double)s2;
    i = i + 1;
  }

  mono_FM_impl(samplesr, samplesi, SIZE, z_out);
  
  for (int i=0; i<SIZE/50;i++)
  {
    printf("%f",z_out[i]);
    cout << "\n";
  }

  return 0;
}

