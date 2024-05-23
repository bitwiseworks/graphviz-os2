if(GD_FOUND)

  add_library(gvplugin_gd SHARED
    # Source files
    gdioctx_wrapper.h
    gdgen_text.h
    gd_psfontResolve.h
    gvdevice_gd.c
    gvloadimage_gd.c
    gvplugin_gd.c
    gvrender_gd.c
    gvrender_gd_vrml.c
    gvtextlayout_gd.c
  )

  target_include_directories(gvplugin_gd PRIVATE
    ../../lib
    ${CMAKE_CURRENT_SOURCE_DIR}
    ../../lib/cdt
    ../../lib/cgraph
    ../../lib/common
    ../../lib/gvc
    ../../lib/pathplan
  )

  target_include_directories(gvplugin_gd SYSTEM PRIVATE
    ${GD_INCLUDE_DIRS}
  )

  target_link_libraries(gvplugin_gd PRIVATE
    cgraph
    gvc
    pathplan
    ${GD_LIBRARIES}
  )

  if(CAIRO_FOUND)
    target_include_directories(gvplugin_gd SYSTEM PRIVATE
      ${CAIRO_INCLUDE_DIRS}
    )
    target_link_libraries(gvplugin_gd PRIVATE
      ${CAIRO_LINK_LIBRARIES}
    )
    if(PANGOCAIRO_FOUND)
      target_include_directories(gvplugin_gd SYSTEM PRIVATE
        ${PANGOCAIRO_INCLUDE_DIRS}
      )

      target_link_libraries(gvplugin_gd PRIVATE
        ${PANGOCAIRO_LINK_LIBRARIES}
      )
    endif()
  endif()

  # Installation location of library files
  install(
    TARGETS gvplugin_gd
    RUNTIME DESTINATION ${BINARY_INSTALL_DIR}
    LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIBRARY_INSTALL_DIR}
  )

  # Include DLLs with this library on Windows
  if(WIN32 AND install_win_dependency_dlls)
    install(
      FILES
        ${GD_RUNTIME_LIBRARIES}
      DESTINATION ${BINARY_INSTALL_DIR}
    )
  endif()

  # Specify library version and soversion
  set_target_properties(gvplugin_gd PROPERTIES
    VERSION ${GRAPHVIZ_PLUGIN_VERSION}.0.0
    SOVERSION ${GRAPHVIZ_PLUGIN_VERSION}
  )

  if(OS2)
    get_target_property(plug_name gvplugin_gd NAME)
    get_target_property(plug_so ${plug_name} SOVERSION)
    get_target_property(plug_ver ${plug_name} VERSION)
    set(plug_shortname "gvplggd")
    set_target_properties(${plug_name} PROPERTIES
        OS2_DEF_VENDOR "$ENV{VENDOR}"
        OS2_DEF_PATCH "0"
        OS2_DEF_VERSION "${plug_ver}"
        TARGET_SHORT ${plug_shortname})
    add_custom_target(sym_${plug_name} ALL COMMAND
        ${CMAKE_COMMAND} -E create_symlink ${plug_shortname}${plug_so}.dll ./${plug_name}.dll)
    INSTALL (FILES ${CMAKE_CURRENT_BINARY_DIR}/${plug_name}.dll DESTINATION ${PLUGIN_INSTALL_DIR})
  endif()

  if(MINGW)
    # work around https://gitlab.kitware.com/cmake/cmake/-/issues/21716
    set_target_properties(gvplugin_gd PROPERTIES
      RUNTIME_OUTPUT_NAME gvplugin_gd-${GRAPHVIZ_PLUGIN_VERSION}
    )
  endif()

endif()
