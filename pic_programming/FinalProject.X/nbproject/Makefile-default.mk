#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/FinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/FinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../CKCommon/UART/uart.c main.c ../Communication.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c ../Communication.X/cmake-build-debug/CMakeFiles/feature_tests.c ../Communication.X/send_receive_messages.c ../Communication.X/create_normal_message.c ../Statemachines.X/statemachine_airquality_control.c ../Statemachines.X/statemachine_airtemp_control.c ../Statemachines.X/statemachine_watertemp_control.c ../Statemachines.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c ../Statemachines.X/cmake-build-debug/CMakeFiles/feature_tests.c ../Statemachines.X/statemachine_light_control.c ../Schedules.X/desiredValues.c ../Schedules.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c ../Schedules.X/cmake-build-debug/CMakeFiles/feature_tests.c ../Schedules.X/schedules.c ../Timer_Clock.X/hallClock.c ../Timer_Clock.X/timer_libs.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o ${OBJECTDIR}/_ext/1906753243/feature_tests.o ${OBJECTDIR}/_ext/1508717009/send_receive_messages.o ${OBJECTDIR}/_ext/1508717009/create_normal_message.o ${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o ${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o ${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o ${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o ${OBJECTDIR}/_ext/124734772/feature_tests.o ${OBJECTDIR}/_ext/473942824/statemachine_light_control.o ${OBJECTDIR}/_ext/1223356855/desiredValues.o ${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o ${OBJECTDIR}/_ext/1324847285/feature_tests.o ${OBJECTDIR}/_ext/1223356855/schedules.o ${OBJECTDIR}/_ext/2140114641/hallClock.o ${OBJECTDIR}/_ext/2140114641/timer_libs.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1062335525/uart.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o.d ${OBJECTDIR}/_ext/1906753243/feature_tests.o.d ${OBJECTDIR}/_ext/1508717009/send_receive_messages.o.d ${OBJECTDIR}/_ext/1508717009/create_normal_message.o.d ${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o.d ${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o.d ${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o.d ${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o.d ${OBJECTDIR}/_ext/124734772/feature_tests.o.d ${OBJECTDIR}/_ext/473942824/statemachine_light_control.o.d ${OBJECTDIR}/_ext/1223356855/desiredValues.o.d ${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o.d ${OBJECTDIR}/_ext/1324847285/feature_tests.o.d ${OBJECTDIR}/_ext/1223356855/schedules.o.d ${OBJECTDIR}/_ext/2140114641/hallClock.o.d ${OBJECTDIR}/_ext/2140114641/timer_libs.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o ${OBJECTDIR}/_ext/1906753243/feature_tests.o ${OBJECTDIR}/_ext/1508717009/send_receive_messages.o ${OBJECTDIR}/_ext/1508717009/create_normal_message.o ${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o ${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o ${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o ${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o ${OBJECTDIR}/_ext/124734772/feature_tests.o ${OBJECTDIR}/_ext/473942824/statemachine_light_control.o ${OBJECTDIR}/_ext/1223356855/desiredValues.o ${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o ${OBJECTDIR}/_ext/1324847285/feature_tests.o ${OBJECTDIR}/_ext/1223356855/schedules.o ${OBJECTDIR}/_ext/2140114641/hallClock.o ${OBJECTDIR}/_ext/2140114641/timer_libs.o

# Source Files
SOURCEFILES=../CKCommon/UART/uart.c main.c ../Communication.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c ../Communication.X/cmake-build-debug/CMakeFiles/feature_tests.c ../Communication.X/send_receive_messages.c ../Communication.X/create_normal_message.c ../Statemachines.X/statemachine_airquality_control.c ../Statemachines.X/statemachine_airtemp_control.c ../Statemachines.X/statemachine_watertemp_control.c ../Statemachines.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c ../Statemachines.X/cmake-build-debug/CMakeFiles/feature_tests.c ../Statemachines.X/statemachine_light_control.c ../Schedules.X/desiredValues.c ../Schedules.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c ../Schedules.X/cmake-build-debug/CMakeFiles/feature_tests.c ../Schedules.X/schedules.c ../Timer_Clock.X/hallClock.c ../Timer_Clock.X/timer_libs.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/FinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1062335525/uart.o: ../CKCommon/UART/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1062335525" 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1062335525/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1062335525/uart.o.d" -o ${OBJECTDIR}/_ext/1062335525/uart.o ../CKCommon/UART/uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o: ../Communication.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/818924089" 
	@${RM} ${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o.d 
	@${RM} ${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o.d" -o ${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o ../Communication.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1906753243/feature_tests.o: ../Communication.X/cmake-build-debug/CMakeFiles/feature_tests.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1906753243" 
	@${RM} ${OBJECTDIR}/_ext/1906753243/feature_tests.o.d 
	@${RM} ${OBJECTDIR}/_ext/1906753243/feature_tests.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1906753243/feature_tests.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1906753243/feature_tests.o.d" -o ${OBJECTDIR}/_ext/1906753243/feature_tests.o ../Communication.X/cmake-build-debug/CMakeFiles/feature_tests.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1508717009/send_receive_messages.o: ../Communication.X/send_receive_messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1508717009" 
	@${RM} ${OBJECTDIR}/_ext/1508717009/send_receive_messages.o.d 
	@${RM} ${OBJECTDIR}/_ext/1508717009/send_receive_messages.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1508717009/send_receive_messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1508717009/send_receive_messages.o.d" -o ${OBJECTDIR}/_ext/1508717009/send_receive_messages.o ../Communication.X/send_receive_messages.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1508717009/create_normal_message.o: ../Communication.X/create_normal_message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1508717009" 
	@${RM} ${OBJECTDIR}/_ext/1508717009/create_normal_message.o.d 
	@${RM} ${OBJECTDIR}/_ext/1508717009/create_normal_message.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1508717009/create_normal_message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1508717009/create_normal_message.o.d" -o ${OBJECTDIR}/_ext/1508717009/create_normal_message.o ../Communication.X/create_normal_message.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o: ../Statemachines.X/statemachine_airquality_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/473942824" 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o.d" -o ${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o ../Statemachines.X/statemachine_airquality_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o: ../Statemachines.X/statemachine_airtemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/473942824" 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o.d" -o ${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o ../Statemachines.X/statemachine_airtemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o: ../Statemachines.X/statemachine_watertemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/473942824" 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o.d" -o ${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o ../Statemachines.X/statemachine_watertemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o: ../Statemachines.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2056437792" 
	@${RM} ${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o.d 
	@${RM} ${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o.d" -o ${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o ../Statemachines.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/124734772/feature_tests.o: ../Statemachines.X/cmake-build-debug/CMakeFiles/feature_tests.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/124734772" 
	@${RM} ${OBJECTDIR}/_ext/124734772/feature_tests.o.d 
	@${RM} ${OBJECTDIR}/_ext/124734772/feature_tests.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/124734772/feature_tests.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/124734772/feature_tests.o.d" -o ${OBJECTDIR}/_ext/124734772/feature_tests.o ../Statemachines.X/cmake-build-debug/CMakeFiles/feature_tests.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/473942824/statemachine_light_control.o: ../Statemachines.X/statemachine_light_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/473942824" 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_light_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_light_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/473942824/statemachine_light_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/473942824/statemachine_light_control.o.d" -o ${OBJECTDIR}/_ext/473942824/statemachine_light_control.o ../Statemachines.X/statemachine_light_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1223356855/desiredValues.o: ../Schedules.X/desiredValues.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1223356855" 
	@${RM} ${OBJECTDIR}/_ext/1223356855/desiredValues.o.d 
	@${RM} ${OBJECTDIR}/_ext/1223356855/desiredValues.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1223356855/desiredValues.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1223356855/desiredValues.o.d" -o ${OBJECTDIR}/_ext/1223356855/desiredValues.o ../Schedules.X/desiredValues.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o: ../Schedules.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/895878433" 
	@${RM} ${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o.d 
	@${RM} ${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o.d" -o ${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o ../Schedules.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1324847285/feature_tests.o: ../Schedules.X/cmake-build-debug/CMakeFiles/feature_tests.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1324847285" 
	@${RM} ${OBJECTDIR}/_ext/1324847285/feature_tests.o.d 
	@${RM} ${OBJECTDIR}/_ext/1324847285/feature_tests.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1324847285/feature_tests.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1324847285/feature_tests.o.d" -o ${OBJECTDIR}/_ext/1324847285/feature_tests.o ../Schedules.X/cmake-build-debug/CMakeFiles/feature_tests.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1223356855/schedules.o: ../Schedules.X/schedules.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1223356855" 
	@${RM} ${OBJECTDIR}/_ext/1223356855/schedules.o.d 
	@${RM} ${OBJECTDIR}/_ext/1223356855/schedules.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1223356855/schedules.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1223356855/schedules.o.d" -o ${OBJECTDIR}/_ext/1223356855/schedules.o ../Schedules.X/schedules.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2140114641/hallClock.o: ../Timer_Clock.X/hallClock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2140114641" 
	@${RM} ${OBJECTDIR}/_ext/2140114641/hallClock.o.d 
	@${RM} ${OBJECTDIR}/_ext/2140114641/hallClock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2140114641/hallClock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2140114641/hallClock.o.d" -o ${OBJECTDIR}/_ext/2140114641/hallClock.o ../Timer_Clock.X/hallClock.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2140114641/timer_libs.o: ../Timer_Clock.X/timer_libs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2140114641" 
	@${RM} ${OBJECTDIR}/_ext/2140114641/timer_libs.o.d 
	@${RM} ${OBJECTDIR}/_ext/2140114641/timer_libs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2140114641/timer_libs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2140114641/timer_libs.o.d" -o ${OBJECTDIR}/_ext/2140114641/timer_libs.o ../Timer_Clock.X/timer_libs.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1062335525/uart.o: ../CKCommon/UART/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1062335525" 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1062335525/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1062335525/uart.o.d" -o ${OBJECTDIR}/_ext/1062335525/uart.o ../CKCommon/UART/uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o: ../Communication.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/818924089" 
	@${RM} ${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o.d 
	@${RM} ${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o.d" -o ${OBJECTDIR}/_ext/818924089/CMakeCCompilerId.o ../Communication.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1906753243/feature_tests.o: ../Communication.X/cmake-build-debug/CMakeFiles/feature_tests.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1906753243" 
	@${RM} ${OBJECTDIR}/_ext/1906753243/feature_tests.o.d 
	@${RM} ${OBJECTDIR}/_ext/1906753243/feature_tests.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1906753243/feature_tests.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1906753243/feature_tests.o.d" -o ${OBJECTDIR}/_ext/1906753243/feature_tests.o ../Communication.X/cmake-build-debug/CMakeFiles/feature_tests.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1508717009/send_receive_messages.o: ../Communication.X/send_receive_messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1508717009" 
	@${RM} ${OBJECTDIR}/_ext/1508717009/send_receive_messages.o.d 
	@${RM} ${OBJECTDIR}/_ext/1508717009/send_receive_messages.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1508717009/send_receive_messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1508717009/send_receive_messages.o.d" -o ${OBJECTDIR}/_ext/1508717009/send_receive_messages.o ../Communication.X/send_receive_messages.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1508717009/create_normal_message.o: ../Communication.X/create_normal_message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1508717009" 
	@${RM} ${OBJECTDIR}/_ext/1508717009/create_normal_message.o.d 
	@${RM} ${OBJECTDIR}/_ext/1508717009/create_normal_message.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1508717009/create_normal_message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1508717009/create_normal_message.o.d" -o ${OBJECTDIR}/_ext/1508717009/create_normal_message.o ../Communication.X/create_normal_message.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o: ../Statemachines.X/statemachine_airquality_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/473942824" 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o.d" -o ${OBJECTDIR}/_ext/473942824/statemachine_airquality_control.o ../Statemachines.X/statemachine_airquality_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o: ../Statemachines.X/statemachine_airtemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/473942824" 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o.d" -o ${OBJECTDIR}/_ext/473942824/statemachine_airtemp_control.o ../Statemachines.X/statemachine_airtemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o: ../Statemachines.X/statemachine_watertemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/473942824" 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o.d" -o ${OBJECTDIR}/_ext/473942824/statemachine_watertemp_control.o ../Statemachines.X/statemachine_watertemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o: ../Statemachines.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2056437792" 
	@${RM} ${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o.d 
	@${RM} ${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o.d" -o ${OBJECTDIR}/_ext/2056437792/CMakeCCompilerId.o ../Statemachines.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/124734772/feature_tests.o: ../Statemachines.X/cmake-build-debug/CMakeFiles/feature_tests.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/124734772" 
	@${RM} ${OBJECTDIR}/_ext/124734772/feature_tests.o.d 
	@${RM} ${OBJECTDIR}/_ext/124734772/feature_tests.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/124734772/feature_tests.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/124734772/feature_tests.o.d" -o ${OBJECTDIR}/_ext/124734772/feature_tests.o ../Statemachines.X/cmake-build-debug/CMakeFiles/feature_tests.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/473942824/statemachine_light_control.o: ../Statemachines.X/statemachine_light_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/473942824" 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_light_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/473942824/statemachine_light_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/473942824/statemachine_light_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/473942824/statemachine_light_control.o.d" -o ${OBJECTDIR}/_ext/473942824/statemachine_light_control.o ../Statemachines.X/statemachine_light_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1223356855/desiredValues.o: ../Schedules.X/desiredValues.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1223356855" 
	@${RM} ${OBJECTDIR}/_ext/1223356855/desiredValues.o.d 
	@${RM} ${OBJECTDIR}/_ext/1223356855/desiredValues.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1223356855/desiredValues.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1223356855/desiredValues.o.d" -o ${OBJECTDIR}/_ext/1223356855/desiredValues.o ../Schedules.X/desiredValues.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o: ../Schedules.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/895878433" 
	@${RM} ${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o.d 
	@${RM} ${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o.d" -o ${OBJECTDIR}/_ext/895878433/CMakeCCompilerId.o ../Schedules.X/cmake-build-debug/CMakeFiles/3.8.2/CompilerIdC/CMakeCCompilerId.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1324847285/feature_tests.o: ../Schedules.X/cmake-build-debug/CMakeFiles/feature_tests.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1324847285" 
	@${RM} ${OBJECTDIR}/_ext/1324847285/feature_tests.o.d 
	@${RM} ${OBJECTDIR}/_ext/1324847285/feature_tests.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1324847285/feature_tests.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1324847285/feature_tests.o.d" -o ${OBJECTDIR}/_ext/1324847285/feature_tests.o ../Schedules.X/cmake-build-debug/CMakeFiles/feature_tests.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1223356855/schedules.o: ../Schedules.X/schedules.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1223356855" 
	@${RM} ${OBJECTDIR}/_ext/1223356855/schedules.o.d 
	@${RM} ${OBJECTDIR}/_ext/1223356855/schedules.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1223356855/schedules.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1223356855/schedules.o.d" -o ${OBJECTDIR}/_ext/1223356855/schedules.o ../Schedules.X/schedules.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2140114641/hallClock.o: ../Timer_Clock.X/hallClock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2140114641" 
	@${RM} ${OBJECTDIR}/_ext/2140114641/hallClock.o.d 
	@${RM} ${OBJECTDIR}/_ext/2140114641/hallClock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2140114641/hallClock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2140114641/hallClock.o.d" -o ${OBJECTDIR}/_ext/2140114641/hallClock.o ../Timer_Clock.X/hallClock.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2140114641/timer_libs.o: ../Timer_Clock.X/timer_libs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2140114641" 
	@${RM} ${OBJECTDIR}/_ext/2140114641/timer_libs.o.d 
	@${RM} ${OBJECTDIR}/_ext/2140114641/timer_libs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2140114641/timer_libs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2140114641/timer_libs.o.d" -o ${OBJECTDIR}/_ext/2140114641/timer_libs.o ../Timer_Clock.X/timer_libs.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/FinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -DPK3OBPlatformTool=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/FinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=PK3OBPlatformTool=1,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/FinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/FinalProject.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/FinalProject.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
