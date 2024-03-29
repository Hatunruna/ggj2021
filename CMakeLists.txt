cmake_minimum_required(VERSION 3.10)

set(GAME TheLostWill)

project(${GAME}
  VERSION 0.1.0
)

include(GNUInstallDirs)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/extras/cmake")

find_package(L10N)
find_package(gf REQUIRED COMPONENTS graphics)
find_package(Boost REQUIRED COMPONENTS locale)

if (UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
endif ()

add_subdirectory("data/raw/i18n")

set(GAME_DATADIR "${CMAKE_INSTALL_PREFIX}/share/games/${GAME}")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/code/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)

add_executable(${GAME}
  code/main.cc
  code/bits/BuildingEntity.cc
  code/bits/CharacterEntity.cc
  code/bits/DialogEntity.cc
  code/bits/DialogScene.cc
  code/bits/GameData.cc
  code/bits/GameHub.cc
  code/bits/GameState.cc
  code/bits/IntroductionScene.cc
  code/bits/LightEntity.cc
  code/bits/Plot.cc
  code/bits/SliderChallengeScene.cc
  code/bits/SliderEntity.cc
  code/bits/StartScene.cc
  code/bits/StoryEntity.cc
  code/bits/StreakChallengeScene.cc
  code/bits/TitleEntity.cc
  code/bits/WorldScene.cc
  code/bits/PlayerEntity.cc
  code/bits/StreakEntity.cc
  code/bits/MapEntity.cc
  code/bits/InfoEntity.cc
)

target_include_directories(${GAME}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/code
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${GAME}
  PRIVATE
    gf::graphics
    Boost::locale
)

install(
  TARGETS ${GAME}
  RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/data/${GAME}"
  DESTINATION "${CMAKE_INSTALL_DATAROOTDIR}/games"
)
