/*
@File    :   setns.c
@Time    :   2020/03/22 11:37:41
@Author  :   xiaosongsong
@Desc    :   None

Linux中每个进程都拥有自己对应的namespace,这是通过clone系统调用传递对应的参数来实现的。
对于一个已经存在的进程，我们可以使用setns系统调用来将一个进程加入到另一个经常的namespace中。
如下：

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

#define errExit(msg)        \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)
int main(int argc, char *argv[])
{
    int fd;
    fd = open(argv[1], O_RDONLY);
    if (setns(fd, 0) == -1)
    {
        errExit("setns");
    }
    execvp(argv[2], &argv[2]);
    errExit("execvp");
    return 0;
}
