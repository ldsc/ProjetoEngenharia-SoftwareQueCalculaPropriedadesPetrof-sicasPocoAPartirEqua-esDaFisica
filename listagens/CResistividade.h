#ifndef CResistividade_H
#define CResistividade_H
#include "CPerfil.h"
#include <vector>
#include <string>

//rt = resistividade total ; rw = resistividade da água (dado imput)
/* Esta classe representa os valores das medidas do perfil de resistividade**/

using namespace std; 

class CResistividade : public CPerfil
{    
  public:
    CResistividade() {};       //construtor default
    ~CResistividade() {};      //destrutor default
    void EntradaDados (string nomearquivo);
};

#endif
    
  
