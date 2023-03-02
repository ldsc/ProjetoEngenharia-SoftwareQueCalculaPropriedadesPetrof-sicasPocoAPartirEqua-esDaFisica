#include "CSimulador.h"

CSimulador :: CSimulador() {
  
   porosidade = CPorosidade (&densidade, &profundidade);
   argilosidade = CArgilosidade(&gamaray);
   litologia = CLitologia (&gamaray , &profundidade);
   normal = CSaturacaoArchieNormal (&porosidade,&resistividade);
   modificada = CSaturacaoArchieModificada (&porosidade,&resistividade,&argilosidade);
   
   
}

int CSimulador :: Run ()
{
    cout<<" ========================================================================================================" <<endl;
    cout<<"                               Universidade Estadual do Norte Fluminense "<<endl;
    cout<<"      Simulador Para Estimativa de Propriedades Petrofisicas a partir de Perfis Geofisicos de Pocos"<<endl;
    cout<<"                                               ERICA MELLO LISBOA"<<endl;
    cout<<"                                             POLLYANA FERREIRA DA SILVA "<<endl;
    cout<<" ========================================================================================================" <<endl;
    
    
   char opcao;
   
   
   cout << "Entre com o nome do arquivo : "<< endl;
   cin >> nomearquivo;
   nomearquivo = nomearquivo + ".dat";
   densidade.EntradaDados(nomearquivo);
   profundidade.EntradaDados(nomearquivo);
   gamaray.EntradaDados(nomearquivo);
   resistividade.EntradaDados(nomearquivo);
 // o loop só parará quando uma das opcoes for correta.
  do{
    do {
    cout << "Entre com a opcao desejada" << endl; 
    cout << "1 - Argilosidade" << endl;
    cout << "2 - Porosidade" << endl;
    cout << "3 - Saturacao" << endl;
    cout << "4 - Ver litologia" << endl;
    cout << "5 - Plotar perfis" << endl;
    cout << "0 - Quit" << endl;
    cin >> opcao;
    
  if ((opcao != '1') && (opcao != '2') && (opcao !='3') && (opcao !='4') && (opcao !='5') && (opcao !='0')) 
  { cout<< "Opcao invalida!"<< endl;};
  
  
  }while ((opcao != '1') && (opcao != '2') && (opcao !='3') && (opcao !='4') && (opcao !='5') && (opcao !='0') );

 
  // quando a opção inserida for a correta ocorrerá uma das seguintes opções
  switch (opcao)
  {
    case '1':  Opcao_argilosidade(); 
      break;
    
    case '2':  Opcao_porosidade();
      break;
      
    case '3':  Opcao_saturacao();
      break;
      
    case'4':   Opcao_litologia();
      break;
      
    case '5':  Opcao_perfis();
      break;
      
    case '0': return 0;
      };
  }while ((opcao !='0')) ;  
      
}

void CSimulador :: Opcao_argilosidade()
{
  char opcao;
  do{
  cout << "Para calculo da argilosidade entre com o tipo de rocha" << endl;
  cout << "1 - Para Rocha Consolidada" << endl;
  cout << "2 - Para Rocha Nao Consolidada" << endl;
  cout << "3 - Formula que Nao considera o grau de consolidacao" << endl;
  cin >> opcao;
  if ((opcao != '1') && (opcao != '2') && (opcao !='3')) 
  { cout<< "Opcao invalida!"<< endl;
    opcao='4';
  }
  else {opcao=opcao;};
  
  }while (opcao=='4' );
  
  
  // quando a opção inserida for a correta ocorrerá uma das seguintes opções
  switch (opcao)
  {
    case '1': argilosidade.RochaConsolidada();
      break;
    case '2': argilosidade.RochaNaoConsolidada();
      break;
    case '3': argilosidade.FormaPratica();
      break;
  }

  PlotSolutionArgilosidade(argilosidade.Get_VSH_Vector(), profundidade.Get_perfil_vector(),"Argilosidade", "Argilosidade vs. Profundidade");
}

void CSimulador :: Opcao_litologia()
{  
  litologia.IdentificarLitologias();
  PlotSolutionLitologia(litologia.Get_Arenito_vector(), litologia.Get_ProfArenito_vector(),"Gama Ray", "Gama Ray Arenito vs. Profundidade");
  PlotSolutionLitologia(litologia.Get_Folhelho_vector(), litologia.Get_ProfFolhelho_vector(),"Gama Ray","Gama Ray Folhelho vs. Profundidade");
  cin.get();
  cout << "\n";
}

void CSimulador :: Opcao_porosidade()
{
  porosidade.CalcularPorosidade();
  PlotSolutionPorosidade(porosidade.Get_FI_Vector(), profundidade.Get_perfil_vector(),"Porosidade","Porosidade vs. Profundidade");
  porosidade.PorosidadeMedia();
  cin.get();
  cout << "\n";
}

void CSimulador :: Opcao_saturacao()
{ 
  char opcao;
  cout<< "Entre com a opcao desejada" <<endl;
  cout<< "1- Saturacao de Archie" << endl;
  cout<< "2- Saturacao de Archie com a Argilosidade" <<endl;
  cin>> opcao;
  
  porosidade.CalcularPorosidade();
  
  if (opcao=='1')
{ 
  normal.CalcularSaturacao();
  PlotSolutionSaturacao(normal.Get_SO_Vector(), profundidade.Get_perfil_vector(), "Saturacao de Archie", "Saturacao vs. Profundidade");
  cin.get();
  cout << "\n";
}
else
{
    char opcao;
  do{
  cout << "Para calculo da argilosidade entre com o tipo de rocha" << endl;
  cout << "1 - Para Rocha Consolidada" << endl;
  cout << "2 - Para Rocha Nao Consolidada" << endl;
  cout << "3 - Formula que Nao considera o grau de consolidacao" << endl;
  cin >> opcao;
  if ((opcao != '1') && (opcao != '2') && (opcao !='3')) 
  { cout<< "Opcao invalida!"<< endl;
    opcao='4';
  }
  else {opcao=opcao;};
  
  }while (opcao=='4' );
  
  
  // quando a opção inserida for a correta ocorrerá uma das seguintes opções
  switch (opcao)
  {
    case '1': argilosidade.RochaConsolidada();
      break;
    case '2': argilosidade.RochaNaoConsolidada();
      break;
    case '3': argilosidade.FormaPratica();
      break;
  }
  modificada.CalcularSaturacao();
  PlotSolutionSaturacao(modificada.Get_SO_Vector(), profundidade.Get_perfil_vector(),"Saturacao de Archie com a Argilosidade", "Saturacao vs. Profundidade");
  cin.get();
  cout << "\n";
};
  
}


void CSimulador :: Opcao_perfis()
{
  PlotSolutionGamaRay(gamaray.Get_perfil_vector(), profundidade.Get_perfil_vector(),"Gama Ray","Gama Ray vs. Profundidade");
  PlotSolutionResistividade(resistividade.Get_perfil_vector(), profundidade.Get_perfil_vector(),"Resistividade","Resistividade vs. Profundidade");
  PlotSolutionDensidade(densidade.Get_perfil_vector(), profundidade.Get_perfil_vector(),"Densidade","Densidade vs. Profundidade");
  cin.get();
  cout << "\n";
}



void CSimulador :: PlotSolutionArgilosidade(vector<double> &datax, vector<double> &datay, string dados, string titulo) 
{
    plotArgilosidade.set_style("lines");
    int i= 0;
    double in = profundidade.Perfil(i);
    i = profundidade.NumPontos();
    double on = profundidade.Perfil(i-2);
    plotArgilosidade.set_yrange(on,in);
    plotArgilosidade.set_grid();
    plotArgilosidade.set_xlabel(dados);
    plotArgilosidade.set_ylabel("Profundidade");
    plotArgilosidade.set_pointsize(1.2);
    plotArgilosidade.plot_xy(datax , datay, titulo );
}

void CSimulador :: PlotSolutionPorosidade(vector<double> &datax, vector<double> &datay, string dados, string titulo) 
{
    plotPorosidade.set_style("lines");
    int i= 0;
    double in = profundidade.Perfil(i);
    i = profundidade.NumPontos();
    double on = profundidade.Perfil(i-2);
    plotPorosidade.set_yrange(on,in);
    plotPorosidade.set_grid();
    plotPorosidade.set_xlabel(dados);
    plotPorosidade.set_ylabel("Profundidade");
    plotPorosidade.set_pointsize(1.2);
    plotPorosidade.plot_xy(datax , datay, titulo );
}

void CSimulador :: PlotSolutionSaturacao(vector<double> &datax, vector<double> &datay, string dados, string titulo) 
{
    plotSaturacao.set_style("lines");
    plotSaturacao.set_xrange(0.0, 1.0);
    int i= 0;
    double in = profundidade.Perfil(i);
    i = profundidade.NumPontos();
    double on = profundidade.Perfil(i-2);
    plotSaturacao.set_yrange(on,in);
    plotSaturacao.set_grid();
    plotSaturacao.set_xlabel(dados);
    plotSaturacao.set_ylabel("Profundidade");
    plotSaturacao.set_pointsize(1.2);
    plotSaturacao.plot_xy(datax , datay, titulo );
}

void CSimulador :: PlotSolutionGamaRay(vector<double> &datax, vector<double> &datay, string dados, string titulo) 
{
    plotGamaRay.set_style("lines");
    int i= 0;
    double in = profundidade.Perfil(i);
    i = profundidade.NumPontos();
    double on = profundidade.Perfil(i-2);
    plotGamaRay.set_yrange(on,in);
    plotGamaRay.set_grid();
    plotGamaRay.set_xlabel(dados);
    plotGamaRay.set_ylabel("Profundidade");
    plotGamaRay.set_pointsize(1.2);
    plotGamaRay.plot_xy(datax , datay, titulo );
}

void CSimulador :: PlotSolutionResistividade(vector<double> &datax, vector<double> &datay, string dados, string titulo) 
{   
    int i= 0;
    double in = profundidade.Perfil(i);
    i = profundidade.NumPontos();
    double on = profundidade.Perfil(i-2);
    plotResistividade.set_yrange(on,in);
    const double base = 10;
    plotResistividade.set_xlogscale (base);
    plotResistividade.set_style("lines");
    plotResistividade.set_grid();
    plotResistividade.set_xlabel(dados);
    plotResistividade.set_ylabel("Profundidade");
    plotResistividade.set_pointsize(1.2);
    plotResistividade.plot_xy(datax , datay, titulo );
}

void CSimulador :: PlotSolutionDensidade(vector<double> &datax, vector<double> &datay, string dados, string titulo) 
{
    plotDensidade.set_style("lines");
    int i= 0;
    double in = profundidade.Perfil(i);
    i = profundidade.NumPontos();
    double on = profundidade.Perfil(i-2);
    plotDensidade.set_yrange(on,in);
    plotDensidade.set_grid();
    plotDensidade.set_xlabel(dados);
    plotDensidade.set_ylabel("Profundidade");
    plotDensidade.set_pointsize(1.2);
    plotDensidade.plot_xy(datax , datay, titulo );
}

void CSimulador :: PlotSolutionLitologia(vector<double> &datax, vector<double> &datay, string dados, string titulo) 
{
    plotLitologia.set_style("points");
    int i= 0;
    double in = profundidade.Perfil(i);
    i = profundidade.NumPontos();
    double on = profundidade.Perfil(i-2);
    plotLitologia.set_yrange(on,in);
    plotLitologia.set_grid();
    plotLitologia.set_xlabel(dados);
    plotLitologia.set_ylabel("Profundidade");
    plotLitologia.set_pointsize(1.2);
    plotLitologia.plot_xy(datax , datay, titulo );
}
