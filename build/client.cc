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
   inet_pton(AF_INET, "118.31.10.109", &seraddr.sin_addr.s_addr);
   seraddr.sin_family = AF_INET;
   seraddr.sin_port = htons(3389);
    // 连接服务器
   int ret = connect(fd, (struct sockaddr *)&seraddr, sizeof(seraddr));
    if(ret == -1){
     puts("connect fail");
     return -1;
   }
   int num = 0;
   while(true) {
     printf("> ");
     std::string str;
     std::getline(std::cin, str);
     if (str[0] == 'q') {
       break;
     }
     write(fd, str.c_str(), str.length());
     char buff[10000] = {0};
     read(fd, buff, sizeof buff);
     std::cout << buff << std::endl;
   }
}

 
