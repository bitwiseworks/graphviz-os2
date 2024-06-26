if(NOT with_gvedit STREQUAL "OFF")
  find_package(Qt6 COMPONENTS Core PrintSupport Widgets)
  if(Qt6_FOUND)
    set(QT_LIBS Qt6::Core Qt6::PrintSupport Qt6::Widgets)
  else()
    find_package(Qt5 COMPONENTS Core PrintSupport Widgets)
    if(Qt5_FOUND)
      set(QT_LIBS Qt5::Core Qt5::PrintSupport Qt5::Widgets)
    endif()
  endif()
  if(with_gvedit STREQUAL "AUTO")
    # suppress complaints about `with_gvedit` casing
    # cmake-lint: disable=C0103
    if(Qt6_FOUND)
      message(STATUS "setting -Dwith_gvedit=ON with Qt6")
      set(with_gvedit ON)
    elseif(Qt5_FOUND)
      message(STATUS "setting -Dwith_gvedit=ON with Qt5")
      set(with_gvedit ON)
    else()
      message(STATUS "setting -Dwith_gvedit=OFF")
      set(with_gvedit OFF)
    endif()
  elseif(NOT Qt6_FOUND AND NOT Qt5_FOUND)
    message(FATAL_ERROR "-Dwith_gvedit=ON and neither Qt5 nor Qt6 found")
  endif()
endif()

if(with_gvedit)
  add_executable(gvedit
    csettings.cpp
    imageviewer.cpp
    main.cpp
    mainwindow.cpp
    mdi.qrc
    mdichild.cpp
  )

  set_target_properties(gvedit PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    AUTOUIC ON
    AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui"
  )

  target_compile_definitions(gvedit PRIVATE DEMAND_LOADING=1)

  target_include_directories(gvedit PRIVATE
    ../../lib
    ../../lib/cdt
    ../../lib/cgraph
    ../../lib/common
    ../../lib/gvc
    ../../lib/pathplan
  )

  target_link_libraries(gvedit PRIVATE
    cdt
    cgraph
    gvc
  )

  target_link_libraries(gvedit PRIVATE ${QT_LIBS})

  if(EXPAT_FOUND)
    target_include_directories(gvedit SYSTEM PRIVATE ${EXPAT_INCLUDE_DIRS})
    target_link_libraries(gvedit PRIVATE ${EXPAT_LIBRARIES})
  endif()

  if(OS2)
    set_target_properties(gvedit PROPERTIES
      OS2_DEF_VENDOR "$ENV{VENDOR}"
      OS2_DEF_PATCH "${GRAPHVIZ_VERSION_PATCH}"
      OS2_DEF_VERSION "${GRAPHVIZ_VERSION_FULL}")
  endif()

  install(
    TARGETS gvedit
    RUNTIME DESTINATION ${BINARY_INSTALL_DIR}
    LIBRARY DESTINATION ${LIBRARY_INSTALL_DIR}
    ARCHIVE DESTINATION ${LIBRARY_INSTALL_DIR}
  )

  install(
    FILES ../../doc/infosrc/attrs
    DESTINATION ${DATA_INSTALL_DIR}/graphviz/gvedit
    RENAME attrs.txt
  )

  if(GZIP)
    add_custom_target(man-gvedit ALL DEPENDS gvedit.1.gz
                      COMMENT "gvedit man page")
    add_custom_command(
      OUTPUT gvedit.1.gz
      COMMAND ${GZIP} -9 --no-name --to-stdout gvedit.1
        >"${CMAKE_CURRENT_BINARY_DIR}/gvedit.1.gz"
      MAIN_DEPENDENCY gvedit.1
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "compress gvedit man page")
    install(
      FILES ${CMAKE_CURRENT_BINARY_DIR}/gvedit.1.gz
      DESTINATION ${MAN_INSTALL_DIR}/man1)
  else()
    install(
      FILES gvedit.1
      DESTINATION ${MAN_INSTALL_DIR}/man1
    )
  endif()
endif()
