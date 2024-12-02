# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5)

# C++ 20
set(CMAKE_CXX_STANDARD 20)

# Set the project name
project(core)

# Add an executable target
add_library(core SHARED
    "Configuration.cpp"
    "Database.cpp"
    "nejlika.cpp"
    "Lookup.cpp"
    "AbstractMod.cpp"
    "Localization.cpp"
    "Locale.cpp"
    "Manifest.cpp"
    "ModPack.cpp"
    "Mods.cpp"
    "Artifacts.cpp"
    "ModResources.cpp"
    "JsonUtilities.cpp"
    "TypeTemplate.cpp"
    "TypeTemplateParameter.cpp"
    "TypeTemplateValidator.cpp"
    "TypeTemplateError.cpp"
    "TypeTemplateScope.cpp"
    "TypeTemplateValue.cpp"
    "TypeTemplateContext.cpp"
    "TypeTemplateApplier.cpp"
    "TypeTemplateAction.cpp"
    "TypeTemplateWrapper.cpp"
    "TypeTemplateCollection.cpp"
    "TypeTemplateInterface.cpp"
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost REQUIRED COMPONENTS json)
find_package(ZLIB REQUIRED)

# Link to sqlite3, boost::json, tinyxml2, openssl, boost::uuid
target_link_libraries(core
    common
    sqlite3
    tinyxml2
    ssl
    crypto
    ${ZLIB_LIBRARIES}
    ${Boost_LIBRARIES}
)