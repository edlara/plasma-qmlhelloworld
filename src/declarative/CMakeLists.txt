add_definitions(-DTRANSLATION_DOMAIN="helloworldgreeter")

set(plasmagreeter_qmlplugins_SRCS
   qmlplugins.cpp
   greeter.cpp
)

add_library(plasmagreeter_qmlplugins SHARED ${plasmagreeter_qmlplugins_SRCS})

target_link_libraries(plasmagreeter_qmlplugins
    Qt5::Core
    Qt5::Qml
    Qt5::DBus
    KF5::I18n
    KF5::CoreAddons
    KF5::Notifications
    KF5::IconThemes
    KF5::ConfigCore
)

install(TARGETS plasmagreeter_qmlplugins DESTINATION ${QML_INSTALL_DIR}/org/custom/plasma/HelloWorld)
install(FILES qmldir DESTINATION ${QML_INSTALL_DIR}/org/custom/plasma/HelloWorld)

# test binary
set(greeter_console_SRCS
   greeter.cpp
   main.cpp
)

add_executable(greeter-console ${greeter_console_SRCS})

target_link_libraries(greeter-console
    Qt5::Core
    Qt5::DBus
    KF5::I18n
    KF5::CoreAddons
    KF5::ConfigCore
    KF5::Notifications
    KF5::IconThemes
)
