#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
//#pragma comment(lib, "ws2_32.lib")//no need for mac
using namespace std;

int main() {
    //string s_string;
    char temp_buffer [100];
    //const char* pkt = "Message to be sent";
    const char* srcIP = "127.0.0.1";
    const char* destIP = "127.0.0.1";
    sockaddr_in dest;
    sockaddr_in local;
    socklen_t dest_len = sizeof(dest);

    dest.sin_family = AF_INET;
    inet_pton(AF_INET, destIP, &dest.sin_addr.s_addr);
    dest.sin_port = htons(3514);

    int s = socket(AF_INET, SOCK_DGRAM, 0);
    //bind(s, (sockaddr *)&dest, sizeof(dest));//dont need to bind for sending messages
    while(true){
        cin>>temp_buffer;
        sendto(s, (char *)temp_buffer, strlen(temp_buffer), 0, (sockaddr *)&dest, dest_len);
        cin.sync();
    }
    close(s);//Closes an existing socket.

    return 0;
}