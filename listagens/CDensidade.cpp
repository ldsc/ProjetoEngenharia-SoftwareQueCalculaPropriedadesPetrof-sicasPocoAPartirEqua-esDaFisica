#include "CDensidade.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// #include <cmath>


using namespace std;

void CDensidade::EntradaDados(string nomearquivo)
{ perfil.clear();
  ifstream fin;
  fin.open (nomearquivo.c_str());
  int i = 0 ;
  double tmp;
  cout << "Densidade importada"<<endl;
  do
  {  if (fin.eof()) break;
     else 
     {fin>>tmp;
     fin>>tmp; 
     fin>>tmp;    
     fin>>tmp;
     fin>>tmp;
     fin>>tmp;
     perfil.push_back(tmp);
     i++;};  
  }while(!fin.eof()) ;
  Set_numPontos(i);
  Set_Maximo();
  Set_Minimo();
}
