#ifndef CPerfil_H
#define CPerfil_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Esta classe serve para armazenar os valores das profundidades e dos perfis de GamaRay, Resistividad e Densidade.

class CPerfil

{ 

protected:
    int numPontos;
    vector <double> perfil;
    double maximo;
    double minimo;

  
public:
   
     CPerfil() {};   		//Construtor Default
     ~CPerfil() {};	        //Destrutor Default
          
     void Print_Dados();
     int NumPontos () {return numPontos;};
     void Set_numPontos (int _i) {numPontos=_i;};
     vector <double> & Get_perfil_vector() {return perfil;};
     double Perfil (int indice) {return perfil[indice];};
     
     double Get_Minimo() {return minimo;};
     double Get_Maximo() {return maximo;};
     void Set_Minimo();
     void Set_Maximo();


};

#endif
