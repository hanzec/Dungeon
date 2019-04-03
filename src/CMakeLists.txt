ADD_SUBDIRECTORY(display)

# add c file
aux_source_directory(. DIR_GAME_EXE_SRCS)
aux_source_directory(utils/ DIR_UTILS_SRCS)
aux_source_directory(characters/ DIR_CHARACTERS_SRCS)
aux_source_directory(utils/data_stucture DIR_UTILS_DS_SRCS)

#add header file

add_executable(Dungeon main.cpp ${DIR_UTILS_SRCS} ${DIR_CHARACTERS_SRCS} ${DIR_UTILS_DS_SRCS} ${DIR_GAME_EXE_SRCS})

target_link_libraries(Dungeon DisplayLib)
