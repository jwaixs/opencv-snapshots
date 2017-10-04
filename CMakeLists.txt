cmake_minimum_required (VERSION 2.8.11)
project (png16bit)

find_package (OpenCV REQUIRED)

add_executable (convert_image convert_image.cpp)
target_link_libraries (convert_image ${OpenCV_LIBS})
