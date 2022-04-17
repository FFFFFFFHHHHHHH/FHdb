#include <stdio.h>
#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {

    // 创建socket
    int fd = socket(PF_INET, SOCK_STREAM, 0);
    if(fd == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in seraddr;
    inet_pton(AF_INET, "172.31.135.91", &seraddr.sin_addr.s_addr);
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(1234);

    // 连接服务器
    int ret = connect(fd, (struct sockaddr *)&seraddr, sizeof(seraddr));

    if(ret == -1){
      puts("connect fail");
      return -1;
    }

    int num = 0;
    while(1) {
      std::string str;
      std::cin >> str;
      write(fd, str.c_str(), str.length());
      std::cout << "post : " << str << std::endl;
      char buff[1000] = {0};
      read(fd, buff, sizeof buff);
      std::cout << "get : " << buff << std::endl;
        // char sendBuf[1024] = {0};
        // sprintf(sendBuf, "send data %d", num++);
        // write(fd, sendBuf, strlen(sendBuf) + 1);
        // puts("write over");

    }

        // 接收
       // int len = read(fd, sendBuf, sizeof(sendBuf));
       //  if(len == -1) {
       //      perror("read");
       //      return -1;
       //  }else if(len > 0) {
       //      printf("read buf = %s\n", sendBuf);
       //  } else {
       //      printf("服务器已经断开连接...\n");
       //      break;
       //  }
        // sleep(1);
        //usleep(1000);
    // }

    close(fd);

    return 0;
}
 
