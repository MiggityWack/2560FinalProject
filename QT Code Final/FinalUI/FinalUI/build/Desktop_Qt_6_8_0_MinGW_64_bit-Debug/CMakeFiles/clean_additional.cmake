# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FinalUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FinalUI_autogen.dir\\ParseCache.txt"
  "FinalUI_autogen"
  )
endif()
