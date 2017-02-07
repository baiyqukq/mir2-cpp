CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set(PROJECT_NAME mir2-cpp)

file(GLOB_RECURSE 
	SOURCES
	"src/*.cpp"
	)

file(GLOB_RECURSE
	HEADERS
	"src/*.h"
	)

INCLUDE_DIRECTORIES(
        "src"
        )

add_executable(${PROJECT_NAME}
	${HEADERS}
	${SOURCES}
	)


