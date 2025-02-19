# Install script for directory: /Users/cassm/src/openFrameworks 0.9.8/apps/myApps/ledCylinder

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs/libopenFrameworksStatic.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs" TYPE STATIC_LIBRARY FILES "/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs/libopenFrameworksStatic.a")
  if(EXISTS "$ENV{DESTDIR}/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs/libopenFrameworksStatic.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs/libopenFrameworksStatic.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs/libopenFrameworksStatic.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs/libopenFrameworksShared.dylib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs" TYPE SHARED_LIBRARY FILES "/Users/cassm/src/openFrameworks 0.9.8/apps/myApps/ledCylinder/bin/ledCylinder.app/Contents/Frameworks/libopenFrameworksShared.dylib")
  if(EXISTS "$ENV{DESTDIR}/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs/libopenFrameworksShared.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs/libopenFrameworksShared.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "$ENV{DESTDIR}/Users/cassm/src/openFrameworks 0.9.8/addons/ofxCMake/libs/libopenFrameworksShared.dylib")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/cassm/src/openFrameworks 0.9.8/apps/myApps/ledCylinder/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
