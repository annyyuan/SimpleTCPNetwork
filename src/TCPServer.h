#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <thread>
#include <mutex>
#include <queue>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Message.h"

#define MAXPACKETSIZE 4096

class TCPServer {
private:
    int sock;
    std::mutex mtx;
    struct sockaddr_in serverAddress;
    std::queue<Message> messages;

    void task(int newSock);

public:
    void setup(int port, int connections);
    void receive();
    Message getMessage();
    void send(Message msg);
    void detach();
    bool message();
};

#endif