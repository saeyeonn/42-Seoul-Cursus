#include <unistd.h>

void first(char *argv1)
{
    int i, flag = 0;
    int j = -1;

    if (argv1[0])
        write(1, &argv1[0], 1);

    while (argv1[++i])
    {   
        flag = 0;
        j = -1;
        while (++j < i)
            if (argv1[j] == argv1[i])
            {
                flag = 1;
                break;
            }
        if (!flag)
            write(1, &argv1[i], 1);
    }
    return ;
}


void second(char *argv2, int i2)
{
    int index = -1;
    int flag = 1;

    while (++index < i2)
    {
        flag = 1;
        if (argv2[index] == argv2[i2])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
        write(1, &argv2[i2], 1);
    
    return ;
}

void compare(char *argv1, char *argv2)
{
    int i1, i2 = -1;
    int flag = 1;
    while (argv2[++i2])
    {
        i1 = -1;
        flag = 1;
        while (argv1[++i1])
            if (argv1[i1] == argv2[i2])
            {
                flag = 0;
                break;
            }
        if (flag)
            second(argv2, i2);
    }
    return ;
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        first(argv[1]);
        compare(argv[1], argv[2]);
    }

    write(1, "\n", 1);
    return 0;
}