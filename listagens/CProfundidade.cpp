#include "CProfundidade.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

void CProfundidade :: EntradaDados (string nomearquivo)
{ 
  perfil.clear();
  ifstream fin;
  fin.open (nomearquivo.c_str());
  int i = 0 ;
  double tmp;
  cout << "Profundidade importada"<<endl;
  do {
     fin>>tmp;
     perfil.push_back(tmp);
     fin>>tmp; 
     fin>>tmp;    
     fin>>tmp;
     fin>>tmp;
     fin>>tmp;  
  } while(!fin.eof());
  Set_numPontos(perfil.size());
  Set_Maximo();
  Set_Minimo();
}
