# cmake_package_basic_template
Basic cmake package example providing 2 cmake projects.

`demolib` produces a cmake package. Can be build and installed with single- and multi-config generatos.

`demoapp` consumes demolib via find_package. Can be build with single- and multi-config generators.

It is possible to mix single- and multi-config generators for producing and consuming the package (same compiler for stable ABI assumend).

## build and install demolib with multi config generator
    cmake -B build_multi -S .

    cmake --build build_multi --config Debug
    cmake --install build_multi --config Debug --prefix ..\installs\demolib-1.2.3.4-multi

    cmake --build build_multi --config Release    
    cmake --install build_multi --config Release --prefix ..\installs\demolib-1.2.3.4-multi

## build and install demolib with single config generator
    cmake -B build_single_debug -S . -G Ninja -DCMAKE_BUILD_TYPE=Debug
    cmake --build build_single_debug
    cmake --install build_single_debug --prefix ..\installs\demolib-1.2.3.4-single

    cmake -B build_single_release -S . -G Ninja -DCMAKE_BUILD_TYPE=Release
    cmake --build build_single_release
    cmake --install build_single_release --prefix ..\installs\demolib-1.2.3.4-single

## build demoapp multi config generator
    cmake -B build -S . --install-prefix <your absolute install prefix>

    cmake --build build --config Debug
    cmake --build build --config Release

## build demoapp single config generator
    cmake -B build_ninja_debug -S . -G Ninja -DCMAKE_BUILD_TYPE=Debug --install-prefix <your absolute install prefix>
    cmake --build build_ninja_debug

    cmake -B build_ninja_release -S . -G Ninja -DCMAKE_BUILD_TYPE=Release --install-prefix <your absolute install prefix>    
    cmake --build build_ninja_release