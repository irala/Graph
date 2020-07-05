# CMake generated Testfile for 
# Source directory: /home/nuria/Graph/build/NLOHMANN-prefix/src/NLOHMANN/test/cmake_import_minver
# Build directory: /home/nuria/Graph/build/NLOHMANN-prefix/src/NLOHMANN-build/test/cmake_import_minver
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cmake_import_minver_configure "/usr/bin/cmake" "-G" "Unix Makefiles" "-A" "" "-DCMAKE_CXX_COMPILER=/usr/bin/clang++" "-Dnlohmann_json_DIR=/home/nuria/Graph/build/NLOHMANN-prefix/src/NLOHMANN-build" "/home/nuria/Graph/build/NLOHMANN-prefix/src/NLOHMANN/test/cmake_import_minver/project")
set_tests_properties(cmake_import_minver_configure PROPERTIES  FIXTURES_SETUP "cmake_import_minver")
add_test(cmake_import_minver_build "/usr/bin/cmake" "--build" ".")
set_tests_properties(cmake_import_minver_build PROPERTIES  FIXTURES_REQUIRED "cmake_import_minver")
