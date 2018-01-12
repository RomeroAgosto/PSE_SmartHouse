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
SOURCEFILES_QUOTED_IF_SPACED=../actuators/actuators.c ../CKCommon/UART/uart.c ../clock_hall/get_time.c ../clock_hall/hallClock.c ../../pic_programming/Communication.X/StatemachineCommunication/create_normal_message.c ../../pic_programming/Communication.X/StatemachineCommunication/send_receive_messages.c ../log/log_functions.c ../schedules/desiredValues.c ../schedules/schedules.c ../schedules/get_schedule_message.c ../sensors/adc_init.c ../sensors/air_quality_level.c ../sensors/i2c.c ../sensors/motion_detection.c ../sensors/temp_analog.c ../sensors/temp_digital.c ../Statemachines.X/AirQuality/Statemachine_AirQuality/statemachine_airquality_control.c ../Statemachines.X/AirTemperature/Statemachine_AirTemperature/statemachine_airtemp_control.c ../Statemachines.X/LightControl/StatemachineLightControl/statemachine_light_control.c ../Statemachines.X/WaterTemperature/Statemachine_Water/statemachine_watertemp_control.c ../update/update.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/470364171/actuators.o ${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/_ext/731469447/get_time.o ${OBJECTDIR}/_ext/731469447/hallClock.o ${OBJECTDIR}/_ext/1424201914/create_normal_message.o ${OBJECTDIR}/_ext/1424201914/send_receive_messages.o ${OBJECTDIR}/_ext/1360930421/log_functions.o ${OBJECTDIR}/_ext/219456723/desiredValues.o ${OBJECTDIR}/_ext/219456723/schedules.o ${OBJECTDIR}/_ext/219456723/get_schedule_message.o ${OBJECTDIR}/_ext/299869866/adc_init.o ${OBJECTDIR}/_ext/299869866/air_quality_level.o ${OBJECTDIR}/_ext/299869866/i2c.o ${OBJECTDIR}/_ext/299869866/motion_detection.o ${OBJECTDIR}/_ext/299869866/temp_analog.o ${OBJECTDIR}/_ext/299869866/temp_digital.o ${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o ${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o ${OBJECTDIR}/_ext/767478478/statemachine_light_control.o ${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o ${OBJECTDIR}/_ext/754508808/update.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/470364171/actuators.o.d ${OBJECTDIR}/_ext/1062335525/uart.o.d ${OBJECTDIR}/_ext/731469447/get_time.o.d ${OBJECTDIR}/_ext/731469447/hallClock.o.d ${OBJECTDIR}/_ext/1424201914/create_normal_message.o.d ${OBJECTDIR}/_ext/1424201914/send_receive_messages.o.d ${OBJECTDIR}/_ext/1360930421/log_functions.o.d ${OBJECTDIR}/_ext/219456723/desiredValues.o.d ${OBJECTDIR}/_ext/219456723/schedules.o.d ${OBJECTDIR}/_ext/219456723/get_schedule_message.o.d ${OBJECTDIR}/_ext/299869866/adc_init.o.d ${OBJECTDIR}/_ext/299869866/air_quality_level.o.d ${OBJECTDIR}/_ext/299869866/i2c.o.d ${OBJECTDIR}/_ext/299869866/motion_detection.o.d ${OBJECTDIR}/_ext/299869866/temp_analog.o.d ${OBJECTDIR}/_ext/299869866/temp_digital.o.d ${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o.d ${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o.d ${OBJECTDIR}/_ext/767478478/statemachine_light_control.o.d ${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o.d ${OBJECTDIR}/_ext/754508808/update.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/470364171/actuators.o ${OBJECTDIR}/_ext/1062335525/uart.o ${OBJECTDIR}/_ext/731469447/get_time.o ${OBJECTDIR}/_ext/731469447/hallClock.o ${OBJECTDIR}/_ext/1424201914/create_normal_message.o ${OBJECTDIR}/_ext/1424201914/send_receive_messages.o ${OBJECTDIR}/_ext/1360930421/log_functions.o ${OBJECTDIR}/_ext/219456723/desiredValues.o ${OBJECTDIR}/_ext/219456723/schedules.o ${OBJECTDIR}/_ext/219456723/get_schedule_message.o ${OBJECTDIR}/_ext/299869866/adc_init.o ${OBJECTDIR}/_ext/299869866/air_quality_level.o ${OBJECTDIR}/_ext/299869866/i2c.o ${OBJECTDIR}/_ext/299869866/motion_detection.o ${OBJECTDIR}/_ext/299869866/temp_analog.o ${OBJECTDIR}/_ext/299869866/temp_digital.o ${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o ${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o ${OBJECTDIR}/_ext/767478478/statemachine_light_control.o ${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o ${OBJECTDIR}/_ext/754508808/update.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=../actuators/actuators.c ../CKCommon/UART/uart.c ../clock_hall/get_time.c ../clock_hall/hallClock.c ../../pic_programming/Communication.X/StatemachineCommunication/create_normal_message.c ../../pic_programming/Communication.X/StatemachineCommunication/send_receive_messages.c ../log/log_functions.c ../schedules/desiredValues.c ../schedules/schedules.c ../schedules/get_schedule_message.c ../sensors/adc_init.c ../sensors/air_quality_level.c ../sensors/i2c.c ../sensors/motion_detection.c ../sensors/temp_analog.c ../sensors/temp_digital.c ../Statemachines.X/AirQuality/Statemachine_AirQuality/statemachine_airquality_control.c ../Statemachines.X/AirTemperature/Statemachine_AirTemperature/statemachine_airtemp_control.c ../Statemachines.X/LightControl/StatemachineLightControl/statemachine_light_control.c ../Statemachines.X/WaterTemperature/Statemachine_Water/statemachine_watertemp_control.c ../update/update.c main.c


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
${OBJECTDIR}/_ext/470364171/actuators.o: ../actuators/actuators.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/470364171" 
	@${RM} ${OBJECTDIR}/_ext/470364171/actuators.o.d 
	@${RM} ${OBJECTDIR}/_ext/470364171/actuators.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/470364171/actuators.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/470364171/actuators.o.d" -o ${OBJECTDIR}/_ext/470364171/actuators.o ../actuators/actuators.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1062335525/uart.o: ../CKCommon/UART/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1062335525" 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1062335525/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1062335525/uart.o.d" -o ${OBJECTDIR}/_ext/1062335525/uart.o ../CKCommon/UART/uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/731469447/get_time.o: ../clock_hall/get_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/731469447" 
	@${RM} ${OBJECTDIR}/_ext/731469447/get_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/731469447/get_time.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/731469447/get_time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/731469447/get_time.o.d" -o ${OBJECTDIR}/_ext/731469447/get_time.o ../clock_hall/get_time.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/731469447/hallClock.o: ../clock_hall/hallClock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/731469447" 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o.d 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/731469447/hallClock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/731469447/hallClock.o.d" -o ${OBJECTDIR}/_ext/731469447/hallClock.o ../clock_hall/hallClock.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1424201914/create_normal_message.o: ../../pic_programming/Communication.X/StatemachineCommunication/create_normal_message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1424201914" 
	@${RM} ${OBJECTDIR}/_ext/1424201914/create_normal_message.o.d 
	@${RM} ${OBJECTDIR}/_ext/1424201914/create_normal_message.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1424201914/create_normal_message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1424201914/create_normal_message.o.d" -o ${OBJECTDIR}/_ext/1424201914/create_normal_message.o ../../pic_programming/Communication.X/StatemachineCommunication/create_normal_message.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1424201914/send_receive_messages.o: ../../pic_programming/Communication.X/StatemachineCommunication/send_receive_messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1424201914" 
	@${RM} ${OBJECTDIR}/_ext/1424201914/send_receive_messages.o.d 
	@${RM} ${OBJECTDIR}/_ext/1424201914/send_receive_messages.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1424201914/send_receive_messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1424201914/send_receive_messages.o.d" -o ${OBJECTDIR}/_ext/1424201914/send_receive_messages.o ../../pic_programming/Communication.X/StatemachineCommunication/send_receive_messages.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360930421/log_functions.o: ../log/log_functions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360930421" 
	@${RM} ${OBJECTDIR}/_ext/1360930421/log_functions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930421/log_functions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360930421/log_functions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360930421/log_functions.o.d" -o ${OBJECTDIR}/_ext/1360930421/log_functions.o ../log/log_functions.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/219456723/desiredValues.o: ../schedules/desiredValues.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/219456723" 
	@${RM} ${OBJECTDIR}/_ext/219456723/desiredValues.o.d 
	@${RM} ${OBJECTDIR}/_ext/219456723/desiredValues.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/219456723/desiredValues.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/219456723/desiredValues.o.d" -o ${OBJECTDIR}/_ext/219456723/desiredValues.o ../schedules/desiredValues.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/219456723/schedules.o: ../schedules/schedules.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/219456723" 
	@${RM} ${OBJECTDIR}/_ext/219456723/schedules.o.d 
	@${RM} ${OBJECTDIR}/_ext/219456723/schedules.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/219456723/schedules.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/219456723/schedules.o.d" -o ${OBJECTDIR}/_ext/219456723/schedules.o ../schedules/schedules.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/219456723/get_schedule_message.o: ../schedules/get_schedule_message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/219456723" 
	@${RM} ${OBJECTDIR}/_ext/219456723/get_schedule_message.o.d 
	@${RM} ${OBJECTDIR}/_ext/219456723/get_schedule_message.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/219456723/get_schedule_message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/219456723/get_schedule_message.o.d" -o ${OBJECTDIR}/_ext/219456723/get_schedule_message.o ../schedules/get_schedule_message.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/adc_init.o: ../sensors/adc_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/adc_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/adc_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/adc_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/adc_init.o.d" -o ${OBJECTDIR}/_ext/299869866/adc_init.o ../sensors/adc_init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/air_quality_level.o: ../sensors/air_quality_level.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/air_quality_level.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/air_quality_level.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/air_quality_level.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/air_quality_level.o.d" -o ${OBJECTDIR}/_ext/299869866/air_quality_level.o ../sensors/air_quality_level.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/i2c.o: ../sensors/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/i2c.o.d" -o ${OBJECTDIR}/_ext/299869866/i2c.o ../sensors/i2c.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/motion_detection.o: ../sensors/motion_detection.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/motion_detection.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/motion_detection.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/motion_detection.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/motion_detection.o.d" -o ${OBJECTDIR}/_ext/299869866/motion_detection.o ../sensors/motion_detection.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/temp_analog.o: ../sensors/temp_analog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/temp_analog.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/temp_analog.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/temp_analog.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/temp_analog.o.d" -o ${OBJECTDIR}/_ext/299869866/temp_analog.o ../sensors/temp_analog.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/temp_digital.o: ../sensors/temp_digital.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/temp_digital.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/temp_digital.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/temp_digital.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/temp_digital.o.d" -o ${OBJECTDIR}/_ext/299869866/temp_digital.o ../sensors/temp_digital.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o: ../Statemachines.X/AirQuality/Statemachine_AirQuality/statemachine_airquality_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295191707" 
	@${RM} ${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o.d" -o ${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o ../Statemachines.X/AirQuality/Statemachine_AirQuality/statemachine_airquality_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o: ../Statemachines.X/AirTemperature/Statemachine_AirTemperature/statemachine_airtemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/719964549" 
	@${RM} ${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o.d" -o ${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o ../Statemachines.X/AirTemperature/Statemachine_AirTemperature/statemachine_airtemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/767478478/statemachine_light_control.o: ../Statemachines.X/LightControl/StatemachineLightControl/statemachine_light_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/767478478" 
	@${RM} ${OBJECTDIR}/_ext/767478478/statemachine_light_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/767478478/statemachine_light_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767478478/statemachine_light_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/767478478/statemachine_light_control.o.d" -o ${OBJECTDIR}/_ext/767478478/statemachine_light_control.o ../Statemachines.X/LightControl/StatemachineLightControl/statemachine_light_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o: ../Statemachines.X/WaterTemperature/Statemachine_Water/statemachine_watertemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/502816713" 
	@${RM} ${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o.d" -o ${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o ../Statemachines.X/WaterTemperature/Statemachine_Water/statemachine_watertemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/754508808/update.o: ../update/update.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/754508808" 
	@${RM} ${OBJECTDIR}/_ext/754508808/update.o.d 
	@${RM} ${OBJECTDIR}/_ext/754508808/update.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/754508808/update.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/754508808/update.o.d" -o ${OBJECTDIR}/_ext/754508808/update.o ../update/update.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPK3OBPlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/470364171/actuators.o: ../actuators/actuators.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/470364171" 
	@${RM} ${OBJECTDIR}/_ext/470364171/actuators.o.d 
	@${RM} ${OBJECTDIR}/_ext/470364171/actuators.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/470364171/actuators.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/470364171/actuators.o.d" -o ${OBJECTDIR}/_ext/470364171/actuators.o ../actuators/actuators.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1062335525/uart.o: ../CKCommon/UART/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1062335525" 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1062335525/uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1062335525/uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1062335525/uart.o.d" -o ${OBJECTDIR}/_ext/1062335525/uart.o ../CKCommon/UART/uart.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/731469447/get_time.o: ../clock_hall/get_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/731469447" 
	@${RM} ${OBJECTDIR}/_ext/731469447/get_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/731469447/get_time.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/731469447/get_time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/731469447/get_time.o.d" -o ${OBJECTDIR}/_ext/731469447/get_time.o ../clock_hall/get_time.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/731469447/hallClock.o: ../clock_hall/hallClock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/731469447" 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o.d 
	@${RM} ${OBJECTDIR}/_ext/731469447/hallClock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/731469447/hallClock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/731469447/hallClock.o.d" -o ${OBJECTDIR}/_ext/731469447/hallClock.o ../clock_hall/hallClock.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1424201914/create_normal_message.o: ../../pic_programming/Communication.X/StatemachineCommunication/create_normal_message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1424201914" 
	@${RM} ${OBJECTDIR}/_ext/1424201914/create_normal_message.o.d 
	@${RM} ${OBJECTDIR}/_ext/1424201914/create_normal_message.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1424201914/create_normal_message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1424201914/create_normal_message.o.d" -o ${OBJECTDIR}/_ext/1424201914/create_normal_message.o ../../pic_programming/Communication.X/StatemachineCommunication/create_normal_message.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1424201914/send_receive_messages.o: ../../pic_programming/Communication.X/StatemachineCommunication/send_receive_messages.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1424201914" 
	@${RM} ${OBJECTDIR}/_ext/1424201914/send_receive_messages.o.d 
	@${RM} ${OBJECTDIR}/_ext/1424201914/send_receive_messages.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1424201914/send_receive_messages.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1424201914/send_receive_messages.o.d" -o ${OBJECTDIR}/_ext/1424201914/send_receive_messages.o ../../pic_programming/Communication.X/StatemachineCommunication/send_receive_messages.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360930421/log_functions.o: ../log/log_functions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360930421" 
	@${RM} ${OBJECTDIR}/_ext/1360930421/log_functions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360930421/log_functions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360930421/log_functions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360930421/log_functions.o.d" -o ${OBJECTDIR}/_ext/1360930421/log_functions.o ../log/log_functions.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/219456723/desiredValues.o: ../schedules/desiredValues.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/219456723" 
	@${RM} ${OBJECTDIR}/_ext/219456723/desiredValues.o.d 
	@${RM} ${OBJECTDIR}/_ext/219456723/desiredValues.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/219456723/desiredValues.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/219456723/desiredValues.o.d" -o ${OBJECTDIR}/_ext/219456723/desiredValues.o ../schedules/desiredValues.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/219456723/schedules.o: ../schedules/schedules.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/219456723" 
	@${RM} ${OBJECTDIR}/_ext/219456723/schedules.o.d 
	@${RM} ${OBJECTDIR}/_ext/219456723/schedules.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/219456723/schedules.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/219456723/schedules.o.d" -o ${OBJECTDIR}/_ext/219456723/schedules.o ../schedules/schedules.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/219456723/get_schedule_message.o: ../schedules/get_schedule_message.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/219456723" 
	@${RM} ${OBJECTDIR}/_ext/219456723/get_schedule_message.o.d 
	@${RM} ${OBJECTDIR}/_ext/219456723/get_schedule_message.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/219456723/get_schedule_message.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/219456723/get_schedule_message.o.d" -o ${OBJECTDIR}/_ext/219456723/get_schedule_message.o ../schedules/get_schedule_message.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/adc_init.o: ../sensors/adc_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/adc_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/adc_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/adc_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/adc_init.o.d" -o ${OBJECTDIR}/_ext/299869866/adc_init.o ../sensors/adc_init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/air_quality_level.o: ../sensors/air_quality_level.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/air_quality_level.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/air_quality_level.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/air_quality_level.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/air_quality_level.o.d" -o ${OBJECTDIR}/_ext/299869866/air_quality_level.o ../sensors/air_quality_level.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/i2c.o: ../sensors/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/i2c.o.d" -o ${OBJECTDIR}/_ext/299869866/i2c.o ../sensors/i2c.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/motion_detection.o: ../sensors/motion_detection.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/motion_detection.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/motion_detection.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/motion_detection.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/motion_detection.o.d" -o ${OBJECTDIR}/_ext/299869866/motion_detection.o ../sensors/motion_detection.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/temp_analog.o: ../sensors/temp_analog.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/temp_analog.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/temp_analog.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/temp_analog.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/temp_analog.o.d" -o ${OBJECTDIR}/_ext/299869866/temp_analog.o ../sensors/temp_analog.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/299869866/temp_digital.o: ../sensors/temp_digital.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/299869866" 
	@${RM} ${OBJECTDIR}/_ext/299869866/temp_digital.o.d 
	@${RM} ${OBJECTDIR}/_ext/299869866/temp_digital.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/299869866/temp_digital.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/299869866/temp_digital.o.d" -o ${OBJECTDIR}/_ext/299869866/temp_digital.o ../sensors/temp_digital.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o: ../Statemachines.X/AirQuality/Statemachine_AirQuality/statemachine_airquality_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1295191707" 
	@${RM} ${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o.d" -o ${OBJECTDIR}/_ext/1295191707/statemachine_airquality_control.o ../Statemachines.X/AirQuality/Statemachine_AirQuality/statemachine_airquality_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o: ../Statemachines.X/AirTemperature/Statemachine_AirTemperature/statemachine_airtemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/719964549" 
	@${RM} ${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o.d" -o ${OBJECTDIR}/_ext/719964549/statemachine_airtemp_control.o ../Statemachines.X/AirTemperature/Statemachine_AirTemperature/statemachine_airtemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/767478478/statemachine_light_control.o: ../Statemachines.X/LightControl/StatemachineLightControl/statemachine_light_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/767478478" 
	@${RM} ${OBJECTDIR}/_ext/767478478/statemachine_light_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/767478478/statemachine_light_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767478478/statemachine_light_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/767478478/statemachine_light_control.o.d" -o ${OBJECTDIR}/_ext/767478478/statemachine_light_control.o ../Statemachines.X/LightControl/StatemachineLightControl/statemachine_light_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o: ../Statemachines.X/WaterTemperature/Statemachine_Water/statemachine_watertemp_control.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/502816713" 
	@${RM} ${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o.d 
	@${RM} ${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o.d" -o ${OBJECTDIR}/_ext/502816713/statemachine_watertemp_control.o ../Statemachines.X/WaterTemperature/Statemachine_Water/statemachine_watertemp_control.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/754508808/update.o: ../update/update.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/754508808" 
	@${RM} ${OBJECTDIR}/_ext/754508808/update.o.d 
	@${RM} ${OBJECTDIR}/_ext/754508808/update.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/754508808/update.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/754508808/update.o.d" -o ${OBJECTDIR}/_ext/754508808/update.o ../update/update.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -DPK3OBPlatformTool=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=PK3OBPlatformTool=1,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/final.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
