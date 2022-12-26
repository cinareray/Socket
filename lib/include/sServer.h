

#ifndef SSERVER_H
#define SSERVER_H

#include <iostream>
#include <string.h>
#include <string>
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    typedef int socklen_t;
    static WSAData wsaData;
#else
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <netinet/in.h>
#endif

namespace Socket {

    enum class STATUS {
        OPEN, 
        CLOSED
    };

    
    class sServer {
    protected:
        int m_socketFd = -1;
	    struct sockaddr_in m_hint;
	    int m_port = 5000;
	    int m_addressLen = 0;
	    int m_messageSize = 4096;
	    STATUS m_state;
    
        int TotalConnectionNumber = 128; 
        void setSocketInfo();
        void CreatSocket();
        void BindServer();
        void ListenServer();
        void HandleRequest();
        void SendMessage(const int& t_socketFd, const std::string& t_message);
        void CloseSocket();
    

        /*client*/
        int m_clientSize = 0;
    public:
        sServer();
        sServer(const int& t_port);
        void run_server();

    };

} /*namespace*/

#endif /* SSERVER_H*/