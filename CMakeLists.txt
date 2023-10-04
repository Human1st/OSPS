cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_BUILD_TYPE Debug)
project(phonescan)

find_package(CURL REQUIRED) 
include_directories(${CURL_INCLUDE_DIR})

set(SOURCES 
src/phonescan/PhoneData.cpp
src/phonescan/CountryCode.cpp
src/phonescan/GlobalPhoneScan.cpp
src/phonescan/france/FrancePhoneScan.cpp
src/utils/StringOperation.cpp
src/main.cpp)

include_directories(src/)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${CURL_LIBRARIES})