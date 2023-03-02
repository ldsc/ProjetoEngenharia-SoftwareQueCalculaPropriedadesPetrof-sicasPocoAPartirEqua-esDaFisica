#ifndef CSaturacaoArchieModificada_H
#define CSaturacaoArchieModificada_H
#include <vector>
#include "CSaturacaoArchieNormal.h"
#include "CArgilosidade.h"


/* Esta classe recebe os atributos e os métodos das classes CSaturacaoArchieNormal e CArgilosidade para calcular a saturação de óleo e de água **/
using namespace std;

class CSaturacaoArchieModificada : public CSaturacaoArchieNormal
{
  protected:
    CArgilosidade* argilosidade;
    double rsh;
    
  public:
    CSaturacaoArchieModificada();         //Construtor Default
    CSaturacaoArchieModificada(CPorosidade* porosidade_ent ,CResistividade* resistividade_ent,CArgilosidade* argilosidade_ent);
    ~CSaturacaoArchieModificada();	  //Destrutor Default
    void CalcularSaturacao();
     
    
};
#endif
    
