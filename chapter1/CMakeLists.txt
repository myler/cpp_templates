file(GLOB srcs ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

foreach(src ${srcs})
  get_filename_component(case_name ${src} NAME_WE)
  add_executable(${case_name}.exe ${src})
  add_test(NAME test_${case_name} COMMAND ${case_name}.exe)
  set_tests_properties(test_${case_name} PROPERTIES TIMEOUT 30)
endforeach()
