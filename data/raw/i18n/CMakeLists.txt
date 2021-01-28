set(TLW_LANGUAGES
  fr
)

if(L10N_FOUND)
  file(GLOB TLW_FILES
    CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/../../../code/bits/*.cc"
  )

  gettext_xgettext("TheLostWill"
    FILES ${TLW_FILES}
  )

  gettext_merge("TheLostWill.pot"
    ALL
    LANGUAGES ${TLW_LANGUAGES}
  )

  gettext_fmt("TheLostWill"
    ALL
    LANGUAGES ${TLW_LANGUAGES}
    INSTALL_DESTINATION "${CMAKE_INSTALL_LOCALEDIR}"
  )
endif()
