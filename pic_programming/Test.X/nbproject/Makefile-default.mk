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
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
<<<<<<< HEAD
<<<<<<< HEAD
SOURCEFILES_QUOTED_IF_SPACED=main.c statemachine_airquality_control.c statemachine_airtemp_control.c statemachine_light_control.c statemachine_watertemp_control.c ../CKCommon/UART/uart.c ../clock_hall/hallClock.c ../timer_lib/timer_libs.c message.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/statemachine_airquality_control.o ${OBJECTDIR}/statemachine_airtemp_control.o ${OBJECTDIR}/statemachine_light_control.o ${OBJECTDIR}/statemachine_watertemp_control.o ${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/_ext/731469447/hallClock.o ${OBJECTDIR}/_ext/5158660/timer_libs.o ${OBJECTDIR}/message.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/statemachine_airquality_control.o.d ${OBJECTDIR}/statemachine_airtemp_control.o.d ${OBJECTDIR}/statemachine_light_control.o.d ${OBJECTDIR}/statemachine_watertemp_control.o.d ${OBJECTDIR}/_ext/1062335525/uart.o.d ${OBJECTDIR}/_ext/731469447/hallClock.o.d ${OBJECTDIR}/_ext/5158660/timer_libs.o.d ${OBJECTDIR}/message.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/statemachine_airquality_control.o ${OBJECTDIR}/statemachine_airtemp_control.o ${OBJECTDIR}/statemachine_light_control.o ${OBJECTDIR}/statemachine_watertemp_control.o ${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/_ext/731469447/hallClock.o ${OBJECTDIR}/_ext/5158660/timer_libs.o ${OBJECTDIR}/message.o

# Source Files
SOURCEFILES=main.c statemachine_airquality_control.c statemachine_airtemp_control.c statemachine_light_control.c statemachine_watertemp_control.c ../CKCommon/UART/uart.c ../clock_hall/hallClock.c ../timer_lib/timer_libs.c message.c
=======
=======
<<<<<<< Updated upstream
>>>>>>> caad1c705d395c70f91eef302cc542fb7a33bbf5
SOURCEFILES_QUOTED_IF_SPACED=main.c statemachine_airquality_control.c statemachine_airtemp_control.c statemachine_light_control.c statemachine_watertemp_control.c ../CKCommon/UART/uart.c ../clock_hall/hallClock.c ../timer_lib/timer_libs.c update.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/statemachine_airquality_control.o ${OBJECTDIR}/statemachine_airtemp_control.o ${OBJECTDIR}/statemachine_light_control.o ${OBJECTDIR}/statemachine_watertemp_control.o ${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/_ext/731469447/hallClock.o ${OBJECTDIR}/_ext/5158660/timer_libs.o ${OBJECTDIR}/update.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/statemachine_airquality_control.o.d ${OBJECTDIR}/statemachine_airtemp_control.o.d ${OBJECTDIR}/statemachine_light_control.o.d ${OBJECTDIR}/statemachine_watertemp_control.o.d ${OBJECTDIR}/_ext/1062335525/uart.o.d ${OBJECTDIR}/_ext/731469447/hallClock.o.d ${OBJECTDIR}/_ext/5158660/timer_libs.o.d ${OBJECTDIR}/update.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/statemachine_airquality_control.o ${OBJECTDIR}/statemachine_airtemp_control.o ${OBJECTDIR}/statemachine_light_control.o ${OBJECTDIR}/statemachine_watertemp_control.o ${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/_ext/731469447/hallClock.o ${OBJECTDIR}/_ext/5158660/timer_libs.o ${OBJECTDIR}/update.o

# Source Files
SOURCEFILES=main.c statemachine_airquality_control.c statemachine_airtemp_control.c statemachine_light_control.c statemachine_watertemp_control.c ../CKCommon/UART/uart.c ../clock_hall/hallClock.c ../timer_lib/timer_libs.c update.c
<<<<<<< HEAD
>>>>>>> b181bf012ed1ea2ba113df33c9b343079075625c
=======
=======
SOURCEFILES_QUOTED_IF_SPACED=statemachine_airquality_control.c main.c statemachine_airtemp_control.c statemachine_light_control.c statemachine_watertemp_control.c ../CKCommon/UART/uart.c timer_libs.c ../clock_hall/hallClock.c struct_lib.c sr.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/statemachine_airquality_control.o ${OBJECTDIR}/main.o ${OBJECTDIR}/statemachine_airtemp_control.o ${OBJECTDIR}/statemachine_light_control.o ${OBJECTDIR}/statemachine_watertemp_control.o ${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/timer_libs.o ${OBJECTDIR}/_ext/731469447/hallClock.o ${OBJECTDIR}/struct_lib.o ${OBJECTDIR}/sr.o
POSSIBLE_DEPFILES=${OBJECTDIR}/statemachine_airquality_control.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/statemachine_airtemp_control.o.d ${OBJECTDIR}/statemachine_light_control.o.d ${OBJECTDIR}/statemachine_watertemp_control.o.d ${OBJECTDIR}/_ext/1062335525/uart.o.d ${OBJECTDIR}/timer_libs.o.d ${OBJECTDIR}/_ext/731469447/hallClock.o.d ${OBJECTDIR}/struct_lib.o.d ${OBJECTDIR}/sr.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/statemachine_airquality_control.o ${OBJECTDIR}/main.o ${OBJECTDIR}/statemachine_airtemp_control.o ${OBJECTDIR}/statemachine_light_control.o ${OBJECTDIR}/statemachine_watertemp_control.o ${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/timer_libs.o ${OBJECTDIR}/_ext/731469447/hallClock.o ${OBJECTDIR}/struct_lib.o ${OBJECTDIR}/sr.o

# Source Files
SOURCEFILES=statemachine_airquality_control.c main.c statemachine_airtemp_control.c statemachine_light_control.c statemachine_watertemp_control.c ../CKCommon/UART/uart.c timer_libs.c ../clock_hall/hallClock.c struct_lib.c sr.c
>>>>>>> Stashed changes
>>>>>>> caad1c705d395c70f91eef302cc542fb7a33bbf5


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/statemachine_airquality_control.o: statemachine_airquality_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/statemachine_airquality_control.o.d 
	@${RM} ${OBJECTDIR}/statemachine_airquality_control.o 
	@${FIXDEPS} "${OBJECTDIR}/statemachine_airquality_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/statemachine_airquality_control.o.d" -o ${OBJECTDIR}/statemachine_airquality_control.o statemachine_airquality_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/statemachine_airtemp_control.o: statemachine_airtemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/statemachine_airtemp_control.o.d 
	@${RM} ${OBJECTDIR}/statemachine_airtemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/statemachine_airtemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/statemachine_airtemp_control.o.d" -o ${OBJECTDIR}/statemachine_airtemp_control.o statemachine_airtemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/statemachine_light_control.o: statemachine_light_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/statemachine_light_control.o.d 
	@${RM} ${OBJECTDIR}/statemachine_light_control.o 
	@${FIXDEPS} "${OBJECTDIR}/statemachine_light_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/statemachine_light_control.o.d" -o ${OBJECTDIR}/statemachine_light_control.o statemachine_light_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/statemachine_watertemp_control.o: statemachine_watertemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/statemachine_watertemp_control.o.d 
	@${RM} ${OBJECTDIR}/statemachine_watertemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/statemachine_watertemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/statemachine_watertemp_control.o.d" -o ${OBJECTDIR}/statemachine_watertemp_control.o statemachine_watertemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1062335525/uart.o: ../CKCommon/UART/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1062335525" 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o 
<<<<<<< HEAD
	@${FIXDEPS} "${OBJECTDIR}/_ext/1062335525/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1062335525/uart.o.d" -o ${OBJECTDIR}/_ext/1062335525/uart.o ../CKCommon/UART/uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
=======
<<<<<<< Updated upstream
	@${FIXDEPS} "${OBJECTDIR}/_ext/1062335525/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1062335525/uart.o.d" -o ${OBJECTDIR}/_ext/1062335525/uart.o ../CKCommon/UART/uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
=======
	@${FIXDEPS} "${OBJECTDIR}/_ext/1062335525/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1062335525/uart.o.d" -o ${OBJECTDIR}/_ext/1062335525/uart.o ../CKCommon/UART/uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/timer_libs.o: timer_libs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer_libs.o.d 
	@${RM} ${OBJECTDIR}/timer_libs.o 
	@${FIXDEPS} "${OBJECTDIR}/timer_libs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer_libs.o.d" -o ${OBJECTDIR}/timer_libs.o timer_libs.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
>>>>>>> Stashed changes
>>>>>>> caad1c705d395c70f91eef302cc542fb7a33bbf5
	
${OBJECTDIR}/_ext/731469447/hallClock.o: ../clock_hall/hallClock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/731469447" 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o.d 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/731469447/hallClock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/731469447/hallClock.o.d" -o ${OBJECTDIR}/_ext/731469447/hallClock.o ../clock_hall/hallClock.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
<<<<<<< Updated upstream
${OBJECTDIR}/_ext/5158660/timer_libs.o: ../timer_lib/timer_libs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/5158660" 
	@${RM} ${OBJECTDIR}/_ext/5158660/timer_libs.o.d 
	@${RM} ${OBJECTDIR}/_ext/5158660/timer_libs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/5158660/timer_libs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/5158660/timer_libs.o.d" -o ${OBJECTDIR}/_ext/5158660/timer_libs.o ../timer_lib/timer_libs.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/message.o: message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/message.o.d 
	@${RM} ${OBJECTDIR}/message.o 
	@${FIXDEPS} "${OBJECTDIR}/message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DICD3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/message.o.d" -o ${OBJECTDIR}/message.o message.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/update.o: update.c  nbproject/Makefile-${CND_CONF}.mk
=======
${OBJECTDIR}/struct_lib.o: struct_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/struct_lib.o.d 
	@${RM} ${OBJECTDIR}/struct_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/struct_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/struct_lib.o.d" -o ${OBJECTDIR}/struct_lib.o struct_lib.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sr.o: sr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sr.o.d 
	@${RM} ${OBJECTDIR}/sr.o 
	@${FIXDEPS} "${OBJECTDIR}/sr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sr.o.d" -o ${OBJECTDIR}/sr.o sr.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/statemachine_airquality_control.o: statemachine_airquality_control.c  nbproject/Makefile-${CND_CONF}.mk
>>>>>>> Stashed changes
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/update.o.d 
	@${RM} ${OBJECTDIR}/update.o 
	@${FIXDEPS} "${OBJECTDIR}/update.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/update.o.d" -o ${OBJECTDIR}/update.o update.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/statemachine_airquality_control.o: statemachine_airquality_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/statemachine_airquality_control.o.d 
	@${RM} ${OBJECTDIR}/statemachine_airquality_control.o 
	@${FIXDEPS} "${OBJECTDIR}/statemachine_airquality_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/statemachine_airquality_control.o.d" -o ${OBJECTDIR}/statemachine_airquality_control.o statemachine_airquality_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/statemachine_airtemp_control.o: statemachine_airtemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/statemachine_airtemp_control.o.d 
	@${RM} ${OBJECTDIR}/statemachine_airtemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/statemachine_airtemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/statemachine_airtemp_control.o.d" -o ${OBJECTDIR}/statemachine_airtemp_control.o statemachine_airtemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/statemachine_light_control.o: statemachine_light_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/statemachine_light_control.o.d 
	@${RM} ${OBJECTDIR}/statemachine_light_control.o 
	@${FIXDEPS} "${OBJECTDIR}/statemachine_light_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/statemachine_light_control.o.d" -o ${OBJECTDIR}/statemachine_light_control.o statemachine_light_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/statemachine_watertemp_control.o: statemachine_watertemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/statemachine_watertemp_control.o.d 
	@${RM} ${OBJECTDIR}/statemachine_watertemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/statemachine_watertemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/statemachine_watertemp_control.o.d" -o ${OBJECTDIR}/statemachine_watertemp_control.o statemachine_watertemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1062335525/uart.o: ../CKCommon/UART/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1062335525" 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1062335525/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1062335525/uart.o.d" -o ${OBJECTDIR}/_ext/1062335525/uart.o ../CKCommon/UART/uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
<<<<<<< Updated upstream
=======
${OBJECTDIR}/timer_libs.o: timer_libs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/timer_libs.o.d 
	@${RM} ${OBJECTDIR}/timer_libs.o 
	@${FIXDEPS} "${OBJECTDIR}/timer_libs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/timer_libs.o.d" -o ${OBJECTDIR}/timer_libs.o timer_libs.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
>>>>>>> Stashed changes
${OBJECTDIR}/_ext/731469447/hallClock.o: ../clock_hall/hallClock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/731469447" 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o.d 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/731469447/hallClock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/731469447/hallClock.o.d" -o ${OBJECTDIR}/_ext/731469447/hallClock.o ../clock_hall/hallClock.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
<<<<<<< Updated upstream
${OBJECTDIR}/_ext/5158660/timer_libs.o: ../timer_lib/timer_libs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/5158660" 
	@${RM} ${OBJECTDIR}/_ext/5158660/timer_libs.o.d 
	@${RM} ${OBJECTDIR}/_ext/5158660/timer_libs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/5158660/timer_libs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/5158660/timer_libs.o.d" -o ${OBJECTDIR}/_ext/5158660/timer_libs.o ../timer_lib/timer_libs.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
<<<<<<< HEAD
${OBJECTDIR}/message.o: message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/message.o.d 
	@${RM} ${OBJECTDIR}/message.o 
	@${FIXDEPS} "${OBJECTDIR}/message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/message.o.d" -o ${OBJECTDIR}/message.o message.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
=======
${OBJECTDIR}/update.o: update.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/update.o.d 
	@${RM} ${OBJECTDIR}/update.o 
	@${FIXDEPS} "${OBJECTDIR}/update.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/update.o.d" -o ${OBJECTDIR}/update.o update.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
<<<<<<< HEAD
>>>>>>> b181bf012ed1ea2ba113df33c9b343079075625c
=======
=======
${OBJECTDIR}/struct_lib.o: struct_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/struct_lib.o.d 
	@${RM} ${OBJECTDIR}/struct_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/struct_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/struct_lib.o.d" -o ${OBJECTDIR}/struct_lib.o struct_lib.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sr.o: sr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/sr.o.d 
	@${RM} ${OBJECTDIR}/sr.o 
	@${FIXDEPS} "${OBJECTDIR}/sr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/sr.o.d" -o ${OBJECTDIR}/sr.o sr.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
>>>>>>> Stashed changes
>>>>>>> caad1c705d395c70f91eef302cc542fb7a33bbf5
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -DICD3PlatformTool=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=ICD3PlatformTool=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Test.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Test.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
