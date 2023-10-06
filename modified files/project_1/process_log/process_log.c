//created by steven miller on september 21, 2023
/*
//description: allows access to system calls
*/
#include "process_log.h"
int get_proc_log_level()
{
    int status = syscall(GET_KERNEL_LOGLEVEL_CALL);
    if(status == -1)
    {
        return -1;
    }
    else
    {
        return status;
    }
}

int set_proc_log_level(int new_level)
{
    int status = syscall(SET_KERNEL_LOGLEVEL_CALL, new_level);
    if(status == -1)
    {
        return -1;
    }
    else if (status == -2)
    {
        return -1;
    }
    else
    {
        return status;
    }

}

int proc_log_message(int level, char* message)
{
   int status = syscall(PROC_LOG_CALL, message, level);
   if(status == -2)
   {
    return -1;
   }
   else if (status == -3)
   {
    return -1;
   }
   else
   {
    return status;
   }
}

int* retrieve_set_level_params(int new_level)
{
    int* set_level_params = (int*)malloc(3*sizeof(int));
    set_level_params[0] = SET_KERNEL_LOGLEVEL_CALL;
    set_level_params[1] = 1;
    set_level_params[2] =  new_level;
    return set_level_params;
}

int* retrieve_get_level_params()
{
    int* get_level_params = (int*)malloc(2*sizeof(int));
    get_level_params[0] = GET_KERNEL_LOGLEVEL_CALL;
    get_level_params[1] = 0;
    return get_level_params;
}

int interpret_set_level_result(int ret_value)
{
    if(ret_value == -1)
    {
        return -1;
    }
    else if(ret_value == -2)
    {
        return -1;
    }
    else
    {
        return ret_value; 
    }
}

int interpret_get_level_result(int ret_value)
{
    if(ret_value == -1)
    {
        return -1;
    }
    else
    {
        return ret_value;
    }
 
}

int interpret_log_message_result(int ret_value)
{
    if(ret_value == -2)
    {
        return -1;
    }
    else if(ret_value == -3)
    {
        return -1;
    }
    else
    {
        return ret_value; 
    }
}