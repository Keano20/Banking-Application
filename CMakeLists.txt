cmake_minimum_required(VERSION 3.30)
project(Banking_Application)

set(CMAKE_CXX_STANDARD 20)

# Add include directory for header resolution
include_directories(include)

# Add all source files here
add_executable(Banking_Application
        main.cpp
        src/Account.cpp
        src/SavingsAccount.cpp
        src/CurrentAccount.cpp
        src/AccountFactory.cpp
)