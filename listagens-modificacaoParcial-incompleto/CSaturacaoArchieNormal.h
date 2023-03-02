#ifndef CSaturacaoArchieNormal_H
#define CSaturacaoArchieNormal_H
#include <vector>
#include "CResistividade.h"
#include "CPorosidade.h"


/* Esta classe recebe os atributos e os m�todos das classes CSaturacaoArchieNormal e CArgilosidade para calcular a satura��o de �leo e de �gua **/
using namespace std;

class CSaturacaoArchieNormal 
{
  protected:
    CPorosidade* porosidade;
    CResistividade* resistividade;
    double a, m, n, rw ;
    vector <double> so;
    vector <double> sw;
    
  public:
    CSaturacaoArchieNormal();         //Construtor Default
    CSaturacaoArchieNormal(CPorosidade* porosidade_ent ,CResistividade* resistividade_ent);
    ~CSaturacaoArchieNormal();	  //Destrutor Default
    void CalcularSaturacao();	//Este m�todo calcula a satura��o de �leo e �gua utilizando a lei de Archie Normal
    double Get_SO(int indice) {return so[indice];};
    vector <double> & Get_SO_Vector() {return so;};
    
};
#endif
    
  
