cmake_minimum_required(VERSION 3.30)
project(psp-wasm3-test LANGUAGES C)

add_library(m3 STATIC
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_api_libc.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_api_wasi.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_api_uvwasi.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_api_meta_wasi.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_api_tracer.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_bind.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_code.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_compile.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_core.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_env.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_exec.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_function.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_info.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_module.c
	${PROJECT_SOURCE_DIR}/wasm3/source/m3_parse.c
)

target_include_directories(m3 PUBLIC ${PROJECT_SOURCE_DIR}/wasm3/source/)
target_compile_features(m3 PRIVATE c_std_99)

add_executable(psp-wasm3-test
	${PROJECT_SOURCE_DIR}/main.c
)

target_link_libraries(psp-wasm3-test PRIVATE m3 pspdebug pspdisplay pspge)

if(PSP)
	create_pbp_file(
		TARGET psp-wasm3-test
		ICON_PATH NULL
		BACKGROUND_PATH NULL
		PREVIEW_PATH NULL
		TITLE psp-wasm3-test
		VERSION 01.00
	)
endif()

