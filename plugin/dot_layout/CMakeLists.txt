include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${GRAPHVIZ_LIB_DIR}/cdt
    ${GRAPHVIZ_LIB_DIR}/cgraph
    ${GRAPHVIZ_LIB_DIR}/common
    ${GRAPHVIZ_LIB_DIR}/gvc
    ${GRAPHVIZ_LIB_DIR}/pathplan
)

add_library(gvplugin_dot_layout SHARED
    # Source files
	gvplugin_dot_layout.c
	gvlayout_dot_layout.c
)

target_link_libraries(gvplugin_dot_layout
    cdt
    cgraph
    dotgen
    gvc
    pathplan
)

# Installation location of library files
install(
    TARGETS gvplugin_dot_layout
    RUNTIME DESTINATION ${BINARY_INSTALL_DIR}
    LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIBRARY_INSTALL_DIR}
)

# Specify library version and soversion
set_target_properties(gvplugin_dot_layout PROPERTIES
    VERSION ${GRAPHVIZ_PLUGIN_VERSION}.0.0
    SOVERSION ${GRAPHVIZ_PLUGIN_VERSION}
)

if(OS2)
    get_target_property(plug_name gvplugin_dot_layout NAME)
    get_target_property(plug_so ${plug_name} SOVERSION)
    get_target_property(plug_ver ${plug_name} VERSION)
    set(plug_shortname "gvplgdl")
    set_target_properties(${plug_name} PROPERTIES
        OS2_DEF_VENDOR "$ENV{VENDOR}"
        OS2_DEF_PATCH "0"
        OS2_DEF_VERSION "${plug_ver}"
        TARGET_SHORT ${plug_shortname})
    add_custom_target(sym_${plug_name} ALL COMMAND
        ${CMAKE_COMMAND} -E create_symlink ${plug_shortname}${plug_so}.dll ./${plug_name}.dll)
    INSTALL (FILES ${CMAKE_CURRENT_BINARY_DIR}/${plug_name}.dll DESTINATION ${PLUGIN_INSTALL_DIR})
endif()
