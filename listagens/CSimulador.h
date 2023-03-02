#ifndef CSimulador_H
#define CSimulador_H

#include "CDensidade.h"
#include "CGamaRay.h"
#include "CProfundidade.h"
#include "CResistividade.h"
  
#include "CArgilosidade.h"
#include "CLitologia.h"
#include "CSaturacaoArchieModificada.h"
#include "CSaturacaoArchieNormal.h"
#include "CPorosidade.h"

#include "CGnuplot.h"

using namespace std;

class CSimulador
{
  
protected:
  CGnuplot plotArgilosidade;
  CGnuplot plotSaturacao;
  CGnuplot plotPorosidade;
  CGnuplot plotDensidade;
  CGnuplot plotGamaRay;
  CGnuplot plotLitologia;
  CGnuplot plotResistividade;
  
  
  CDensidade densidade;
  CGamaRay gamaray;
  CProfundidade profundidade;
  CResistividade resistividade;
  
  CArgilosidade argilosidade;
  CLitologia litologia;
  CSaturacaoArchieModificada modificada;
  CSaturacaoArchieNormal normal;
  CPorosidade porosidade;
  
  string nomearquivo;
  
public:
  CSimulador();
  ~CSimulador() { };
  int Run();
  void Opcao_argilosidade();
  void Opcao_porosidade();
  void Opcao_saturacao();
  void Opcao_litologia();
  void Opcao_perfis();
  void PlotSolutionArgilosidade(vector<double> &datax, vector<double> &datay, string dados, string titulo);
  void PlotSolutionLitologia(vector<double> &datax, vector<double> &datay, string dados, string titulo);
  void PlotSolutionSaturacao(vector<double> &datax, vector<double> &datay, string dados, string titulo);
  void PlotSolutionPorosidade(vector<double> &datax, vector<double> &datay, string dados, string titulo);
  void PlotSolutionGamaRay(vector<double> &datax, vector<double> &datay, string dados, string titulo);
  void PlotSolutionResistividade(vector<double> &datax, vector<double> &datay, string dados, string titulo);
  void PlotSolutionDensidade(vector<double> &datax, vector<double> &datay, string dados, string titulo);
  //void Config_Plot(string dados, CGnuplot plot);
};

#endif
