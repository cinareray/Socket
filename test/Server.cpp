#include "sServer.h"
#include <csignal>
#include <iostream>
#include <limits>

void isExit(int code){
    char p{};
    std::cout << "Are you sure exit program[Y/N]? : ";
    std::cin >> p;
    if( toupper(p) == 'Y')
    {
        exit(0);
    }
    std::cin.clear();
}


int main(){
    signal(SIGINT, isExit);

    std::cout << "ALL RIGHT!\r\n";
	int port = 54000;
	std::cout << "Port: ";
	std::cin >> port;
    Socket::sServer t_new(port);
    try{
            t_new.run_server();

    }catch(const std::exception& e){
        std::cout << e.what() << "\r\n";
    }
}