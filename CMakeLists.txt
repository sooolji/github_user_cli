cmake_minimum_required(VERSION 3.10)

# proyect name and version
project(github-user-cli VERSION 1.0 LANGUAGES CXX)

# define language version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. search for external dependencies
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

# 2. define header
include_directories(include)

# 3. define executables
add_executable(github-activity 
    src/main.cpp 
    src/api_client.cpp 
    src/activity_parser.cpp
)

# 4. link librearies to the executables following cmake good practices
target_link_libraries(github-activity PRIVATE 
    CURL::libcurl 
    nlohmann_json::nlohmann_json
)

# 5. (opcional) config flags for compilation
if(MSVC)
    target_compile_options(github-activity PRIVATE /W4)
else()
    target_compile_options(github-activity PRIVATE -Wall -Wextra -Wpedantic)
endif()