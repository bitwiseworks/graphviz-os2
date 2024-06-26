if(CAIRO_FOUND AND PANGOCAIRO_FOUND)

  add_library(gvplugin_pango SHARED
    # Header files
    gvgetfontlist.h
    gvplugin_pango.h

    # Source files
    gvgetfontlist_pango.c
    gvloadimage_pango.c
    gvplugin_pango.c
    gvrender_pango.c
    gvtextlayout_pango.c
  )

  target_include_directories(gvplugin_pango PRIVATE
    ../../lib
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/lib/common
    ../../lib/cdt
    ../../lib/cgraph
    ../../lib/common
    ../../lib/gvc
    ../../lib/pathplan
  )

  target_include_directories(gvplugin_pango SYSTEM PRIVATE
    ${CAIRO_INCLUDE_DIRS}
    ${PANGOCAIRO_INCLUDE_DIRS}
  )

  target_link_libraries(gvplugin_pango PRIVATE
    cgraph
    gvc
    ${CAIRO_LINK_LIBRARIES}
    ${PANGOCAIRO_LINK_LIBRARIES}
  )

  # Installation location of library files
  install(
    TARGETS gvplugin_pango
    RUNTIME DESTINATION ${BINARY_INSTALL_DIR}
    LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIBRARY_INSTALL_DIR}
  )

  # Include DLLs with this library on Windows
  if(WIN32 AND install_win_dependency_dlls)
    install(
      FILES
          ${CAIRO_RUNTIME_LIBRARIES}
          ${PANGOCAIRO_RUNTIME_LIBRARIES}
      DESTINATION ${BINARY_INSTALL_DIR}
    )
  endif()

  # Specify library version and soversion
  set_target_properties(gvplugin_pango PROPERTIES
    VERSION ${GRAPHVIZ_PLUGIN_VERSION}.0.0
    SOVERSION ${GRAPHVIZ_PLUGIN_VERSION}
  )

  if(OS2)
    get_target_property(plug_name gvplugin_pango NAME)
    get_target_property(plug_so ${plug_name} SOVERSION)
    get_target_property(plug_ver ${plug_name} VERSION)
    set(plug_shortname "gvplgpa")
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
    set_target_properties(gvplugin_pango PROPERTIES
      RUNTIME_OUTPUT_NAME gvplugin_pango-${GRAPHVIZ_PLUGIN_VERSION}
    )
  endif()

endif()
