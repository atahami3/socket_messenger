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
using namespace std;

int main() {
    char temp_buffer [100]; 
    const char* srcIP = "127.0.0.1";
    const char* destIP = "127.0.0.1";
    sockaddr_in dest;
    sockaddr_in local;

    socklen_t local_len = sizeof(local);
    
    local.sin_family = AF_INET;
    inet_pton(AF_INET, srcIP, &local.sin_addr.s_addr);
    local.sin_port = htons(3514);
    cout<<sizeof(temp_buffer);

    int s = socket(AF_INET, SOCK_DGRAM, 0);
    bind(s, (sockaddr *)&local, sizeof(local));

    while(true){
        recvfrom(s, (char *)temp_buffer, 100, 0,  (sockaddr *) &local, &local_len);
        cout << temp_buffer << endl;
        cin.sync(); 
   }

    close(s);

    return 0;
}