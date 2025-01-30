make:

teste:
	g++ -std=c++11 main.cpp database.cpp servico.cpp dominio.cpp -o main -lsqlite3
	./main
	rm main