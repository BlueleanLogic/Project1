# Install script for directory: /v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/cegui-0.8.7/samples

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cegui-0/samples" TYPE FILE FILES "/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/datafiles/samples/samples.xml")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/HelloWorld/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/LookNFeelOverview/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/GameMenu/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/HUDDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/DragDropDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/InventoryDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/EffectsDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/FontDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/Demo6/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/EditboxValidationDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/Minesweeper/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/ScrollablePaneDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/TabControlDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/CommonDialogsDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/WidgetDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/TextDemo/cmake_install.cmake")
  INCLUDE("/v/filer4b/v38q001/madrigal/classes/cs354R/Project1/appdirectory/CEGUI-0.8.7/samples/TreeDemo/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

