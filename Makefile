all:
	g++ main.cpp ./source/angajat.cpp ./source/magazin.cpp ./source/produs.cpp -o magazin
clean:
	rm -f magazin