cmake_minimum_required(VERSION 3.10)

# Remove when sharing with others.
list(APPEND CMAKE_PREFIX_PATH "/doc/src/qt/qt-creator/build-sys")

project(KommitQtCreatorPlugin)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(KF_MIN_VERSION "6.3.0")
set(KF_MAJOR_VERSION 6)
set(QT_MAJOR_VERSION 6)
set(QT_MIN_VERSION "6.4.0")

find_package(QtCreator REQUIRED COMPONENTS Core Widgets)
# find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(
    Qt6 ${QT_MIN_VERSION}
    CONFIG REQUIRED
        Core
        Widgets
        Concurrent
        Network
)


find_package(ECM REQUIRED NO_MODULE)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBGIT2 "libgit2>=1.0" REQUIRED IMPORTED_TARGET)
set(
    CMAKE_MODULE_PATH
    ${ECM_MODULE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/kommit/cmake
)
find_package(
    KF${KF_MAJOR_VERSION} ${KF_MIN_VERSION}
    REQUIRED COMPONENTS
        ConfigWidgets
        CoreAddons
        Crash
        DocTools
        I18n
        XmlGui
        KIO
        TextWidgets
        TextEditor
        SyntaxHighlighting
)


# include(KDECompilerSettings NO_POLICY_SCOPE)
# include(KDECMakeSettings NO_POLICY_SCOPE)
include(FeatureSummary)

# include(ECMInstallIcons)
include(ECMQtDeclareLoggingCategory)
# include(ECMAddAppIcon)
include(ECMSetupVersion)
# include(ECMAddTests)
include(GenerateExportHeader)
# include(KDEGitCommitHooks)
include(KDEClangFormat)
include(ECMDeprecationSettings)

set(QtX Qt${QT_VERSION_MAJOR})

# Add a CMake option that enables building your plugin with tests.
# You don't want your released plugin binaries to contain tests,
# so make that default to 'NO'.
# Enable tests by passing -DWITH_TESTS=ON to CMake.
option(WITH_TESTS "Builds with tests" NO)
add_subdirectory(3rdparty/kommit/src/libkommit)
add_subdirectory(3rdparty/kommit/src/libkommitdiff)
add_subdirectory(3rdparty/kommit/src/libkommitwidgets)

if(WITH_TESTS)
  # Look for QtTest
  find_package(${QtX} REQUIRED COMPONENTS Test)

  # Tell CMake functions like add_qtc_plugin about the QtTest component.
  set(IMPLICIT_DEPENDS Qt::Test)

  # Enable ctest for auto tests.
  enable_testing()
endif()

add_qtc_plugin(KommitQtCreatorPlugin
  PLUGIN_DEPENDS
    QtCreator::Core
  DEPENDS
    Qt::Core Qt::CorePrivate Qt::Widgets
    QtCreator::ExtensionSystem
    QtCreator::ProjectExplorer
    libkommit
    libkommitdiff
    libkommitwidgets
  SOURCES
    .github/workflows/build_cmake.yml
    .github/workflows/README.md
    README.md
    kommitqtcreatorplugin.cpp
    kommitqtcreatorplugin.h
    kommitqtcreatorplugin_global.h
    kommitqtcreatorpluginconstants.h
    kommitqtcreatorplugintr.h
    kommitsidebarfactory.h kommitsidebarfactory.cpp
    changedfilespane.h changedfilespane.cpp
    gitdata.h gitdata.cpp
    kommitsidebar.h kommitsidebar.cpp kommitsidebar.ui
)
