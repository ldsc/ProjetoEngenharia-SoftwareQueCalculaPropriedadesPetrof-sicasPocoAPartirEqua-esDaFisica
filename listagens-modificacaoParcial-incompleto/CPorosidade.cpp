#include "CPorosidade.h"
#include "CPorosidade.h"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

CPorosidade :: CPorosidade(CDensidade* densidade_ent, CProfundidade* profundidade_ent)
{
  densidade = densidade_ent;
  profundidade = profundidade_ent;
}

void CPorosidade :: CalcularPorosidade ()
{ 
  porosidade.clear();
  for(int i=0; i< densidade->NumPontos(); i++)
  { 
    if (densidade->Get_Maximo() == densidade->Perfil(i))
      porosidade.push_back(0.05);
    else
    porosidade.push_back((densidade->Get_Maximo() - densidade->Perfil(i))/(densidade->Get_Maximo() - densidade->Get_Minimo()));
  };
 
}

void CPorosidade :: PorosidadeMedia ()
{
    double prof_inicial;
    double prof_final;   
    int j=0;
    int cont=0;   
    cout << "\nEntre com a profundidade inicial da area desejada : ";
    cin >> prof_inicial;
    cout << "\nEntre com o fim da profundidade da area desejada : ";
    cin >> prof_final;
    
    for (int i = 0; i < profundidade->NumPontos() ;i++)
    {
        if ((profundidade->Perfil(i)) > prof_inicial)
        { j=i; break; }
    } 
    
    porosidadeMedia = 0.0;
    do {       
        porosidadeMedia = porosidadeMedia + porosidade[j];
        prof_inicial = profundidade->Perfil(j); 
        j++;
        cont++;        
    } while (prof_inicial < prof_final);
    
    porosidadeMedia = porosidadeMedia/cont;
    cout << "A Porosidade media da area desejada e: "<< porosidadeMedia << endl;  
    
}


