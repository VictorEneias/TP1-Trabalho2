make:
 	g++ -std=c++11 main.cpp database.cpp servico.cpp dominio.cpp -o app -lsqlite3
	./app
	rm app

