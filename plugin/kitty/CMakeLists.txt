if(PANGOCAIRO_FOUND)
  add_library(gvplugin_kitty SHARED gvdevice_kitty.c gvplugin_kitty.c)

  target_include_directories(gvplugin_kitty PRIVATE
    ../../lib
    ../../lib/cdt
    ../../lib/cgraph
    ../../lib/common
    ../../lib/gvc
    ../../lib/pathplan
  )

  if(ZLIB_FOUND)
    target_include_directories(gvplugin_kitty SYSTEM PRIVATE
      ${ZLIB_INCLUDE_DIRS}
    )
    target_link_libraries(gvplugin_kitty PUBLIC
      ${ZLIB_LIBRARIES}
    )
  endif()

  install(
    TARGETS gvplugin_kitty
    RUNTIME DESTINATION ${BINARY_INSTALL_DIR}
    LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIBRARY_INSTALL_DIR}
  )

  set_target_properties(gvplugin_kitty PROPERTIES
    VERSION ${GRAPHVIZ_PLUGIN_VERSION}.0.0
    SOVERSION ${GRAPHVIZ_PLUGIN_VERSION}
  )

  if(OS2)
    get_target_property(plug_name gvplugin_kitty NAME)
    get_target_property(plug_so ${plug_name} SOVERSION)
    get_target_property(plug_ver ${plug_name} VERSION)
    set(plug_shortname "gvplgki")
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
    set_target_properties(gvplugin_kitty PROPERTIES
      RUNTIME_OUTPUT_NAME gvplugin_kitty-${GRAPHVIZ_PLUGIN_VERSION}
    )
  endif()
endif()
