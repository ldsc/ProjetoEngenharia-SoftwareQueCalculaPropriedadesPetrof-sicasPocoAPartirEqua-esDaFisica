#include "CGamaRay.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>


using namespace std;

void CGamaRay :: EntradaDados (string nomearquivo)
{ perfil.clear();
  ifstream fin;
  fin.open (nomearquivo.c_str());
  int i = 0 ;
  double tmp;
  cout << "Gama Ray importado"<<endl;
  do
  {  
    if (fin.eof()) break;
     else 
     {
       fin>>tmp;
       fin>>tmp; 
       perfil.push_back(tmp);
       fin>>tmp;
       fin>>tmp;
       fin>>tmp;
       fin>>tmp;
       i++;}; 
       
  }while(!fin.eof()) ;
  
  Set_numPontos(i);
  Set_Maximo();
  Set_Minimo();
}
