#include<stdio.h>
#include<sys/type.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{

        int fd;
        char ubuff[]= "user buffer is sending data to kernel buffer";
        char kbuff[100];
        
        fd=open("/dev/Kernel", O_RDONLY);
        if(fd<0)
        {
            printf("ERROR OPENING DEVICE");
            exit(1);
        }

        read(fd,kbuff,50);
        print("READING DATA : %s\n",kbuff);
        close(fd);