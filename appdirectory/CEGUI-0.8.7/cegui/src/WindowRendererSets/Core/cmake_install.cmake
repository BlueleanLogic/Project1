# Install script for directory: /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cegui-0.8/libCEGUICoreWindowRendererSet.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cegui-0.8/libCEGUICoreWindowRendererSet.so")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cegui-0.8/libCEGUICoreWindowRendererSet.so"
         RPATH "")
  ENDIF()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cegui-0.8" TYPE SHARED_LIBRARY FILES "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/lib/libCEGUICoreWindowRendererSet.so")
  IF(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cegui-0.8/libCEGUICoreWindowRendererSet.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cegui-0.8/libCEGUICoreWindowRendererSet.so")
    FILE(RPATH_REMOVE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cegui-0.8/libCEGUICoreWindowRendererSet.so")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cegui-0.8/libCEGUICoreWindowRendererSet.so")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cegui-0/CEGUI/WindowRendererSets/Core" TYPE FILE FILES
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/ItemListbox.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/MultiColumnList.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Menubar.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Static.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Button.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/TabControl.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/StaticImage.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/MenuItem.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Slider.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/ListHeaderSegment.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/FrameWindow.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Scrollbar.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Default.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Tree.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/PopupMenu.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/ProgressBar.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Module.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/ItemEntry.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Listbox.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Titlebar.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Editbox.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/ScrollablePane.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/ToggleButton.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/TabButton.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/MultiLineEditbox.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/ListHeader.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/StaticText.h"
    "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/cegui/src/WindowRendererSets/Core/../../../include/CEGUI/WindowRendererSets/Core/Tooltip.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

