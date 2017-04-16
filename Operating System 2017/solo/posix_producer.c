//gcc posix_produer.c -lrt

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/stat.h>

#define SIZE 4096   //size of the shared memory object

int main(void)
{
    const char *name = "OS";    //name of the shared memory object
    const char *msg0 = "HELLO";
    const char *msg1 = "World!";

    int shm_fd = shm_open(name, O_CREAT|O_RDWR, 0666); //shared memory file descripter
    void *ptr;  //pointer to shared memory object

    ftruncate(shm_fd, SIZE);    //configure the size of the shared memory object
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0); //memory map the shared ,e,pry object
    
    sprintf(ptr, "%s", msg0);
    ptr += strlen(msg0);
    sprintf(ptr, "%s", msg1);
    ptr += strlen(msg1);

    return 0;
}
