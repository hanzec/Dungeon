ADD_SUBDIRECTORY(Display)

# add c file
aux_source_directory(. DIR_GAME_EXE_SRCS)
aux_source_directory(Utils/ DIR_UTILS_SRCS)
aux_source_directory(GameContent/ DIR_CHARACTERS_SRCS)
aux_source_directory(Utils/data_stucture DIR_UTILS_DS_SRCS)

#add boost lib
find_package(Boost CONFIG REQUIRED COMPONENTS filesystem log)
include_directories(${Boost_INCLUDE_DIRS})

#sdl2 dependency
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#ser project wide include
include_directories("${CMAKE_SOURCE_DIR}/include/")

# add RapidJson Dependency
include_directories("${CMAKE_SOURCE_DIR}/thirdparty/rapidjson/include")


add_executable(Dungeon ${DIR_UTILS_SRCS} ${DIR_CHARACTERS_SRCS} ${DIR_UTILS_DS_SRCS} ${DIR_GAME_EXE_SRCS} GameEventFactory.cpp ../include/GameEventFactory.h ../include/GameContant/GameObjects/Terrain.h GameContent/GameObjects/Terrain.cpp GameContent/GameObjects/Item.cpp ../include/GameContant/GameObjects/Item.h)

target_link_libraries(Dungeon libdisplay-sdl2 libdisplay-ncurses Boost::filesystem Boost::log)
