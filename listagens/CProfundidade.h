#ifndef CProfundidade_H
#define CProfundidade_H
#include "CPerfil.h"
#include <vector>
#include <string>

using namespace std; 

class CProfundidade : public CPerfil
{        
  public:
    CProfundidade() {};       //construtor default
    ~CProfundidade(){};      //destrutor default
    void EntradaDados(string nomearquivo);   
};

#endif
    
