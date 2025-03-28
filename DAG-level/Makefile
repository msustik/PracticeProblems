%.o: %.cpp
	g++ -Wall -O3 -std=c++20 -c $<

%.exe: %.o
	g++ -Wall -O3 -std=c++20  $< -o $@

%_g.o: %.cpp
	g++ -Wall -g -O0 -std=c++20 -o $@ -c $<

%_g.exe: %_g.o
	g++ -Wall -g -O0 -std=c++20  $< -o $@

%_pg.o: %.cpp
	g++ -Wall -pg -O3 -std=c++20 -o $@ -c $<

%_pg.exe: %_pg.o
	g++ -Wall -pg -O3 -std=c++20  $< -o $@
