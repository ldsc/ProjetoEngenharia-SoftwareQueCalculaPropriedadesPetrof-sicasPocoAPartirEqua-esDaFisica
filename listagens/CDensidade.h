#ifndef CDensidade_H
#define CDensidade_H
#include "CPerfil.h"
#include <vector>
#include <iostream>
#include <string>

// ro = densidade

using namespace std;

class CDensidade : public CPerfil
{
  public:
    CDensidade() {};       //construtor default
    ~CDensidade(){};      //destrutor default
    void EntradaDados(string nomearquivo);
};
#endif
