#include<cmath>
#include<iostream> 
#include<fstream>
#include <vector>
using namespace std;

ofstream fout("tabelle.txt");

static int I_j = 20; //Seed
double u_i;
string d1;

double zufall(int a, int c ,int m){

  I_j = (a * I_j + c) % m;
  
  return u_i=1.0*(I_j)/m;

}

void schreiben(int a, int c, int m, int N) {

  int N_in=0;

  for(int n=1; n<(N-1); ++n){
    
    
    double x = zufall(a,c,m)*2-1;
    double y = zufall(a,c,m)*2-1;
    if(sqrt(pow(x,2)+pow(y,2) <= 1)) {

      N_in++;
       
    }
  } 
  
  double pi = 4.0* N_in / N;
  double p = 3.14159/4;
  double E = p*N;
  double V = E*(1-p);
  double sigma = 4*sqrt(V)/N;

  if(a==5) { d1="          ";}
  else { d1="";}

  fout << "a=" << a << " c=" << c << " m=" << m << d1 <<" || "<< N <<" | "<< E <<" | "<< V <<" || "<< N_in <<"   | "<< pi <<" | "<< sigma << endl;;
}

int main() {

  fout << "Einstellung            ||" << " N  " << " | E[N_in] " << "| V[N_in] " << "|| N_in " << "| pi   " << "| sigma_pi" << endl;

  for(int i=2; i<7; ++i) {
    if(i!=3) {
      schreiben(5,3,16,pow(10,i));
      schreiben(205,29573,139968,pow(10,i));
    }
  }

  fout.close();
}
