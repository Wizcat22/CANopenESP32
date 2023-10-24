# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "../components/micro_ros_espidf_component/esp32_toolchain.cmake"
  "../components/micro_ros_espidf_component/include"
  "../components/micro_ros_espidf_component/micro_ros_dev"
  "../components/micro_ros_espidf_component/micro_ros_src"
  )
endif()
