main: main.o Book.o Reader.o History.o Library.o Library_manager.o Library_reader.o Menu.o Menu_manager.o Menu_reader.o Console.o Functions.o
	g++ main.o Book.o Reader.o History.o Library.o Library_manager.o Library_reader.o Menu.o Menu_manager.o Menu_reader.o Console.o Functions.o -o main -std=c++11
main.o: main.cpp Library.h Console.h Menu.h
	g++ main.cpp -c -o main.o -std=c++11
Book.o: Book.cpp Book.h
	g++ Book.cpp -c -o Book.o -std=c++11
Reader.o: Reader.cpp Reader.h
	g++ Reader.cpp -c -o Reader.o -std=c++11
History.o: History.cpp History.h
	g++ History.cpp -c -o History.o -std=c++11
Library.o: Library.cpp Book.h Reader.h History.h Library.h Functions.h
	g++ Library.cpp -c -o Library.o -std=c++11
Library_manager.o: Library_manager.cpp Book.h Reader.h History.h Library.h Functions.h
	g++ Library_manager.cpp -c -o Library_manager.o -std=c++11
Library_reader.o: Library_reader.cpp Book.h Reader.h History.h Library.h Functions.h
	g++ Library_reader.cpp -c -o Library_reader.o -std=c++11
Menu.o: Menu.cpp Library.h Console.h Menu.h Functions.h 
	g++ Menu.cpp -c -o Menu.o -std=c++11
Menu_manager.o: Menu_manager.cpp Library.h Menu.h Functions.h
	g++ Menu_manager.cpp -c -o Menu_manager.o -std=c++11
Menu_reader.o: Menu_reader.cpp Library.h Menu.h Functions.h
	g++ Menu_reader.cpp -c -o Menu_reader.o -std=c++11
Console.o: Console.cpp Console.h Library.h
	g++ Console.cpp -c -o Console.o -std=c++11
Functions.o: Functions.cpp Functions.h
	g++ Functions.cpp -c -o Functions.o -std=c++11
clean:
	rm *.o
