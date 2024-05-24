if(WEBP_FOUND)

  add_library(gvplugin_webp SHARED
    gvplugin_webp.c
    gvloadimage_webp.c
    gvdevice_webp.c
  )

  target_include_directories(gvplugin_webp PRIVATE
    ../../lib
    ../../lib/cdt
    ../../lib/cgraph
    ../../lib/common
    ../../lib/gvc
    ../../lib/pathplan
  )

  target_include_directories(gvplugin_webp SYSTEM PRIVATE
    ${WEBP_INCLUDE_DIRS}
  )

  target_link_libraries(gvplugin_webp PRIVATE
    gvc
    ${WEBP_LINK_LIBRARIES}
  )

  if(CAIRO_FOUND)
    target_include_directories(gvplugin_webp SYSTEM PRIVATE
      ${CAIRO_INCLUDE_DIRS}
    )
    target_link_libraries(gvplugin_webp PRIVATE
      ${CAIRO_LINK_LIBRARIES}
    )
    if(PANGOCAIRO_FOUND)
      target_include_directories(gvplugin_webp SYSTEM PRIVATE
        ${PANGOCAIRO_INCLUDE_DIRS}
      )

      target_link_libraries(gvplugin_webp PRIVATE
        ${PANGOCAIRO_LINK_LIBRARIES}
      )
    endif()
  endif()

  install(
    TARGETS gvplugin_webp
    RUNTIME DESTINATION ${BINARY_INSTALL_DIR}
    LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIBRARY_INSTALL_DIR}
  )

  set_target_properties(gvplugin_webp PROPERTIES
    VERSION ${GRAPHVIZ_PLUGIN_VERSION}.0.0
    SOVERSION ${GRAPHVIZ_PLUGIN_VERSION}
  )

  if(OS2)
    get_target_property(plug_name gvplugin_webp NAME)
    get_target_property(plug_so ${plug_name} SOVERSION)
    get_target_property(plug_ver ${plug_name} VERSION)
    set(plug_shortname "gvplgwp")
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
    set_target_properties(gvplugin_webp PROPERTIES
      RUNTIME_OUTPUT_NAME gvplugin_webp-${GRAPHVIZ_PLUGIN_VERSION}
    )
  endif()

endif()
