cmake_minimum_required (VERSION 3.26)

project (demolib VERSION 1.2.3.4 LANGUAGES CXX)

add_library(demolib STATIC    
	demolib/demolib.cpp
)

add_library(demolib::demolib ALIAS demolib)

target_sources(demolib PUBLIC	
	FILE_SET 
		HEADERS
	FILES
		demolib/demolib.hpp
)

include(GNUInstallDirs)

install(
	TARGETS 
		demolib 
	EXPORT 
		demolib-targets	
	FILE_SET HEADERS
		DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	LIBRARY
		DESTINATION $<CONFIG>/${CMAKE_INSTALL_LIBDIR}
	ARCHIVE
		DESTINATION $<CONFIG>/${CMAKE_INSTALL_LIBDIR}
)

install(
	EXPORT 
		demolib-targets
	NAMESPACE 
		demolib::
	DESTINATION 
		share/cmake/demolib
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/demolib-config-version.cmake"
	COMPATIBILITY 
		AnyNewerVersion
)

configure_package_config_file(
	cmake/demolib-config.cmake.in
	demolib-config.cmake
	INSTALL_DESTINATION 
		share/cmake/demolib
)

install(
	FILES
		"${CMAKE_CURRENT_BINARY_DIR}/demolib-config.cmake"
		"${CMAKE_CURRENT_BINARY_DIR}/demolib-config-version.cmake"
	DESTINATION 
		share/cmake/demolib
)

