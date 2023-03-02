CC=g++

sources=main.cpp CPerfil.cpp CProfundidade.cpp CGamaRay.cpp CResistividade.cpp CDensidade.cpp CSaturacaoArchieModificada.cpp \
	CPorosidade.cpp CArgilosidade.cpp CSaturacaoArchieNormal.cpp CSimulador.cpp CLitologia.cpp CGnuplot.cpp

headers=CProfundidade.h CPerfil.h CGamaRay.h CResistividade.h CDensidade.h CSaturacaoArchieModificada.h \
	CPorosidade.h CArgilosidade.h CSaturacaoArchieNormal.h CSimulador.h CLitologia.h CGnuplot.h

objects=$(sources:.cpp=.o)
executable=programa

all: $(sources) $(executable)

$(executable): $(objects)
	$(CC) $(objects) -o $@

.cpp.o:
	$(CC) $< -c -o $@

clear:
	rm -f *.o
	rm -f *.gch
	rm -f a.out
	rm -f programa