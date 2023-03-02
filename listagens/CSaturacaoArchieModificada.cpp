#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "CSaturacaoArchieNormal.h"
#include "CSaturacaoArchieModificada.h"
#include "CArgilosidade.h"
#include "CPorosidade.h"


using namespace std;

CSaturacaoArchieModificada :: CSaturacaoArchieModificada()  { } 

CSaturacaoArchieModificada :: CSaturacaoArchieModificada(CPorosidade* porosidade_ent ,CResistividade* resistividade_ent,CArgilosidade* argilosidade_ent)  
{
  porosidade = porosidade_ent;
  resistividade = resistividade_ent;
  argilosidade = argilosidade_ent;
} 

CSaturacaoArchieModificada :: ~CSaturacaoArchieModificada() { }


void CSaturacaoArchieModificada:: CalcularSaturacao()
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
  cout << "Entre com a resistividade da argila Rsh =";
  cin >> rsh ;
  cout << endl;
  

  
  double erro = 0.00;
  double x = 0.0;
  double y = 0.0;
  double s = 0.1;
  double s_old = 0.1;

  for (int i = 0 ; i < resistividade->NumPontos() ; i ++) { 
    s = 0.1;
    do
    {
      s_old = s;
      y = 1.0/resistividade->Perfil(i);
      x = ((pow (porosidade->Get_FI(i),m) * pow (s_old,n))/(a*rw)); 
      s = (x - y)*argilosidade->Get_VSH(i)/rsh;
      erro = s - s_old;
      
    }while ((abs(erro)>0.001) and (s > 1.00));
    sw.push_back(s);
    so.push_back(1 -sw[i]);
    
  }
}
