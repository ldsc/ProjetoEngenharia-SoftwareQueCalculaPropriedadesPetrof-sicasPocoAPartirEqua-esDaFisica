#ifndef CPorosidade_H
#define CPorosidade_H
#include <vector>
#include "CDensidade.h"
#include "CProfundidade.h"


//FI - porosidade
/* Esta classe calcula a porosidade através dos valores máximos e mínimos da densidade, utilizando para isso dados da classe CDensidade.**/
using namespace std;

class CPorosidade
{
  protected:
    CDensidade * densidade;
    CProfundidade* profundidade;
    vector <double> porosidade;
    double porosidadeMedia;
    
    
  public:
    CPorosidade() {};   		//Construtor Default
    CPorosidade(CDensidade* densidade_ent, CProfundidade* profundidade_ent);
    ~CPorosidade() {};		//Destrutor Default
    void CalcularPorosidade ();		//Calcula a porosidade
    double Get_FI(int indice) {return porosidade[indice];};
    vector <double> & Get_FI_Vector () {return porosidade;};
    void PorosidadeMedia (); 
    
};

#endif
