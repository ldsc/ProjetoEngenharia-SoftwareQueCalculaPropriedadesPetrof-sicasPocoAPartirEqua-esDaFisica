#ifndef CArgilosidade_H
#define CArgilosidade_H
#include <vector>
#include "CGamaRay.h"


//Esta classe guarda o valor da argilosidade calculada de acordo com a formula desejada, referente aos tr�s m�todos de c�lculo 


class CArgilosidade 
{
  protected:
    vector <double> argilosidade;
    CGamaRay* gamaray;
    
  public:
    CArgilosidade(){};        //Construtor Default
    CArgilosidade(CGamaRay* gamaray_ent);
    ~CArgilosidade(){};	    //Destrutor Default
    //Calcula a argilosidade usando os valores maximo e m�nimo de Raio Gama
    void FormaPratica();  
    //Calcula a argilosidade usando uma f�rmula espec�fica para rochas consolidadas
    void RochaConsolidada();  
    //Calcula a argilosidade usando uma f�rmula espec�fica para rochas n�o consolidadas
    void RochaNaoConsolidada();
    double Get_VSH(int indice){return argilosidade[indice];};
    vector <double> & Get_VSH_Vector() {return argilosidade;};
};
#endif 
