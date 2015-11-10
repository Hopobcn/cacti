
set(SOURCE_FILES
        arbiter.cc
        area.cc
        bank.cc
        basic_circuit.cc
        cacti_interface.cc
        component.cc
        crossbar.cc
        decoder.cc
        htree2.cc
        io.cc
        main.cc
        mat.cc
        nuca.cc
        parameter.cc
        router.cc
        subarray.cc
        technology.cc
        uca.cc
        Ucache.cc
        wire.cc)


add_executable(cacti ${SOURCE_FILES})