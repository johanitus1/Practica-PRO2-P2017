OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: program.o Poblacio.o Individu.o Parell_Cromosomes.o Cromosoma.o Especie.o
	g++ -o program.exe program.o Poblacio.o Individu.o Parell_Cromosomes.o Cromosoma.o Especie.o

program.o: program.cc Poblacio.hh ArbreIO.hh
	g++ -c program.cc $(OPCIONS)

Poblacio.o: Poblacio.cc Poblacio.hh Individu.hh ArbreIO.hh
	g++ -c Poblacio.cc $(OPCIONS)

Individu.o: Individu.cc Individu.hh Parell_Cromosomes.hh
	g++ -c Individu.cc $(OPCIONS)

Parell_Cromosomes.o: Parell_Cromosomes.cc Parell_Cromosomes.hh Cromosoma.hh Especie.hh Cromosoma.hh
	g++ -c Parell_Cromosomes.cc $(OPCIONS)

Cromosoma.o: Cromosoma.cc Cromosoma.hh
	g++ -c Cromosoma.cc $(OPCIONS)

Especie.o: Especie.cc Especie.hh
	g++ -c Especie.cc $(OPCIONS)


practica.tar: Poblacio.hh Individu.hh Parell_Cromosomes.hh Cromosoma.hh Especie.hh program.cc Poblacio.cc Individu.cc Parell_Cromosomes.cc Cromosoma.cc Especie.cc DOC
	zip -r html.zip ./DOC/html
	tar -cvf practica.tar *.hh *.cc html.zip Makefile

DOC:
	doxygen Doxyfile

clean: clean_o clean_exe clean_tar clean_zip clean_html
clean_o:
	-rm *.o

clean_exe:
	-rm *.exe

clean_tar:
	-rm *.tar

clean_zip:
	-rm *.zip

clean_html:
	-rm -rf html
	-rm -rf DOC
