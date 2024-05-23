add_library(gvplugin_core SHARED
  # Header files
  ps.h

  # Source files
  gvloadimage_core.c
  gvplugin_core.c
  gvrender_core_dot.c
  gvrender_core_json.c
  gvrender_core_fig.c
  gvrender_core_map.c
  gvrender_core_mp.c
  gvrender_core_pic.c
  gvrender_core_pov.c
  gvrender_core_ps.c
  gvrender_core_svg.c
  gvrender_core_tk.c
)

target_include_directories(gvplugin_core PRIVATE
  ../../lib
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ../../lib/cdt
  ../../lib/cgraph
  ../../lib/common
  ../../lib/gvc
  ../../lib/gvpr
  ../../lib/pathplan
  ../../lib/xdot
)

target_link_libraries(gvplugin_core PRIVATE
  cgraph
  gvc
  xdot
)

# Installation location of library files
install(
  TARGETS gvplugin_core
  RUNTIME DESTINATION ${BINARY_INSTALL_DIR}
  LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR}
  ARCHIVE DESTINATION ${LIBRARY_INSTALL_DIR}
)

# Specify library version and soversion
set_target_properties(gvplugin_core PROPERTIES
  VERSION ${GRAPHVIZ_PLUGIN_VERSION}.0.0
  SOVERSION ${GRAPHVIZ_PLUGIN_VERSION}
)

if(OS2)
    get_target_property(plug_name gvplugin_core NAME)
    get_target_property(plug_so ${plug_name} SOVERSION)
    get_target_property(plug_ver ${plug_name} VERSION)
    set(plug_shortname "gvplgco")
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
  set_target_properties(gvplugin_core PROPERTIES
    RUNTIME_OUTPUT_NAME gvplugin_core-${GRAPHVIZ_PLUGIN_VERSION}
  )
endif()
