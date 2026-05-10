cmake_minimum_required(VERSION 3.20)
project(CMSToolkit)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJECT_NAME} SHARED
        cms_toolkit_dll.hpp
        cms_toolkit_dll.cpp
)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/dist)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(${PROJECT_NAME} PRIVATE CMS_EXPORTS)


set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")


install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)


install(TARGETS ${PROJECT_NAME}

        RUNTIME DESTINATION bin

        ARCHIVE DESTINATION lib

        LIBRARY DESTINATION lib
)

install(FILES
        cms_toolkit_dll.hpp
        cms_utils.hpp
        DESTINATION include
)