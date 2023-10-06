#include "process_log/process_log.h"
#include <stdio.h>
void set_level();
void get_level();
void log_message();

int main()
{
     if (geteuid() != 0)
       {
          printf("You need to run this program as sudo. \n");
	}
    else
     {
    system("dmesg -c");
    //system("clear");
    set_level_tests();
     }
    return 0;
}

void set_level_tests()
{
    printf("Calling 'kernel_log_setlevel() with -1'...  \n");
    int status = set_proc_log_level(-1);
    if(status == -1)
    {
        printf("your level checking for 'kernel_log_setlevel()' is good for bad inputs %d \n",status);
    }
    else
    {
        printf("your level checking for 'kernel_log_setlevel()' needs to account for bad inputs. exiting... %d \n",status);
        return;
    }
    printf("Calling 'kernel_log_setlevel() with 8'...  \n");
    status = set_proc_log_level(8);
    if(status == -1)
    {
        printf("your level checking for 'kernel_log_setlevel()' is good for bad inputs %d \n",status);
    }
    else
    {
        printf("your level checking for 'kernel_log_setlevel()' needs to account for bad inputs. exiting... %d \n",status);
        return;
    }
    int i;
    for(i=0; i < 8; i++)
    {
        status = set_proc_log_level(i);
        if(status == i)
        {
            printf("your syscall can set the level to: %d \n", i);
        }
        else
        {
            printf("your syscall cant set the level to: %d \n", i);
            break;
        }
    }
    if(status == -1)
    {
        printf("set level tests failed, exiting... \n");
        return;
    }
    else
    {
        get_level();
    }
}

void get_level()
{
    printf("Calling 'kernel_log_getlevel()'...  \n");
    int status = 0;
    int i;
    for(i=0; i < 8; i++)
    {
        status = set_proc_log_level(i);
        status = get_proc_log_level();
        if (status == -1)
        {
            printf("something happened, the current log level cant be retrieved. %d \n",status);
            return;
        }
        else
        {
            printf("your 'kernel_log_getlevel()' works fine %d \n", status);
        }
    }
        status = set_proc_log_level(8);
        status = get_proc_log_level();
        printf("output: %d \n", get_proc_log_level());
        if (status == -1)
        {
            printf("something happened, the current log level cant be retrieved. %d \n",status);
            return;
           // break;
        }
        else
        {
            printf("your 'kernel_log_getlevel()' works fine %d \n", status);
        }
    if(status == -1)
    {
        printf("get level tests failed, exiting... \n");
        return;
    }
    else
    {
        log_message();
    }
}
void log_message()
{
    int status =0;
    printf("Calling 'proc_log_message()' with valid string  \n");
    char* c = "This is a valid string";
    int i;
    for(i=0; i < 8; i++)
    {
        status = proc_log_message(i,c);
        if(status == i)
        {
            printf("your syscall can print normal messages %d \n", status);
        }
        else
        {
            printf("your syscall cant print normal messages \n");
            break;
        }
    }
    if(status == -1)
    {
        printf("log message tests failed for normal strings, exiting... \n");
        return;
    }
    printf("Calling 'proc_log_message()' with very long string  \n");
    c = "The largest ocean in the world is the pacific ocean The largest ocean in the world is the pacific ocean The largest ocean in the world is the pacific ocean";
    for(i=0; i < 8; i++)
    {
        status = proc_log_message(i,c);
        if(status == i)
        {
            printf("your syscall prints strings that are too long. exiting... %d \n",status);
            return;
        }
        else
        {
            printf("your syscall can reject messages that are too long %d \n",status);
        }
    }
    
    if(status != -1)
    {
        printf("log message tests failed for long strings, exiting... \n");
        return;
    }

    printf("Calling 'proc_log_message()' with empty string  \n");
    c = "";
    for(i=0; i < 8; i++)
    {
        status = proc_log_message(i,c);
        if(status == i)
        {
            printf("your syscall prints strings that are empty %d \n", status);
        }
        else
        {
            printf("your syscall cant print strings that are empty %d \n",status);
            break;
        }
    }
    if(status == -1)
    {
        printf("log message tests failed for empty strings, exiting... \n");
        return;
    }

    printf("Calling 'proc_log_message()' with -1 log level  \n");
    c = "you should not be seeing this message, as its level is -1";
    status = proc_log_message(-1,c);
    if(status == -1)
    {
        printf("your syscall can detect invalid log request levels %d \n",status);
    }
    else
    {
        printf("your syscall cant detect invalid log request levels %d \n",status);
    }
   if(status != -1)
    {
        printf("log message tests failed for invalid log levels, exiting... \n");
        return;
    }
    printf("Calling 'proc_log_message()' with 8 log level  \n");
    c = "you should not be seeing this message, as its level is 8";
    status = proc_log_message(8,c);
    if(status == -1)
    {
        printf("your syscall can detect invalid log request levels %d \n",status);
    }
    else
    {
        printf("your syscall cant detect invalid log request levels %d \n",status);
    }
   if(status != -1)
    {
        printf("log message tests failed for invalid log levels, exiting... \n");
        return;
    }
        

    printf("Calling 'proc_log_message()' with 128 character string \n");
    c = "bkcuwrnnmelpanxinxthixrkneejrpbkghmsqeiqtshwptoavxeosjzogwfcooazhnzxbeotkyauzhhftyzmkoxrcusvqeguoumyynqeotfvtstoaatcesnyazcevxks";
    for(i=0; i < 8; i++)
    {
        status = proc_log_message(i,c);
        if(status == i)
        {
            printf("your syscall prints strings that are 128 characters long %d \n", status);
        }
        else
        {
            printf("your syscall cant print strings that are 128 characters long %d \n",status);
            break;
        }
    }
    if(status == -1)
    {
        printf("log message tests failed for 128 character strings, exiting... \n");
        return;
    }

    printf("Setting logging level to 3... %d \n", set_proc_log_level(3));
    printf("Calling 'proc_log_message()' at level 4 \n");
    c = "you should not see this message, as this is logged at level 4 and the current kernel level is 3";
    for(i=4; i < 8; i++)
    {
        status = proc_log_message(i,c);
        if(status == i)
        {
            printf("your syscall rejects high log requests %d \n", status);
        }
        else
        {
            printf("your syscall cant reject high log requests %d \n",status);
            break;
        }
    }
    if(status == -1)
    {
        printf("log message tests failed for high log requests, exiting... \n");
        return;
    }

    printf("Setting logging level to 7... %d \n", set_proc_log_level(7));
    printf("Calling 'proc_log_message()' with bad address \n");
    //c = "you should not see this message, as this is logged at level 4 and the current kernel level is 3";
    for(i=0; i < 8; i++)
    {
        status = proc_log_message(i,0xffff);
        if(status == -1)
        {
            printf("your syscall rejects bad addresses %d \n", status);
        }
        else
        {
            printf("your syscall cant reject bad addresses %d \n",status);
            break;
        }
    }
    if(status != -1)
    {
        printf("log message tests failed for bad address exiting... \n");
        return;
    }

    system("dmesg");

}