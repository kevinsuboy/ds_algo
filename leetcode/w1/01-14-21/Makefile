today=$(shell date +%m-%d-%y)

all:
	g++ -std=c++11 problem1.cpp -o problem1.out
	./problem1.out
	g++ -std=c++11 problem2.cpp -o problem2.out
	./problem2.out
	g++ -std=c++11 problem3.cpp -o problem3.out
	./problem3.out
	g++ -std=c++11 problem4.cpp -o problem4.out
	./problem4.out
	g++ -std=c++11 problem5.cpp -o problem5.out
	./problem5.out
	g++ -std=c++11 problem6.cpp -o problem6.out
	./problem6.out
copy:
	# mkdir -p test
	mkdir -p ${today}
	cp skeleton.cpp ${today}/problem1.cpp
	cp skeleton.cpp ${today}/problem2.cpp
	cp skeleton.cpp ${today}/problem3.cpp
	cp skeleton.cpp ${today}/problem4.cpp
	cp skeleton.cpp ${today}/problem5.cpp
	cp Makefile ${today}