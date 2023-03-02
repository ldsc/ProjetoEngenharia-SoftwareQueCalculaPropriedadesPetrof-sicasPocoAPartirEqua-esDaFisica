#ifndef CGamaRay_H
#define CGamaRay_H
#include "CPerfil.h"
#include <vector>
#include <iostream>
#include <string>

/* Esta classe representa os valores das medidas do perfil de raio gama **/

using namespace std;

class CGamaRay : public CPerfil
{
  public:
    CGamaRay() {};       //construtor default
    ~CGamaRay() {};      //destrutor default
    void EntradaDados(string nomearquivo);
};

#endif  
