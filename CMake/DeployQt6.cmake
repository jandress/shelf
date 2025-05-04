#.rst:
# DeployQt6
# ---------
#
# Functions to help assemble a standalone Qt5 executable.
#
# A collection of CMake utility functions useful for deploying Qt5
# executables.
#
# The following functions are provided by this module:
#
# ::
#
#    write_qt5_conf
#    resolve_qt5_paths
#    fixup_qt5_executable
#    install_qt5_plugin_path
#    install_qt5_plugin
#    install_qt5_executable
#
# Requires CMake 2.8.9 or greater because Qt 5 does.
# Also depends on BundleUtilities.cmake.
#
# ::
#
#   WRITE_QT5_CONF(<qt_conf_dir> <qt_conf_contents>)
#
# Writes a qt.conf file with the <qt_conf_contents> into <qt_conf_dir>.
#
# ::
#
#   RESOLVE_QT5_PATHS(<paths_var> [<executable_path>])
#
# Loop through <paths_var> list and if any don't exist resolve them
# relative to the <executable_path> (if supplied) or the
# CMAKE_INSTALL_PREFIX.
#
# ::
#
#   FIXUP_QT5_EXECUTABLE(<executable> [<qtplugins> <libs> <dirs> <plugins_dir> <request_qt_conf>])
#
# Copies Qt plugins, writes a Qt configuration file (if needed) and
# fixes up a Qt5 executable using BundleUtilities so it is standalone
# and can be drag-and-drop copied to another machine as long as all of
# the system libraries are compatible.
#
# <executable> should point to the executable to be fixed-up.
#
# <qtplugins> should contain a list of the names or paths of any Qt
# plugins to be installed.
#
# <libs> will be passed to BundleUtilities and should be a list of any
# already installed plugins, libraries or executables to also be
# fixed-up.
#
# <dirs> will be passed to BundleUtilities and should contain and
# directories to be searched to find library dependencies.
#
# <plugins_dir> allows an custom plugins directory to be used.
#
# <request_qt_conf> will force a qt.conf file to be written even if not
# needed.
#
# ::
#
#   INSTALL_QT5_PLUGIN_PATH(plugin executable copy installed_plugin_path_var <plugins_dir> <component> <configurations>)
#
# Install (or copy) a resolved <plugin> to the default plugins directory
# (or <plugins_dir>) relative to <executable> and store the result in
# <installed_plugin_path_var>.
#
# If <copy> is set to TRUE then the plugins will be copied rather than
# installed.  This is to allow this module to be used at CMake time
# rather than install time.
#
# If <component> is set then anything installed will use this COMPONENT.
#
# ::
#
#   INSTALL_QT5_PLUGIN(plugin executable copy installed_plugin_path_var <plugins_dir> <component>)
#
# Install (or copy) an unresolved <plugin> to the default plugins
# directory (or <plugins_dir>) relative to <executable> and store the
# result in <installed_plugin_path_var>.  See documentation of
# INSTALL_QT5_PLUGIN_PATH.
#
# ::
#
#   INSTALL_QT5_EXECUTABLE(<executable> [<qtplugins> <libs> <dirs> <plugins_dir> <request_qt_conf> <component>])
#
# Installs Qt plugins, writes a Qt configuration file (if needed) and
# fixes up a Qt5 executable using BundleUtilities so it is standalone
# and can be drag-and-drop copied to another machine as long as all of
# the system libraries are compatible.  The executable will be fixed-up
# at install time.  <component> is the COMPONENT used for bundle fixup
# and plugin installation.  See documentation of FIXUP_QT5_BUNDLE.

#=============================================================================
# Copyright 2011 Mike McQuaid <mike@mikemcquaid.com>
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

# The functions defined in this file depend on the fixup_bundle function
# (and others) found in BundleUtilities.cmake
include(BundleUtilities)
include("${Qt6_DIR}/Qt6DeploySupport.cmake")

set(DeployQt6_cmake_dir "${CMAKE_CURRENT_LIST_DIR}")
set(DeployQt6_apple_plugins_dir "PlugIns")

function(write_qt_conf qt_conf_dir qt_conf_contents)
  set(qt_conf_path "${qt_conf_dir}/qt.conf")
  message(STATUS "Writing ${qt_conf_path}")
  file(WRITE "${qt_conf_path}" "${qt_conf_contents}")
endfunction()

function(resolve_qt_paths paths_var executable_path)
  set(paths_resolved)
  foreach(path ${${paths_var}})
    if(EXISTS "${path}")
      list(APPEND paths_resolved "${path}")
    else()
      if(${executable_path})
        list(APPEND paths_resolved "${executable_path}/${path}")
      else()
        list(APPEND paths_resolved "\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/${path}")
      endif()
    endif()
  endforeach()
  set(${paths_var} ${paths_resolved} PARENT_SCOPE)
endfunction()

function(fixup_qt6_executable executable)
  set(libs ${ARGV1})
  set(dirs ${ARGV2})
  set(plugins_dir ${ARGV3})
  set(request_qt_conf ${ARGV4})

  message(STATUS "Fixing up: ${executable}")
  message(STATUS "Libraries: ${libs}")

  if(APPLE)
    set(qt_conf_dir "${executable}/Contents/Resources")
    set(executable_path "${executable}")
    set(write_qt_conf TRUE)
    if(NOT plugins_dir)
      set(plugins_dir "${DeployQt6_apple_plugins_dir}")
    endif()
  else()
    get_filename_component(executable_path "${executable}" PATH)
    if(NOT executable_path)
      set(executable_path ".")
    endif()
    set(qt_conf_dir "${executable_path}")
    set(write_qt_conf ${request_qt_conf})
  endif()

  resolve_qt_paths(libs "${executable_path}")

  if(write_qt_conf)
    set(qt_conf_contents "[Paths]\nPlugins = ${plugins_dir}")
    write_qt_conf("${qt_conf_dir}" "${qt_conf_contents}")
  endif()

  fixup_bundle("${executable}" "${libs}" "${dirs}")
endfunction()

function(install_qt6_executable executable)
  set(libs ${ARGV0})
  set(dirs ${ARGV1})
  set(plugins_dir ${ARGV2})
  set(request_qt_conf ${ARGV3})
  set(component ${ARGV4})

  if(QT_LIBRARY_DIR)
    list(APPEND dirs "${QT_LIBRARY_DIR}")
  endif()
  if(QT_BINARY_DIR)
    list(APPEND dirs "${QT_BINARY_DIR}")
  endif()

  if(component)
    set(component COMPONENT ${component})
  else()
    unset(component)
  endif()

  get_filename_component(executable_absolute "${executable}" ABSOLUTE)

  # Automatically detect plugins via target dependencies
  message(STATUS "Importing Qt plugins for target: ${executable}")
  qt6_import_plugins(${executable})

  # Resolve library paths
  resolve_qt_paths(libs "")

  install(CODE "
    include(BundleUtilities)
    include(\"${DeployQt6_cmake_dir}/DeployQt6.cmake\")
    set(BU_CHMOD_BUNDLE_ITEMS TRUE)
    fixup_qt6_executable(\"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/${executable}\" \"${libs}\" \"${dirs}\" \"${plugins_dir}\" \"${request_qt_conf}\")
  " ${component})

  # Deploy runtime dependencies with Qt6 deploy API
  install(CODE "
    qt_deploy_runtime_dependencies(
      EXECUTABLE \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/${executable}\"
      LIB_DIR \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/lib\"
      PLUGIN_DIR \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/plugins\"
      QML_DIR \"\$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/qml\"
    )
  " ${component})
endfunction()
