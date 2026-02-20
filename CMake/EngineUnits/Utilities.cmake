set(UTILITIES_PROJECT_NAME RNGOEngine_Utilities)
add_library(${UTILITIES_PROJECT_NAME} STATIC
        include/Utilities/Singleton.h

        include/Utilities/UUID.h
        src/Utilities/UUID.cpp

        include/Utilities/EnumDefinitions.h
        include/Utilities/RNGOAsserts.h
)
target_include_directories(${UTILITIES_PROJECT_NAME} PUBLIC include)
target_link_libraries(${UTILITIES_PROJECT_NAME} PUBLIC
        magic_enum::magic_enum
)


