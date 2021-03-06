cmake_minimum_required (VERSION 2.8)
project (YogiAccountManager)

cmake_policy (SET CMP0022 OLD)
if (${CMAKE_MAJOR_VERSION} GREATER 2)
    cmake_policy (SET CMP0038 NEW)
endif ()

if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "^arm.*$")
    link_directories (/usr/lib/arm-linux-gnueabihf)
endif ()

set (Boost_USE_STATIC_LIBS        OFF)
set (Boost_USE_MULTITHREADED      ON)
set (Boost_USE_STATIC_RUNTIME     OFF)
find_package (Boost 1.54 COMPONENTS system log log_setup filesystem thread program_options REQUIRED)
find_package (Threads)
find_package (Protobuf 3.0.0 REQUIRED)

set (ignored_warnings        "-Wno-unused-variable -Wno-unused-function -Wno-overloaded-virtual -Wno-unused-value")
set (CMAKE_CXX_FLAGS         "-std=c++14 -Wall -Werror ${ignored_warnings} -DBOOST_ALL_DYN_LINK")
set (CMAKE_CXX_FLAGS_DEBUG   "-g")
set (CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

include_directories (${Boost_INCLUDE_DIRS})
include_directories (${PROTOBUF_INCLUDE_DIRS})
file (GLOB_RECURSE src_files src/*.cc src/*.cpp src/*.h src/*.hh src/*.hpp)

#===== build executable =====
add_executable (yogi-account-manager ${src_files})
target_link_libraries (yogi-account-manager yogi yogi_core ${Boost_LIBRARIES} ${PROTOBUF_LITE_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

#===== tests =====
enable_testing ()

file (GLOB_RECURSE files ${PROJECT_SOURCE_DIR}/tests/test_*.py)
foreach (file ${files})
    file (RELATIVE_PATH rel_file ${PROJECT_SOURCE_DIR} ${file})
    get_filename_component (name ${file} NAME_WE)

    add_test (NAME ${name} COMMAND python3 ${file})
endforeach ()

#===== install =====
install (
    TARGETS yogi-account-manager
    DESTINATION /usr/bin
)

install (
    FILES yogi-account-manager.json
    DESTINATION /etc
)

install (
    FILES yogi-accounts.json
    DESTINATION /etc
    PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ
)

install (
    FILES yogi-account-manager.sh
    DESTINATION /etc/init.d
    RENAME yogi-account-manager
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ
)
