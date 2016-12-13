
/*
  StackOverrun.c
  This program shows an example of how a stack-based 
  buffer overrun can be used to execute arbitrary code.  Its 
  objective is to find an input string that executes the function bar.
*/

#pragma check_stack(off)

#include <string.h>
#include <stdio.h> 
// assuming a 32 bit machine here

void digInStack(char * string)
{
    long sneak[1];
    static int j=0;
    if(j++ == 1)
    {   puts("hack here\n");
        sneak[11] = bar;
    }

    int i;
    printf("[ %s ] \n",string);
    // feel free to adjust the search limits
    for( i = -32; i <= 32; ++i) {
        printf("offset %3d: data 0x%08X\n", i, sneak[i]);
    }
    //sneak[11] = 0x4007be;
    puts("...................\n");
}


// for ubuntu stytle
void foo_ubuntu(const char* input)
{
    char buf[10];
    digInStack("before strcpy");

    printf("buf address here &buf %p buf %p \n",&buf,buf);
    //printf("My stack looks like:\n%p\n %p\n %p\n %p\n return address %p\n %p\n \n");
    printf("saved return address at %p\n", __builtin_return_address(0));
    //strcpy(buf, input);
    digInStack("after strcpy");
    printf("%s\n", buf);

    
    //printf("Now stack looks like:\n%p\n %p\n %p\n %p\n return address %p\n %p\n \n");
}



// for windows stytle
void foo_windows(const char* input)
{
    char buf[10];

    printf("buf address here &buf %p buf %p \n",&buf,buf);
    printf("My stack looks like:\n%p\n %p\n %p\n %p\n return address %p\n %p\n \n");
    printf("foo is %p\n", __builtin_return_address(0));
    strcpy(buf, input);
    printf("%s\n", buf);

    printf("Now stack looks like:\n%p\n %p\n %p\n %p\n return address %p\n %p\n \n");
}

void bar(void)
{
    printf("[ERROR] Augh! I've been hacked!\n");
}

int main(int argc, char* argv[])
{
    //Blatant cheating to make life easier on myself
    printf("Address of main = %p\n", main);
    printf("Address of foo = %p\n", foo_ubuntu);
    printf("Address of bar = %p\n", bar);
    printf("main is %p\n", __builtin_return_address(0));
    if (argc != 2) 
    {
        printf("Please supply a string as an argument!\n");
        return -1;
	} 
    foo_ubuntu(argv[1]);
    return 0;
}

