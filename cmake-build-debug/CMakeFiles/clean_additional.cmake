# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "36_4_1_Three_colors_Circle_in_window_autogen"
  "CMakeFiles\\36_4_1_Three_colors_Circle_in_window_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\36_4_1_Three_colors_Circle_in_window_autogen.dir\\ParseCache.txt"
  )
endif()
