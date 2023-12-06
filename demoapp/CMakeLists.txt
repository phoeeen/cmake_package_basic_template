cmake_minimum_required (VERSION 3.26)

project(demoapp VERSION 4.3.2.1)

add_executable(demoapp 
	demoapp/demoapp.cpp 
)

target_sources(demoapp PRIVATE	 
	FILE_SET 
		HEADERS
	FILES
		demoapp/demoapp.hpp
)

find_package(demolib)
target_link_libraries(demoapp demolib::demolib)

