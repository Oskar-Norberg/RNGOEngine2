set(THREADING_PROJECT_NAME RNGOEngine_Threading)
add_library(${THREADING_PROJECT_NAME} INTERFACE
        include/Utilities/Threading/Runnable.h
        include/Utilities/Threading/SharedExecutionContext.h
)
target_include_directories(${THREADING_PROJECT_NAME} INTERFACE include)
target_link_libraries(${THREADING_PROJECT_NAME} INTERFACE
        ${CORE_UTILS}
)
