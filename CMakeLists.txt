cmake_minimum_required(VERSION 3.22)
project(cpp_2023_lab_01)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 14)

if (UNIX)
    # konfiguracja dla systemów Unix/Linux/MacOS
    # proszę nie modyfkować pierwszego wpisu, można dopisać kolejne katalogi
    # wpis dla antycznego Ubuntu (dla SFML 2.4)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULES_PATH})

    # katalog, w którym jest plik SFMLConfig.cmake
    # nowe Ubuntu (SFML 2.5)
    # NIE ZMIENIAĆ, NIE KASOWAĆ !!!
    set ( CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML" ${CMAKE_PREFIX_PATH})

    # dla MacOS lub innej dystrybucji Linuksa - można dopisać DODATKOWY CMAKE_PREFIX_PATH
    # set ( CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/SFML" ${CMAKE_PREFIX_PATH})
endif(UNIX)

if (WIN32)
    # próbujemy linkować statycznie (nie trzeba kopiować plików dll do katalogu projektu)
    set( SFML_STATIC_LIBRARIES TRUE )

    # Jeśli zainstalowaliście w innym miejscu to trzeba tu zmienić katalog na właściwy
    set ( SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)


find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

# tego brakuje !! To są opcje, których ja sam używam w moich programach
# te opcje muszą być ZAWSZE włączone
add_compile_options(-Wall -Wextra)

# chcemy, by nasz kod był w pełni zgodny ze standardem
add_compile_options(-pedantic)

# zmieniamy niektóre ostrzeżenia na błędy
# missing return in non-void function: “control reaches end of non-void function"
add_compile_options(-Werror=return-type)

# misleading parentheses - read here: https://www.ibm.com/docs/en/ztpf/1.1.0.14?topic=warnings-parentheses
add_compile_options(-Werror=parentheses)

# VLA is a non-standard feature of some c++ compilers - this prevents its usage
add_compile_options(-Werror=vla)

# detect some trivial array-bounds errors in code (only compile-time !!)
add_compile_options(-Werror=array-bounds)

# additional warnings
add_compile_options ( -Wcast-qual )
add_compile_options ( -Wmaybe-uninitialized )

add_executable(Saper main.cpp MinesweeperBoard.cpp MinesweeperBoard.h MSBoardTextView.cpp MSBoardTextView.h MSTextController.cpp MSTextController.h MSSFMLView.cpp MSSFMLView.h)
target_link_libraries(Saper sfml-graphics sfml-audio)
