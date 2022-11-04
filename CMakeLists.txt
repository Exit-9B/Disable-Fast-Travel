cmake_minimum_required(VERSION 3.24)

project(
	DisableFastTravel
	VERSION 1.0.2
	LANGUAGES CXX
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

list(APPEND CMAKE_IGNORE_PATH "${PROJECT_BINARY_DIR}")
list(APPEND CMAKE_MODULE_PATH
	"${PROJECT_SOURCE_DIR}/tools/BethesdaCMakeModules/Modules"
	"${PROJECT_SOURCE_DIR}/tools/SKSE-CMakeModules/Modules"
)
include(SKSEPlugin)

set(SKSE_SUPPORT_XBYAK ON)

SKSEPlugin_Add(
	${PROJECT_NAME}
	SOURCE_DIR src
	SOURCES
		.clang-format
		.editorconfig
		README.md
		vcpkg.json
	PRECOMPILE_HEADERS
		src/PCH.h
)

install(
	FILES
		"${PROJECT_SOURCE_DIR}/data/${PROJECT_NAME}.ini"
	DESTINATION "SKSE/Plugins"
)

set(CPACK_GENERATOR "7Z")
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME}-${PROJECT_VERSION})
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY FALSE)
include(CPack)
