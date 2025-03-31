cmake_minimum_required(VERSION 3.16)
project(TP10)

# List all exercices
file(GLOB exercice_folders "${CMAKE_CURRENT_SOURCE_DIR}/ex[0-9]*")
foreach(exercice_folder ${exercice_folders})
    get_filename_component(exercice_id ${exercice_folder} NAME_WE)
    
    # Collect the sources for each exercice
    file(GLOB_RECURSE exercice_src CONFIGURE_DEPENDS
        "${exercice_folder}/src/*.cpp"
        "${exercice_folder}/src/*.hpp"
        "${exercice_folder}/src/*.h"
    )

    set(sandbox_file "${exercice_folder}/src/sandbox.cpp")
    MESSAGE("${sandbox_file}")
    MESSAGE("${exercice_src}")
    list(FIND exercice_src "${sandbox_file}" _index)
    if (${_index} GREATER -1)
        MESSAGE("HELLO")
        add_executable("${exercice_id}-sandbox"
            ${exercice_src}
        )
        list(REMOVE_ITEM exercice_src "${exercice_folder}/src/sandbox.cpp")
    endif()

endforeach()