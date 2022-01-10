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
        write(fd,ubuff,sizeof(ubuff));
        close(fd);
}