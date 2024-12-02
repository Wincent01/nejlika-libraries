set (SQLITE3_SOURCES
	"CppSQLite3.cpp"
	"sqlite3.c"
)

add_library (sqlite3 SHARED ${SQLITE3_SOURCES})

target_include_directories(sqlite3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(UNIX)
	# Add warning disable flags and link Unix libraries to sqlite3
	target_link_libraries(sqlite3 pthread dl m)

	#  -Wno-unused-result -Wno-unknown-pragmas -fpermissive
	target_compile_options(sqlite3 PRIVATE "-Wno-return-local-addr" "-Wno-maybe-uninitialized")
endif()
