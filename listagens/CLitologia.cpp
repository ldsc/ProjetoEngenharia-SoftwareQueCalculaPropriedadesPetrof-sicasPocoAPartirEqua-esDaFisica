#include "CLitologia.h"
// #include "CGamaRay.h"
#include <vector>

using namespace std;

CLitologia :: CLitologia(CGamaRay* gamaray_ent, CProfundidade* profundidade_ent)
{
  profundidade = profundidade_ent;
  gamaray = gamaray_ent;
}

void CLitologia :: IdentificarLitologias()
{
  litoArenito.clear();
  profArenito.clear();
  litoFolhelho.clear();
  profFolhelho.clear();
  for (int i = 0; i<gamaray->NumPontos(); i++)
  {
    if (gamaray->Perfil(i)<90.0)
    {
      litoArenito.push_back(gamaray->Perfil(i));
      profArenito.push_back(profundidade->Perfil(i));
    }
    else
    {
      litoFolhelho.push_back(gamaray->Perfil(i));
      profFolhelho.push_back(profundidade->Perfil(i));
    }
  }
}
