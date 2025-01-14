# The module defines the following variables
#
#  LXQT_SHARE_DIR     - This allows to install and read the configs from non-standard locations
#
#  LXQT_TRANSLATIONS_DIR - The default translations directory
#
#  LXQT_ETC_XDG_DIR   - XDG standards expects system-wide configuration files in the
#                        /etc/xdg/lxqt location. Unfortunately QSettings we are using internally
#                        can be overriden in the Qt compilation time to use different path for
#                        system-wide configs. (for example configure ... -sysconfdir /etc/settings ...)
#                        This path can be found calling Qt's qmake:
#                             qmake -query QT_INSTALL_CONFIGURATION
#
#  LXQT_DATA_DIR      - LXQt base directory relative to which data files should
#                       be searched.Defaults to CMAKE_INSTALL_FULL_DATADIR. It's
#                       added to XDG_DATA_DIRS by the startlxqt script.


set(LXQT_LIBRARY_NAME "lxqt")
set(LXQT_RELATIVE_SHARE_DIR "lxqt")
set(LXQT_SHARE_DIR          "/usr/local/share/lxqt")
set(LXQT_RELATIVE_TRANSLATIONS_DIR "lxqt/translations")
set(LXQT_TRANSLATIONS_DIR   "/usr/local/share/lxqt/translations")
set(LXQT_GRAPHICS_DIR       "/usr/local/share/lxqt/graphics")
set(LXQT_ETC_XDG_DIR        "/etc/xdg")
set(LXQT_DATA_DIR           "/usr/local/share")

add_definitions("-DLXQT_RELATIVE_SHARE_DIR=\"${LXQT_RELATIVE_SHARE_DIR}\"")
add_definitions("-DLXQT_SHARE_DIR=\"${LXQT_SHARE_DIR}\"")
add_definitions("-DLXQT_RELATIVE_SHARE_TRANSLATIONS_DIR=\"${LXQT_RELATIVE_TRANSLATIONS_DIR}\"")
add_definitions("-DLXQT_SHARE_TRANSLATIONS_DIR=\"${LXQT_TRANSLATIONS_DIR}\"")
add_definitions("-DLXQT_GRAPHICS_DIR=\"${LXQT_GRAPHICS_DIR}\"")
add_definitions("-DLXQT_ETC_XDG_DIR=\"${LXQT_ETC_XDG_DIR}\"")
add_definitions("-DLXQT_DATA_DIR=\"${LXQT_DATA_DIR}\"")
