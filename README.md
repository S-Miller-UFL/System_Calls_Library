This is a system call library i wrote for linux.

There are 3 folders in this library:
1. P1_files: These are all testing files
2. Files to submit: we are only concerned with p1.diff and process_log.tar.gz
3. Modified files: These are files from the linux kernel i modified to implement these system calls.

Running and testing these system calls requires you do the following:
1. patch the kernel and recompile it
2. build the library and include it in your project

To patch the kernel:
You will need a copy of the reptilian kernel:
https://cise.ufl.edu/research/reptilian/wiki/doku.php
Once its installed, change directory to /usr/rep/src/reptilian-kernel
then, run the following commands:
"git apply p1.diff"
"make && sudo make install && sudo make modules_install"

to build the library:
untar the process_log file and make sure to untar it using gzip
then, run the make file included.
this will produce a lib file that you can include in your project.
