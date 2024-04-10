cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(bde)
set(CMAKE_CXX_STANDARD 20)

SET(CMAKE_COLOR_MAKEFILE ON)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache) # Less useful to do it for linking, see edit2
endif(CCACHE_FOUND)


add_definitions("-O4 -Wall -Wextra -fdiagnostics-color -g")

set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")
# set_property(TARGET bde RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

# find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
# if (CMAKE_CXX_CPPCHECK)
#     list(
#         APPEND CMAKE_CXX_CPPCHECK 
#             "--enable=warning"
#             # "-i json.hpp"
#             # "--inconclusive"
#             "--force"
#             "--inline-suppr"
#             # "--suppressions-list=${CMAKE_SOURCE_DIR}/CppCheckSuppressions.txt"
#     )
# endif()



# if(NOT CMAKE_BUILD_TYPE)
#   set(CMAKE_BUILD_TYPE RELEASE CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
# endif()

add_executable(bde
  src/main.cpp
  src/bde.cpp
  src/config.cpp
)

# set(bde PROPERTIES LINKER_LANGUAGE CXX)


