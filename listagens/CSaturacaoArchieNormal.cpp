#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "CSaturacaoArchieNormal.h"


using namespace std;

CSaturacaoArchieNormal :: CSaturacaoArchieNormal()  { } 

CSaturacaoArchieNormal:: CSaturacaoArchieNormal(CPorosidade* porosidade_ent ,CResistividade* resistividade_ent)
{
  porosidade = porosidade_ent;
  resistividade = resistividade_ent;
}

CSaturacaoArchieNormal :: ~CSaturacaoArchieNormal() { }
 
void CSaturacaoArchieNormal :: CalcularSaturacao()
{ 
  sw.clear();
  so.clear();
  
  cout << "Insira o coeficiente de tortuosidade a =";
  cin >> a;
  cout << endl;
  cout << "Insira o coeficiente de cimentacao m =" ;
  cin >> m;
  cout << endl;
  cout << "Insira o coeficiente de saturacao n = " ;
  cin >> n;
  cout << endl;
  cout << "Entre com o valor da resistividade da agua Rw =";
  cin >> rw;
  cout << endl;
  double s=0.0;
    for(int i=0; i < resistividade->NumPontos(); i++)
    { 
      sw.push_back(pow(((a*rw)/(resistividade->Perfil(i)*pow(porosidade->Get_FI(i),m))),(1.0/n))) ; 
      if (sw[i]>1.0)
	sw[i]=1.0;
      s=1.0-sw[i];
      so.push_back(s);
    } 
}
