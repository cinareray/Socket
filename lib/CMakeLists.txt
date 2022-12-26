#cmake minimum VERSION
cmake_minimum_required(VERSION 2.8)

#proje ismi 
project(socket)


# CMake include_directories komutu, belirtilen dizinlerin derleyici tarafından dahil edilmesini sağlar. 
# Bu, derleyiciye belirtilen dizinlerdeki başlık dosyalarının bulunmasını ve bu dosyaların derleme sırasında dahil edilmesini sağlar.
# Bu komut, bir kaynak kod projesinin derlenmesinde gerekli olan başlık dosyalarının yolunu belirtmek için kullanılır.(from chat.openai)
include_directories(include)

# set komutu ile var olan tüm lib ve src leri bir degisken# set komutu ile var olan tüm lib ve src leri bir degiskende tutabiliriz.# set komutu ile var olan tüm lib ve src leri bir degiskende tutabiliriz.
set(SOURCE include/sServer.h src/sServer.cpp)



# Cmake add_library komutu, kütüphaneleri eklemek maksadi ile kullanılır. modlari ise
# STATIC   Yalnızca derleme zamanında doğrudan gömülebilen kütüphane 
# SHARED   Derleme zamanında linklenebilen ve çalışma zamanında yüklenebilen kütüphane
# MODULE   Derleme zamanında linkleme olmaksızın, çalışma zamanında ihtiyaç hâlinde yüklenebilen kütüphane
add_library(mylib STATIC ${SOURCE})
