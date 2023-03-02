#include "CArgilosidade.h"
#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

CArgilosidade :: CArgilosidade(CGamaRay* gamaray_ent)
{
  gamaray = gamaray_ent;
}

void CArgilosidade :: FormaPratica ()
{ 
  argilosidade.clear();
  //loop para calcular a argilosidade em cada profundidade e preencher no vetor argilosidade
  for (int i= 0; i< gamaray->NumPontos() ; i++)
  { argilosidade.push_back((gamaray->Perfil(i) - gamaray->Get_Minimo())/(gamaray->Get_Maximo() - gamaray->Get_Minimo()));};
}


void CArgilosidade :: RochaConsolidada ()
{ 
  argilosidade.clear();
  //loop para calcular a argilosidade em cada profundidade e preencher no vetor argilosidade
  for (int i= 0; i< gamaray->NumPontos() ; i++)
  { argilosidade.push_back((gamaray->Perfil(i) - gamaray->Get_Minimo())/(gamaray->Get_Maximo() - gamaray->Get_Minimo()));
    argilosidade[i]=( 0.33 *((pow(2,2*argilosidade[i])) - 1));
  };
}


void CArgilosidade :: RochaNaoConsolidada ()
{
  argilosidade.clear();
  //loop para calcular a argilosidade em cada profundidade e preencher no vetor argilosidade
  for (int i= 0; i< gamaray->NumPontos() ; i++)
  { argilosidade.push_back((gamaray->Perfil(i) - gamaray->Get_Minimo())/(gamaray->Get_Maximo() - gamaray->Get_Minimo()));
    argilosidade[i]=(0.083 * pow(2,3.7*argilosidade[i])-0.083) ;
  };
}
