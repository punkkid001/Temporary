// gcc posix_consumer.c -lrt

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/stat.h>

#define SIZE 4096

int main(void)
{
    const char *name = "OS";
    int shm_fd = shm_open(name, O_RDONLY, 0666);
    void *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

    printf("%s", (char *)ptr);
    shm_unlink(name);

    return 0;
}
