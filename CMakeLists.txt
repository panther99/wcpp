cmake_minimum_required(VERSION "3.27.6")

project("wcpp")

add_executable("${PROJECT_NAME}"
	wcpp/args.cpp
	wcpp/File.cpp
	wcpp/InputManager.cpp
	wcpp/InputSource.cpp
	wcpp/Main.cpp
)

target_include_directories("${PROJECT_NAME}" PRIVATE "wcpp")

set_property(TARGET "${PROJECT_NAME}"
	PROPERTY
		CXX_STANDARD 20
)
