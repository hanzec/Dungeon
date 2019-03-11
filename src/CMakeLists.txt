ADD_SUBDIRECTORY(display)

# add character
aux_source_directory(utils/ DIR_UTILS_SRCS)
aux_source_directory(characters/ DIR_CHARACTERS_SRCS)
aux_source_directory(utils/data_stucture DIR_UTILS_DS_SRCS)


#add header file
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(Dungeon main.c ${DIR_UTILS_SRCS} ${DIR_CHARACTERS_SRCS} ${DIR_UTILS_DS_SRCS})

target_link_libraries(Dungeon DisplayLib)
