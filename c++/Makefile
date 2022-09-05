DIRS = basic leetcode

$(info **building  src)

SHELL = /bin/sh
all: compile
compile:
	@echo --------------------------------
	@echo Compiling libraries...
	@echo --------------------------------
	@for lib in $(DIRS); do cd $$lib; echo compiling $$lib; make -s; cd ..; done
clean:
	@echo --------------------------------
	@echo Cleaning libraries...
	@echo --------------------------------
	@for lib in $(DIRS); do cd $$lib; echo cleaning $$lib; make clean; cd ..; done
	rm -f ../lib/*
	rm -f ../bin/*
	rm -f test/test

qmake:
	@echo --------------------------------
	@echo qmake ...
	@echo --------------------------------
	@for lib in $(DIRS); do cd $$lib; echo qmaking $$lib; make qmake; cd ..; done
