#========================================================================
#
# fofi/CMakeLists.txt
#
# CMake script for the fofi library.
#
# Copyright 2015 Glyph & Cog, LLC
#
#========================================================================

include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/goo")

add_library(fofi_objs OBJECT
  FoFiBase.cc
  FoFiEncodings.cc
  FoFiIdentifier.cc
  FoFiTrueType.cc
  FoFiType1.cc
  FoFiType1C.cc
)
set_property(TARGET fofi_objs
             PROPERTY POSITION_INDEPENDENT_CODE True)


add_library(fofi
  $<TARGET_OBJECTS:fofi_objs>
)
target_link_libraries(fofi PRIVATE goo)
