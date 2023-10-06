compileproject1: main.c 
	cd process_log && cc -g -c process_log.c && ar cr libprocess_log.a process_log.o
	cc -g -o project_1_compiled main.c -L ./process_log -lprocess_log
	cc -o setlevel  setlevel.c -L ./process_log -lprocess_log
	cc -o getlevel  getlevel.c -L ./process_log -lprocess_log
	cc -o send_log  send_log.c -L ./process_log -lprocess_log
	g++ -o harness_test  harness_test.cpp -L ./process_log -lprocess_log
	g++ -o library_test  library_test.cpp -L ./process_log -lprocess_log

compilekernel:
	cd /usr/rep/src/reptilian-kernel && sudo make && sudo make install && sudo make modules_install

generatepatch:
	cd /usr/rep/src/reptilian-kernel && git add -u && git add '*.c' '*.h' '*Makefile*' '*.tbl' && git diff remotes/origin/os-latest > p1.diff

runtests:
	./setlevel 1 && ./getlevel && ./send_log 1 "this is a test"
	sudo ./setlevel 7 && ./getlevel && ./send_log 0 "this is a test as sudo"