#ifndef CArgilosidade_H
#define CArgilosidade_H
#include <vector>
#include "CGamaRay.h"


//Esta classe guarda o valor da argilosidade calculada de acordo com a formula desejada, referente aos três métodos de cálculo 


class CArgilosidade 
{
  protected:
    vector <double> argilosidade;
    CGamaRay* gamaray;
    
  public:
    CArgilosidade(){};        //Construtor Default
    CArgilosidade(CGamaRay* gamaray_ent);
    ~CArgilosidade(){};	    //Destrutor Default
    //Calcula a argilosidade usando os valores maximo e mínimo de Raio Gama
    void FormaPratica();  
    //Calcula a argilosidade usando uma fórmula específica para rochas consolidadas
    void RochaConsolidada();  
    //Calcula a argilosidade usando uma fórmula específica para rochas não consolidadas
    void RochaNaoConsolidada();
    double Get_VSH(int indice){return argilosidade[indice];};
    vector <double> & Get_VSH_Vector() {return argilosidade;};
};
#endif 
