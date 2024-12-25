all:
	g++ main.cpp ./source/angajat.cpp ./source/persoana.cpp ./source/functii_angajati.cpp ./source/functii_stoc.cpp ./source/comanda.cpp ./source/disc_vint.cpp ./source/disc.cpp ./source/produs.cpp ./source/vestimentatie.cpp -o magazin
clean:
	rm -f magazin