#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "DemLibrary" for configuration "Debug"
set_property(TARGET DemLibrary APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(DemLibrary PROPERTIES
  IMPORTED_IMPLIB_DEBUG "D:/project/cpp_dem_get/install/lib/libDemLibrary.dll.a"
  IMPORTED_LOCATION_DEBUG "D:/project/cpp_dem_get/install/bin/libDemLibrary.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS DemLibrary )
list(APPEND _IMPORT_CHECK_FILES_FOR_DemLibrary "D:/project/cpp_dem_get/install/lib/libDemLibrary.dll.a" "D:/project/cpp_dem_get/install/bin/libDemLibrary.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
