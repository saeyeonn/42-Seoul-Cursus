#include <unistd.h>

int self_check(char *argv1, int i) 
{
    int index = -1;

    while (++index < i) 
        if (argv1[i] == argv1[index])
            return 1;
    return 0;
}

int double_check(char c, char *argv2) 
{
    int i = -1;
    
    while (argv2[++i])
        if (c == argv2[i])
           return 1;
    return 0;
}

int main(int argc, char* argv[])
{
    int i = -1; 

    if (argc == 3)
        while (argv[1][++i])
            if (!self_check(argv[1], i)) 
                if (double_check(argv[1][i], argv[2]))
                    write(1, &argv[1][i], 1);    
                
    write(1, "\n", 1);    
    return 0;
}