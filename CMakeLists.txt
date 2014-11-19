project(3d_viewer)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories( ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/glm)

# Opencv required
find_package(OpenCV REQUIRED)
include_directories(${OPENCV_INCLUDE_DIRS})
link_directories(${OPENCV_LIBRARY_DIRS})
add_definitions(${OPENCV_DEFINITIONS})

message("\n\nFound OpenCV\n\n")

# OpenGL required
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
   MESSAGE("OpenGL Correctly Found")
   include_directories(${OPENGL_INCLUDE_DIR})
else (OPENGL_FOUND)
   MESSAGE("OpenGL environment missing")
endif (OPENGL_FOUND)

# QT4 required
find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

message("\n\nFound QT4\n\n")


INCLUDE_DIRECTORIES(${QT_QTOPENGL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} )

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


file(GLOB VIEWER_SOURCES src/*.cpp)

file(GLOB VIEWER_INCLUDES include/*.h)


# set QT headers
SET(QT_HEADERS
    include/mainwindow.h
    include/glwidget.h
    )

#set QT forms
SET(QT_FORMS
    ui/mainwindow.ui
)

# create moc for QT
QT4_WRAP_CPP(QT_MOC ${QT_HEADERS})

# process ui
QT4_WRAP_UI(QT_FORMS_HEADERS ${QT_FORMS})

ADD_EXECUTABLE(3d_viewer ${VIEWER_SOURCES} ${VIEWER_INCLUDES}
    ${QT_HEADERS}
    ${QT_MOC}
    ${QT_FORMS})

TARGET_LINK_LIBRARIES(3d_viewer ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${QT_LIBRARIES} ${OpenCV_LIBS})
