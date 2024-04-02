# Install script for directory: /home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0

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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/lxqt-build-tools" TYPE FILE FILES
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/build/install/lxqt-build-tools-config.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/build/lxqt-build-tools-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/lxqt-build-tools/find-modules" TYPE FILE FILES
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindClazy.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindExif.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindFontconfig.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindGLIB.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindMenuCache.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindUDev.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindXCB.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindXKBCommon.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindXTerm.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindXdgEmail.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindXdgMime.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindXdgOpen.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindXdgScreensaver.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindXdgSettings.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/find-modules/FindXdgUserDirs.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/lxqt-build-tools/modules" TYPE FILE FILES
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/ECMFindModuleHelpers.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtAppTranslationLoader.cpp.in"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtCompilerSettings.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtCreatePkgConfigFile.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtCreatePortableHeaders.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtLibTranslationLoader.cpp.in"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtPluginTranslationLoader.cpp.in"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtPreventInSourceBuilds.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtTranslate.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtTranslateDesktop.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtTranslationLoader.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/Qt5TranslationLoader.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/Qt5TranslationLoader.cpp.in"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/cmake/modules/LXQtTranslateDesktopYaml.pl"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/build/install/LXQtConfigVars.cmake"
    "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/build/install/LXQtTranslateTs.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/lxqt-transupdate")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/photinia/Documents/nav_assiant_sever_ws/nav_assiant/lxqt-build-tools-0.13.0/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
