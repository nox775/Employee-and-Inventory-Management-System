all:
	g++ main.cpp ./source/angajat.cpp ./source/persoana.cpp ./source/functii_angajati.cpp -o magazin
clean:
	rm -f magazin