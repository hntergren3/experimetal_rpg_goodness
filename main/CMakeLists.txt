add_executable(rpg main.cpp)
target_link_libraries(rpg battle)
install(TARGETS rpg DESTINATION bin)
