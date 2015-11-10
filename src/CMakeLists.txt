
set(SOURCE_FILES
        arbiter.cpp
        area.cpp
        bank.cpp
        basic_circuit.cpp
        cacti_interface.cpp
        component.cpp
        crossbar.cpp
        decoder.cpp
        htree2.cpp
        io.cpp
        main.cpp
        mat.cpp
        nuca.cpp
        parameter.cpp
        router.cpp
        subarray.cpp
        technology.cpp
        uca.cpp
        Ucache.cpp
        wire.cpp)


add_executable(cacti ${SOURCE_FILES})
target_link_libraries(cacti ${CMAKE_THREAD_LIBS_INIT})