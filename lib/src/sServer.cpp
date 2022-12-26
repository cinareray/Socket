#include "sServer.h"

/**
  * @brief  Socket olusturmak icin gerekli bilgileri set eden fonksiyon
  * @param  
  * @retval void 
*/
void Socket::sServer::setSocketInfo(){
    this->m_addressLen = sizeof (this->m_hint);
    memset(&this->m_hint, 0, this->m_addressLen);
    this->m_hint.sin_family = AF_INET;
	  this->m_hint.sin_port = htons(this->m_port);

    this->m_hint.sin_addr.s_addr = htonl(INADDR_ANY);
}

Socket::sServer::sServer(){
    setSocketInfo();

}

Socket::sServer::sServer(const int& t_port): m_port(t_port){
    setSocketInfo();
}

/**
  * @brief  Socket olusturmak icin gerekli bilgileri set eden fonksiyon
  * @param  
  * @retval void 
*/
void Socket::sServer::CreatSocket(){

#ifdef _WIN32
		if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) {
			throw std::runtime_error("WSAStartup() failed");
		}
#endif
/*
AF_INET : IPv4
SOCK_STREAM : TCP iken SOCK_DGRAM : UDP
protokol parametresi genellikle 0 kullanılır.
*/
    this->m_socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if(m_socketFd == -1){
        throw std::runtime_error("Could not create socket\r\n");
    }
    this->m_state = STATUS::OPEN;
}


/**
  * @brief  Socket kapatmak icin kullanılan fonksiyon
  * @param  
  * @retval 
*/
void Socket::sServer::CloseSocket(){
#ifdef _WIN32
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) {
			throw std::runtime_error("WSAStartup() failed");
		}
#endif

    if(close(this->m_socketFd < 0))
        throw std::runtime_error("Could not close socket\r\n");
    this->m_state = STATUS::CLOSED;

}


/**
  * @brief  mesaj gönderme fonksiyonu.
  * @param  
           t_socketFd : 
  * @retval 
*/
void Socket::sServer::SendMessage(const int& t_socketFd, const std::string& t_message){
    send(t_socketFd, t_message.c_str(), t_message.size(), 0);
}



/**
  * @brief  Belirlenen IP adresi ve port ile iliskendiren fonksiyon. adres bağlama
  * @param  
  * @retval 
*/
void Socket::sServer::BindServer(){
        if(bind(this->m_socketFd, reinterpret_cast<sockaddr*> (&m_hint), this->m_addressLen) == -1){
            throw std::runtime_error("Could not bind socket\r\n");
        }
}


/**
  * @brief  Belirlenen IP adresi ve port ile iliskendiren fonksiyon. adres baglama. 
            Kuyrkta bekleyecek kişi sayısı 128 olarak ayarlanmistir. 
  * @param  
  * @retval 
*/
void Socket::sServer::ListenServer(){
    if(listen(this->m_socketFd, this->TotalConnectionNumber) == -1){
        throw std::runtime_error("Could not listening\r\n");
    }
}

/**
  * @brief  Taleplerin kabul edildiği yer.
  * @param  
  * @retval 
*/
void Socket::sServer::HandleRequest(){
    std::cout << "Server Running!!\r\n";

    char buff[this->m_messageSize];
      struct sockaddr_in temp_addr;
			socklen_t temp_len = sizeof (temp_addr);

      int temp_socket = accept(this->m_socketFd, reinterpret_cast<sockaddr*>(&temp_addr), &temp_len);
    while(1){

      if(temp_socket < 0 )
      
      {
        std::cout << "İstek kabul hatasi\r\n";
      }

      /*kisi sayisi kontrolu*/
      if(this-> m_clientSize + 1 > this->TotalConnectionNumber)
      {
        std::cout << "Server is full.\r\n";
        close(temp_socket);
        continue;
      }
      this->m_clientSize++;

      memset(buff, 0, this->m_messageSize);
      int len = recv(temp_socket, buff, this->m_messageSize, 0);

      if(len == -1){
        std::cout << "recv hatasi \r\n";
        break;
      }
      
      if(len == 0 ){
        std::cout << "Client disconnected\r\n";
      }
      
      std::cout << "Received message : " << std::string(buff, 0, len);

      send(temp_socket, buff, len + 1, 0);
    } 
    close(temp_socket);
}


/**
  * @brief  run server.
  * @param  
  * @retval 
*/
void Socket::sServer::run_server(){
  CreatSocket();
  BindServer();
  ListenServer();
  HandleRequest();
}
