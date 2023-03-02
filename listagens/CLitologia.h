#ifndef CLitologia_H
#define CLitologia_H
#include <vector>
#include "CGamaRay.h"
#include "CProfundidade.h"


/* Esta classe plota o grafico de GamaRay especificando onde está cada litologia **/


class CLitologia
{
  protected:
    CGamaRay* gamaray;
    CProfundidade* profundidade;
    vector <double> litoArenito;
    vector <double> litoFolhelho;
    vector <double> profArenito;
    vector <double> profFolhelho;
    
  public:
    CLitologia(){};        //Construtor Default
    CLitologia(CGamaRay* gamaray_ent, CProfundidade* profundidade_ent);
    ~CLitologia(){};	 //Destrutor Default
    void IdentificarLitologias();
    double Get_Arenito(int indice) {return litoArenito[indice];};
    vector <double> & Get_Arenito_vector () {return litoArenito;};
    double Get_Folhelho(int indice) {return litoFolhelho[indice];};
    vector <double> & Get_Folhelho_vector () {return litoFolhelho;};
    double Get_ProfArenito(int indice) {return profArenito[indice];};
    vector <double> & Get_ProfArenito_vector () {return profArenito;};
    double Get_ProfFolhelho(int indice) {return profFolhelho[indice];};
    vector <double> & Get_ProfFolhelho_vector () {return profFolhelho;};
    
};
#endif
