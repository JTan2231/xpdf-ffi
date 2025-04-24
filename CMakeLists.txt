#========================================================================
#
# cmake-xpdf.txt
#
# CMake script for the Xpdf package.
#
# Copyright 2021 Glyph & Cog, LLC
#
#========================================================================

cmake_minimum_required(VERSION 2.8.12)

project(xpdf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_USE_CXX11_ABI=0")
# Force older GLIBC compatibility
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_FORTIFY_SOURCE=2 -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FORTIFY_SOURCE=2 -O2")

include(cmake-config.txt)

add_subdirectory(goo)
add_subdirectory(fofi)
add_subdirectory(splash)
add_subdirectory(xpdf)
add_subdirectory(xpdf-qt)

if (NOT HAVE_FREETYPE_H)
  message(WARNING "Couldn't find FreeType -- will not build pdftoppm, pdftopng, pdftohtml, or xpdf.")
endif ()

if (NOT PNG_FOUND)
  message(WARNING "Couldn't find libpng -- will not build pdftopng or pdftohtml.")
endif ()

if (NOT QT4_FOUND AND NOT Qt5Widgets_FOUND AND NOT Qt6Widgets_FOUND)
  message(WARNING "Couldn't find Qt4/5/6 -- will not build xpdf.")
endif ()

if (NOT MULTITHREADED)
  message(WARNING "Multithreading is disabled -- will not build xpdf.")
endif ()

if (NOT USE_EXCEPTIONS)
  message(WARNING "C++ exceptions are disabled -- will not build xpdf.")
endif ()
