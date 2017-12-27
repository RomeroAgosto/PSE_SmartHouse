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
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../clock_hall/timer_libs.c ../CKCommon/UART/uart.c ../clock_hall/hallClock.c main.c adc_init.c desiredValues.c i2c.c update.c motion_detection.c temp_analog.c temp_digital.c ../statemachine/statemachine_airquality_control.c ../statemachine/statemachine_airtemp_control.c ../statemachine/statemachine_light_control.c ../statemachine/statemachine_watertemp_control.c send_receive_messages.c schedules.c create_normal_message.c actuators.c air_quality_level.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/731469447/timer_libs.o ${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/_ext/731469447/hallClock.o ${OBJECTDIR}/main.o ${OBJECTDIR}/adc_init.o ${OBJECTDIR}/desiredValues.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/update.o ${OBJECTDIR}/motion_detection.o ${OBJECTDIR}/temp_analog.o ${OBJECTDIR}/temp_digital.o ${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o ${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o ${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o ${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o ${OBJECTDIR}/send_receive_messages.o ${OBJECTDIR}/schedules.o ${OBJECTDIR}/create_normal_message.o ${OBJECTDIR}/actuators.o ${OBJECTDIR}/air_quality_level.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/731469447/timer_libs.o.d ${OBJECTDIR}/_ext/1062335525/uart.o.d ${OBJECTDIR}/_ext/731469447/hallClock.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/adc_init.o.d ${OBJECTDIR}/desiredValues.o.d ${OBJECTDIR}/i2c.o.d ${OBJECTDIR}/update.o.d ${OBJECTDIR}/motion_detection.o.d ${OBJECTDIR}/temp_analog.o.d ${OBJECTDIR}/temp_digital.o.d ${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o.d ${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o.d ${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o.d ${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o.d ${OBJECTDIR}/send_receive_messages.o.d ${OBJECTDIR}/schedules.o.d ${OBJECTDIR}/create_normal_message.o.d ${OBJECTDIR}/actuators.o.d ${OBJECTDIR}/air_quality_level.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/731469447/timer_libs.o ${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/_ext/731469447/hallClock.o ${OBJECTDIR}/main.o ${OBJECTDIR}/adc_init.o ${OBJECTDIR}/desiredValues.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/update.o ${OBJECTDIR}/motion_detection.o ${OBJECTDIR}/temp_analog.o ${OBJECTDIR}/temp_digital.o ${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o ${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o ${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o ${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o ${OBJECTDIR}/send_receive_messages.o ${OBJECTDIR}/schedules.o ${OBJECTDIR}/create_normal_message.o ${OBJECTDIR}/actuators.o ${OBJECTDIR}/air_quality_level.o

# Source Files
SOURCEFILES=../clock_hall/timer_libs.c ../CKCommon/UART/uart.c ../clock_hall/hallClock.c main.c adc_init.c desiredValues.c i2c.c update.c motion_detection.c temp_analog.c temp_digital.c ../statemachine/statemachine_airquality_control.c ../statemachine/statemachine_airtemp_control.c ../statemachine/statemachine_light_control.c ../statemachine/statemachine_watertemp_control.c send_receive_messages.c schedules.c create_normal_message.c actuators.c air_quality_level.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/731469447/timer_libs.o: ../clock_hall/timer_libs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/731469447" 
	@${RM} ${OBJECTDIR}/_ext/731469447/timer_libs.o.d 
	@${RM} ${OBJECTDIR}/_ext/731469447/timer_libs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/731469447/timer_libs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/731469447/timer_libs.o.d" -o ${OBJECTDIR}/_ext/731469447/timer_libs.o ../clock_hall/timer_libs.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1062335525/uart.o: ../CKCommon/UART/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1062335525" 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1062335525/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1062335525/uart.o.d" -o ${OBJECTDIR}/_ext/1062335525/uart.o ../CKCommon/UART/uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/731469447/hallClock.o: ../clock_hall/hallClock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/731469447" 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o.d 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/731469447/hallClock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/731469447/hallClock.o.d" -o ${OBJECTDIR}/_ext/731469447/hallClock.o ../clock_hall/hallClock.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/adc_init.o: adc_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc_init.o.d 
	@${RM} ${OBJECTDIR}/adc_init.o 
	@${FIXDEPS} "${OBJECTDIR}/adc_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/adc_init.o.d" -o ${OBJECTDIR}/adc_init.o adc_init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/desiredValues.o: desiredValues.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/desiredValues.o.d 
	@${RM} ${OBJECTDIR}/desiredValues.o 
	@${FIXDEPS} "${OBJECTDIR}/desiredValues.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/desiredValues.o.d" -o ${OBJECTDIR}/desiredValues.o desiredValues.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/i2c.o: i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	@${RM} ${OBJECTDIR}/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c.o.d" -o ${OBJECTDIR}/i2c.o i2c.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/update.o: update.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/update.o.d 
	@${RM} ${OBJECTDIR}/update.o 
	@${FIXDEPS} "${OBJECTDIR}/update.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/update.o.d" -o ${OBJECTDIR}/update.o update.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/motion_detection.o: motion_detection.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/motion_detection.o.d 
	@${RM} ${OBJECTDIR}/motion_detection.o 
	@${FIXDEPS} "${OBJECTDIR}/motion_detection.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/motion_detection.o.d" -o ${OBJECTDIR}/motion_detection.o motion_detection.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/temp_analog.o: temp_analog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/temp_analog.o.d 
	@${RM} ${OBJECTDIR}/temp_analog.o 
	@${FIXDEPS} "${OBJECTDIR}/temp_analog.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/temp_analog.o.d" -o ${OBJECTDIR}/temp_analog.o temp_analog.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/temp_digital.o: temp_digital.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/temp_digital.o.d 
	@${RM} ${OBJECTDIR}/temp_digital.o 
	@${FIXDEPS} "${OBJECTDIR}/temp_digital.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/temp_digital.o.d" -o ${OBJECTDIR}/temp_digital.o temp_digital.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o: ../statemachine/statemachine_airquality_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1570893445" 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o.d" -o ${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o ../statemachine/statemachine_airquality_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o: ../statemachine/statemachine_airtemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1570893445" 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o.d" -o ${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o ../statemachine/statemachine_airtemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o: ../statemachine/statemachine_light_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1570893445" 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o.d" -o ${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o ../statemachine/statemachine_light_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o: ../statemachine/statemachine_watertemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1570893445" 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o.d" -o ${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o ../statemachine/statemachine_watertemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/send_receive_messages.o: send_receive_messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/send_receive_messages.o.d 
	@${RM} ${OBJECTDIR}/send_receive_messages.o 
	@${FIXDEPS} "${OBJECTDIR}/send_receive_messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/send_receive_messages.o.d" -o ${OBJECTDIR}/send_receive_messages.o send_receive_messages.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/schedules.o: schedules.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/schedules.o.d 
	@${RM} ${OBJECTDIR}/schedules.o 
	@${FIXDEPS} "${OBJECTDIR}/schedules.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/schedules.o.d" -o ${OBJECTDIR}/schedules.o schedules.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/create_normal_message.o: create_normal_message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/create_normal_message.o.d 
	@${RM} ${OBJECTDIR}/create_normal_message.o 
	@${FIXDEPS} "${OBJECTDIR}/create_normal_message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/create_normal_message.o.d" -o ${OBJECTDIR}/create_normal_message.o create_normal_message.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/actuators.o: actuators.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/actuators.o.d 
	@${RM} ${OBJECTDIR}/actuators.o 
	@${FIXDEPS} "${OBJECTDIR}/actuators.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/actuators.o.d" -o ${OBJECTDIR}/actuators.o actuators.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/air_quality_level.o: air_quality_level.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/air_quality_level.o.d 
	@${RM} ${OBJECTDIR}/air_quality_level.o 
	@${FIXDEPS} "${OBJECTDIR}/air_quality_level.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/air_quality_level.o.d" -o ${OBJECTDIR}/air_quality_level.o air_quality_level.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/731469447/timer_libs.o: ../clock_hall/timer_libs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/731469447" 
	@${RM} ${OBJECTDIR}/_ext/731469447/timer_libs.o.d 
	@${RM} ${OBJECTDIR}/_ext/731469447/timer_libs.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/731469447/timer_libs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/731469447/timer_libs.o.d" -o ${OBJECTDIR}/_ext/731469447/timer_libs.o ../clock_hall/timer_libs.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1062335525/uart.o: ../CKCommon/UART/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1062335525" 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1062335525/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1062335525/uart.o.d" -o ${OBJECTDIR}/_ext/1062335525/uart.o ../CKCommon/UART/uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/731469447/hallClock.o: ../clock_hall/hallClock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/731469447" 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o.d 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/731469447/hallClock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/731469447/hallClock.o.d" -o ${OBJECTDIR}/_ext/731469447/hallClock.o ../clock_hall/hallClock.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/adc_init.o: adc_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc_init.o.d 
	@${RM} ${OBJECTDIR}/adc_init.o 
	@${FIXDEPS} "${OBJECTDIR}/adc_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/adc_init.o.d" -o ${OBJECTDIR}/adc_init.o adc_init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/desiredValues.o: desiredValues.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/desiredValues.o.d 
	@${RM} ${OBJECTDIR}/desiredValues.o 
	@${FIXDEPS} "${OBJECTDIR}/desiredValues.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/desiredValues.o.d" -o ${OBJECTDIR}/desiredValues.o desiredValues.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/i2c.o: i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	@${RM} ${OBJECTDIR}/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/i2c.o.d" -o ${OBJECTDIR}/i2c.o i2c.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/update.o: update.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/update.o.d 
	@${RM} ${OBJECTDIR}/update.o 
	@${FIXDEPS} "${OBJECTDIR}/update.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/update.o.d" -o ${OBJECTDIR}/update.o update.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/motion_detection.o: motion_detection.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/motion_detection.o.d 
	@${RM} ${OBJECTDIR}/motion_detection.o 
	@${FIXDEPS} "${OBJECTDIR}/motion_detection.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/motion_detection.o.d" -o ${OBJECTDIR}/motion_detection.o motion_detection.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/temp_analog.o: temp_analog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/temp_analog.o.d 
	@${RM} ${OBJECTDIR}/temp_analog.o 
	@${FIXDEPS} "${OBJECTDIR}/temp_analog.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/temp_analog.o.d" -o ${OBJECTDIR}/temp_analog.o temp_analog.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/temp_digital.o: temp_digital.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/temp_digital.o.d 
	@${RM} ${OBJECTDIR}/temp_digital.o 
	@${FIXDEPS} "${OBJECTDIR}/temp_digital.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/temp_digital.o.d" -o ${OBJECTDIR}/temp_digital.o temp_digital.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o: ../statemachine/statemachine_airquality_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1570893445" 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o.d" -o ${OBJECTDIR}/_ext/1570893445/statemachine_airquality_control.o ../statemachine/statemachine_airquality_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o: ../statemachine/statemachine_airtemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1570893445" 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o.d" -o ${OBJECTDIR}/_ext/1570893445/statemachine_airtemp_control.o ../statemachine/statemachine_airtemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o: ../statemachine/statemachine_light_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1570893445" 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o.d" -o ${OBJECTDIR}/_ext/1570893445/statemachine_light_control.o ../statemachine/statemachine_light_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o: ../statemachine/statemachine_watertemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1570893445" 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o.d" -o ${OBJECTDIR}/_ext/1570893445/statemachine_watertemp_control.o ../statemachine/statemachine_watertemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/send_receive_messages.o: send_receive_messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/send_receive_messages.o.d 
	@${RM} ${OBJECTDIR}/send_receive_messages.o 
	@${FIXDEPS} "${OBJECTDIR}/send_receive_messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/send_receive_messages.o.d" -o ${OBJECTDIR}/send_receive_messages.o send_receive_messages.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/schedules.o: schedules.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/schedules.o.d 
	@${RM} ${OBJECTDIR}/schedules.o 
	@${FIXDEPS} "${OBJECTDIR}/schedules.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/schedules.o.d" -o ${OBJECTDIR}/schedules.o schedules.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/create_normal_message.o: create_normal_message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/create_normal_message.o.d 
	@${RM} ${OBJECTDIR}/create_normal_message.o 
	@${FIXDEPS} "${OBJECTDIR}/create_normal_message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/create_normal_message.o.d" -o ${OBJECTDIR}/create_normal_message.o create_normal_message.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/actuators.o: actuators.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/actuators.o.d 
	@${RM} ${OBJECTDIR}/actuators.o 
	@${FIXDEPS} "${OBJECTDIR}/actuators.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/actuators.o.d" -o ${OBJECTDIR}/actuators.o actuators.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/air_quality_level.o: air_quality_level.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/air_quality_level.o.d 
	@${RM} ${OBJECTDIR}/air_quality_level.o 
	@${FIXDEPS} "${OBJECTDIR}/air_quality_level.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/air_quality_level.o.d" -o ${OBJECTDIR}/air_quality_level.o air_quality_level.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
