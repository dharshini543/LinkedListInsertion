cmake_minimum_required(VERSION 3.16)

project(LinkedListInsertion LANGUAGES C)

add_executable(LinkedListInsertion main.c)

include(GNUInstallDirs)
install(TARGETS LinkedListInsertion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
