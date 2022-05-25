//===================================
//    Shayan Dodge
//    MSc in Physics
// M: +98 935 741 67 63
// E: dodgeshayan@gmail.com
// A: Tehran, Iran
//===================================
// The explicit solve of the wave equation
// (u^2(d^2Q/dx^2)=(d^2Q/dt^2))
// where u is the speed of the wave
//%===================================
#include<iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
  float u;
  float x_0;
  float x_n;
  float t_0;
  float t_n;
  float dx;
  float r;
  float dt;
  int m;
  int n;
  float border_1;
  float border_2;
  float initial;

  std::cout << "u=";
  std::cin >> u;
  std::cout << "x_0=";
  std::cin >> x_0;
  std::cout << "x_n=";
  std::cin >> x_n;
  std::cout << "t_0=";
  std::cin >> t_0;
  std::cout << "t_n=";
  std::cin >> t_n;
  std::cout << "dx=";
  std::cin >> dx;
  std::cout << "dt=";
  std::cin >> dt;
  std::cout << "Q(x=0)=";
  std::cin >> border_1;
  std::cout << "Q(x=x_n)=";
  std::cin >> border_2;
  r=pow(u*dt/dx,2);
  if (r>1&&r<0) {
    std::cout <<  "You're program is ustable"<<"\n";
  } else {
  m=((x_n-x_0)/dx);
  n=((t_n-t_0)/dt);
  float x[m+1];
  float Q[m+1][n+1];
  x[0]={x_0};
  x[m]={x_n};
  for (int i = 0; i < m+1; i++) {
    x[i+1]=x[i]+dx;
  }
  for (int j = 0; j < n+1; j++) {
    Q[0][j]=border_1;
    Q[m][j]=border_2;
  }
  for (int i = 0; i < m; i++) {
    Q[i][0]=sin(M_PI*x[i]);
  }


// Main function
  for (int i = 1; i < m; i++) {
    Q[i][1]=(Q[i+1][0]+Q[i-1][0])/2;
  }

  for (int j = 1; j < n; j++) {
for (int i = 1; i < m; i++) {
  Q[i][j+1]=Q[i+1][j]+Q[i-1][j]-Q[i][j-1];
}  }

// Display results
for (int j = 0; j < n+1; j++) {
  for (int i = 0; i < m+1; i++) {
    cout.width(10); cout <<left<<Q[i][j]<<'\t';
  }
  std::cout << '\n';
}
}
  return 0;
}
