set(ERROR_PROJECT_NAME RNGOEngine_Error)
add_library(${ERROR_PROJECT_NAME} INTERFACE
        include/Error/Error.h
)
target_include_directories(${ERROR_PROJECT_NAME} INTERFACE include)
target_link_libraries(${ERROR_PROJECT_NAME} INTERFACE
        ${LOGGING_PROJECT_NAME}
        ${UTILITIES_PROJECT_NAME}
)
