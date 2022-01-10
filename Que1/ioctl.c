#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
 
#define WR_buff _IOW('a','0',arg_t*)
#define RD_buff _IOR('a','1',arg_t*)
 
int main()
{
        int fd;
        char S[]; 
        int number,value;
 
        printf("\nOpening Driver\n");
        fd = open("/dev/etx_device", O_RDWR);
        if(fd < 0) {
                printf("Cannot open device file...\n");
                return 0;
        }
 
        printf("Enter the string to send\n");
        scanf("%s",S);
        printf("Writing string to Driver\n");
        ioctl(fd, WR_buff, (char*) &number); 
 
        printf("Reading Value from Driver\n");
        ioctl(fd, RD_buff, (char*) &value);
        printf("Value is %d\n", value);
 
        printf("Closing Driver\n");
        close(fd);
}