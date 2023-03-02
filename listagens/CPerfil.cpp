#include "CPerfil.h"
#include "CGamaRay.h"
#include "CResistividade.h"
#include "CDensidade.h"
#include "CProfundidade.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;


void  CPerfil :: Print_Dados ()
{

   cout << "Imprimindo o vetor na tela" << endl;
   for (int i=0; i< numPontos ; i++)
   {cout << i << "        " << perfil[i]<< endl;};
}

void CPerfil :: Set_Maximo()
{
    double temporaria = 0.0;
   for (int i =1 ; i < numPontos; i++)
   {
     if (perfil[i]>temporaria)
     { maximo=perfil[i];
       temporaria=maximo;};
     
   };
}

void CPerfil :: Set_Minimo()
{
  double temporaria = 1000.0;
  for (int i =1 ; i < numPontos; i++)
  {
    if (perfil[i]<temporaria)
    {minimo=perfil[i]; temporaria=minimo;};
  };
}
