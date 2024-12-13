all:
	g++ main.cpp ./source/angajat.cpp ./source/produs.cpp ./source/persoana.cpp -o magazin
clean:
	rm -f magazin