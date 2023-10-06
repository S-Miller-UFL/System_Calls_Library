//created by steven miller on september 21, 2023
/*
//description: allows access to system calls
*/
#pragma once
#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>
#define PROC_LOG_CALL 548
#define SET_KERNEL_LOGLEVEL_CALL 549
#define GET_KERNEL_LOGLEVEL_CALL 550
/*
Invokes system call which reads system-wide process log level. 
Returns the process log level on success, and -1 otherwise.
*/
int get_proc_log_level();
/*
Invokes system call which attempts to change the 
system-wide process log level to new_level. Returns new_level
on success, and -1 otherwise. On failure, log level should be unchanged.

*/
int set_proc_log_level(int);
/*
Invokes system call to log a message for this process. 
If logged, the message should appear in dmesg logs at 
the corresponding kernel level. Returns -1 for invalid 
log level (or if message is too long), and level otherwise
*/
int proc_log_message(int ,char*);

/*
Returns an int array of 2-4 values that can
be used to make the set-process-log-level system call.

*/
int* retrieve_set_level_params(int);
/*
Returns an int array of 2-4 values that can 
be used to make the get-process-log-level system call.
*/
int* retrieve_get_level_params();
/*
After making the system call, 
we will pass the syscall return value to this 
function call. It should return set_proc_log_level’s 
interpretation of the system call 
completing with return value ret_value
*/
int interpret_set_level_result(int);
/*
After making the system call, 
we will pass the syscall return value to this function call. 
It should return get_proc_log_level’s interpretation 
of the system call completing with return value ret_value. 
*/
int interpret_get_level_result(int);
/*
After making the system call, we will pass the 
syscall return value to this function call. 
It should return proc_log_message’s interpretation 
of the system call completing with return value ret_value. 
*/
int interpret_log_message_result(int);
