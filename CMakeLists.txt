cmake_minimum_required(VERSION 3.21)
project(LaserGUI LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# -------------------------------------------------------------
# 1. 尋找 VISA (使用 find_library 讓它自己找)
# -------------------------------------------------------------
find_library(VISA_LIB
    NAMES visa32 visa64
    PATHS
    "C:/Program Files (x86)/IVI Foundation/VISA/WinNT/lib/msc/x64" # 標準 MSVC 64-bit 路徑
    "C:/Program Files/IVI Foundation/VISA/Win64/Lib_x64/msc"
    DOC "VISA Library"
)

# 尋找 VISA Include
find_path(VISA_INCLUDE_DIR 
    NAMES visa.h vpptype.h
    PATHS
    "C:/Program Files (x86)/IVI Foundation/VISA/WinNT/include"
    "C:/Program Files/IVI Foundation/VISA/Win64/Include"
)

# -------------------------------------------------------------
# 2. 設定 TLPM 與 FTD2XX (先用變數存路徑，不強迫檢查)
# -------------------------------------------------------------
set(TLPM_LIB "${CMAKE_SOURCE_DIR}/3rdParty/TLPM/TLPM_64.lib")
set(FTD2XX_LIB "${CMAKE_SOURCE_DIR}/3rdParty/ftd2xx/ftd2xx.lib")

# -------------------------------------------------------------
# 3. 專案設定
# -------------------------------------------------------------
find_package(Qt6 REQUIRED COMPONENTS Widgets SerialPort Network Multimedia Concurrent)

# 設定你的 Source Files (維持你原本的設定)
set(GUI_SOURCES src/Gui/MainWindow.cpp src/Gui/Login.cpp src/Gui/Simulation.cpp src/Gui/StressTesting.cpp)
set(GUI_HEADERS src/Gui/MainWindow.h src/Gui/Login.h src/Gui/Simulation.h src/Gui/StressTesting.h)
set(GUI_FORMS   src/Gui/MainWindow.ui src/Gui/Login.ui src/Gui/Simulation.ui src/Gui/StressTesting.ui)
set(APP_SOURCES src/App/Automation.cpp src/App/ConnectDevice.cpp src/App/PowerCheck.cpp)
set(APP_HEADERS src/App/Automation.h src/App/ConnectDevice.h src/App/PowerCheck.h)

add_executable(LaserGUI src/main.cpp ${GUI_SOURCES} ${GUI_HEADERS} ${GUI_FORMS} ${APP_SOURCES} ${APP_HEADERS})

# Include 設定
target_include_directories(LaserGUI PRIVATE 
    src/Gui src/App 3rdParty/TLPM
    "${CMAKE_SOURCE_DIR}/3rdParty/ftd2xx"
    "${VISA_INCLUDE_DIR}"
    "${CMAKE_SOURCE_DIR}/eigen-5.0.0"
)

# Link 設定
target_link_libraries(LaserGUI PRIVATE
    Qt6::Widgets Qt6::SerialPort Qt6::Network Qt6::Multimedia Qt6::Concurrent
    "${VISA_LIB}"
    "${TLPM_LIB}"
    "${FTD2XX_LIB}"
)
