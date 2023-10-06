#include "process_log/process_log.h"
#include <stdio.h>
void set_level();
void get_level();
void log_message();

int main()
{
    set_level();

    get_level();

    log_message();
    return 0;
}

void set_level()
{
    printf("Calling 'kernel_log_setlevel()'...  \n");
    printf("output: %d \n", set_proc_log_level(5));
}

void get_level()
{
    printf("Calling 'kernel_log_getlevel()'...  \n");
    printf("output: %d \n", get_proc_log_level());
}
void log_message()
{
    printf("Calling 'proc_log_message()'...  \n");
    char* c = "i hate thishhhhhhhhhhhhhhhhh";
    printf("output: %d \n",proc_log_message(1,c));
    
}