all:
	g++ main.cpp ./source/angajat.cpp ./source/persoana.cpp ./source/functii_angajati.cpp ./source/functii_stoc.cpp ./source/comanda.cpp ./source/disc_vint.cpp ./source/disc.cpp ./source/produs.cpp ./source/vestimentatie.cpp ./source/functii_comenzi.cpp ./source/operator.cpp ./source/functii_raport.cpp -o magazin
clean:
	rm -f magazin