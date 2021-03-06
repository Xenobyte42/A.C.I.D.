cmake_minimum_required(VERSION 3.12)
project(A.C.I.D.)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest)
include_directories (
        include
        include/framework/test
        include/framework
        include/framework/test
)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR} )

##############################
set (
        FRAMEWORK_HDRS

        include/framework/i_system.h
        include/framework/active_system.h
        include/framework/reactive_system.h
        include/framework/game_loop.h
        include/framework/entity.h
        include/framework/entity_life_queue.h
        include/framework/i_component.h
        include/framework/i_node.h
        include/framework/node.h
        include/framework/i_observable.h
        include/framework/i_observer.h
        include/framework/entity_manager.h
        include/framework/node_manager.h
        include/framework/i_singleton.h
        include/framework/proxy_singleton_observer.h
        include/framework/base_system.h
        include/framework/entity_life_system.h
        include/framework/terminator_system.h
)

set (
        TEST_FRAMEWORK_HDRS

        include/framework/test/test_node.h
        include/framework/test/test_icomponent.h
        include/framework/test/test_node_manager.h
        include/framework/test/test_entity.h
        include/framework/test/test_activesystems_cycle.h
        include/framework/test/test_reactivesystems_cycle.h
)

set (
        FRAMEWORK_SRCS

        src/framework/i_node.cpp
        src/framework/entity.cpp
        src/framework/entity_manager.cpp
        src/framework/node_manager.cpp
        src/framework/i_component.cpp
        src/framework/game_loop.cpp
        src/framework/entity_life_queue.cpp
)

set (
        TEST_FRAMEWORK_SRC

        src/framework/test/test_node.cpp
        src/framework/test/test_icomponent.cpp
        src/framework/test/test_node_manager.cpp
        src/framework/test/test_entity.cpp
        src/framework/test/test_activesystems_cycle.cpp
        src/framework/test/test_reactivesystems_cycle.cpp
)

set (FRAMEWORK ${FRAMEWORK_HDRS} ${FRAMEWORK_SRCS})

set (TEST_FRAMEWORK ${TEST_FRAMEWORK_HDRS} ${TEST_FRAMEWORK_SRC})
##############################


##############################
set (
        HDRS

        include/input_system.h
        include/input_component.h
        include/input_node.h
        include/graphic_node.h
        include/texture_component.h
        include/graphic_manager.h
        include/position_component.h
        include/graphic_system.h
        include/camera_system.h
        include/camera_node.h
        include/camera_component.h
        include/displayer_system.h
        include/input_move_system.h
        include/input_move_node.h
        include/input_move_component.h
        include/move_system.h
        include/move_node.h
)
set (
        SRCS

)
set (APP ${SRCS} ${HDRS})
##############################


add_executable(ACID src/main.cpp ${APP} ${FRAMEWORK})
add_executable(framework_test_example src/framework_test_example.cpp ${FRAMEWORK})
add_executable(framework_gtest src/framework/test/test.cpp ${FRAMEWORK} ${TEST_FRAMEWORK})
add_executable(input_test src/input_test.cpp ${APP} ${FRAMEWORK})
add_executable(graph_test src/graph_test.cpp ${APP} ${FRAMEWORK})

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(SFML 2 COMPONENTS graphics audio network window system REQUIRED)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})
target_link_libraries(framework_gtest gtest gtest_main pthread)
target_link_libraries(ACID ${SFML_LIBRARIES})
target_link_libraries(input_test ${SFML_LIBRARIES})
target_link_libraries(graph_test ${SFML_LIBRARIES})

target_link_libraries(framework_gtest gtest gtest_main gmock gmock_main pthread)