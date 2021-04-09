#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <complex>
#include <complex.h>
#include "fm.h"

using namespace std;

int main () {
  
  __complex__ double samples[2400000];
  __complex__ double z_out[2400000/50];
  ifstream file("complex.txt");
  string line;
  double s1;
  double s2;
  int i=0;
  while(getline(file,line))
  {
    istringstream sin(line);
    sin >> s1 >> s2;
    __real__ samples[i] = (double)s1;
    __imag__ samples[i] = (double)s2;
  }
  mono_FM_impl(samples, 2400000, z_out);
  for (int i=0; i<2400000;i++)
  {
    cout << z_out[i];
  }

}

