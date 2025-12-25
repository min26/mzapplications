# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)


set(BOARD_ROOT ${CMAKE_SOURCE_DIR}/..)
set(BOARD fmuk64f)


find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(button)

target_sources(app PRIVATE 
		src/m_button.c
		src/m_console.c
		src/main.c)

target_include_directories(app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

