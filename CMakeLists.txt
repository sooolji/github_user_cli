cmake_minimum_required(VERSION 3.16)

project(github-user-cli VERSION 1.0 LANGUAGES CXX)

# global language settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# helpful defaults for tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# dependencies
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

# testing
include(CTest)

# core library (reused by app + tests)

add_library(github_user_cli_lib
    src/api_client.cpp
    src/activity_parser.cpp
)

target_include_directories(github_user_cli_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(github_user_cli_lib
    PUBLIC
        CURL::libcurl
        nlohmann_json::nlohmann_json
)

# main executable

add_executable(github-activity
    src/main.cpp
)

target_link_libraries(github-activity
    PRIVATE
        github_user_cli_lib
)

# warnings (target-scoped)

if(MSVC)
    target_compile_options(github_user_cli_lib PRIVATE /W4 /permissive-)
    target_compile_options(github-activity PRIVATE /W4 /permissive-)
else()
    target_compile_options(github_user_cli_lib PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(github-activity PRIVATE -Wall -Wextra -Wpedantic)
endif()



# unit tests (GoogleTest)
