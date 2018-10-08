OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x


all:
	g++ -c *.cc $(OPCIONS)
	g++ -o program.exe *.o $(OPCIONS)

clean:
	rm *.o
	rm *.exe
