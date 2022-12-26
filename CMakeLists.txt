#cmake minimum VERSION isteri
cmake_minimum_required(VERSION 2.8)

#proje ismi verilir.
project(socket)

#alt nodelardaki cmake uzantı yolu girilmek icin. Örnekte ana dizindeki CMakeLists.txt dosyasında,
# alt dizinlerdeki CMakeLists.txt dosyalarını bağımsız şekilde tanıtabiliriz.
add_subdirectory(lib)

# lib yolunu göstermek icin
include_directories(lib/include)


# add_executable ile calistiralacak olan dosya
add_executable(server test/Server.cpp)


# target_link_library ise nodelarda kullanılan lib ve source yollarına calistirilan dosya ile linkleme yapilir.
target_link_libraries(server mylib)


# proje çıktıları olan library(dll, .os), archive gibi cıktıları düzenlenmesi ve sisteme entegre edilmesi icin kullanılır.
install(TARGETS server DESTINATION /home/ec2-user/socket/bin)

#isletim sistemini ogrenme ve message kullanımı
#MOD	                AÇIKLAMA
#STATUS	                Bilgi metni
#WARNING	            CMake Uyarısı, işlem devam eder
#AUTHOR_WARNING	        CMake Uyarısı (kod), işleme devam eder
#SEND_ERROR	            CMake Hatası, işleme devam eder fakat oluşturmayı atlar
#FATAL_ERROR	        CMake Hatası, işlemi ve oluşturmayı durdurur
#DEPRECATION	        CMake Kullanımdan Kaldırılma Hatası, CMAKE_ERROR_DEPRECATED ya da CMAKE_WARN_DEPRECATED değişkeni aktif değilse hata vermez
if(UNIX AND NOT APPLE)
    message( STATUS "linux system")
endif(UNIX AND NOT APPLE)
 
if(WIN32)
    message( STATUS "windows system")
endif()

if(APPLE)
    message( STATUS  "apple sistemdir")
endif()

if(UNIX)
    message( STATUS "unix system(Apple OS X etc.)")
endif()