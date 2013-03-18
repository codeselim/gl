#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/676253835/node.o \
	${OBJECTDIR}/_ext/676253835/child_elt.o \
	${OBJECTDIR}/_ext/676253835/dtd_attr.o \
	${OBJECTDIR}/_ext/676253835/dtd.o \
	${OBJECTDIR}/_ext/676253835/document.o \
	${OBJECTDIR}/_ext/676253835/main.o \
	${OBJECTDIR}/_ext/676253835/text_node.o \
	${OBJECTDIR}/_ext/676253835/dtd_elt.o \
	${OBJECTDIR}/_ext/676253835/element.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gl \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gl

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gl: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gl ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/676253835/node.o: nbproject/Makefile-${CND_CONF}.mk ../../data_structures/node.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/node.o ../../data_structures/node.cpp

${OBJECTDIR}/_ext/676253835/child_elt.o: nbproject/Makefile-${CND_CONF}.mk ../../data_structures/child_elt.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/child_elt.o ../../data_structures/child_elt.cpp

${OBJECTDIR}/_ext/676253835/dtd_attr.o: nbproject/Makefile-${CND_CONF}.mk ../../data_structures/dtd_attr.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/dtd_attr.o ../../data_structures/dtd_attr.cpp

${OBJECTDIR}/_ext/676253835/dtd.o: nbproject/Makefile-${CND_CONF}.mk ../../data_structures/dtd.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/dtd.o ../../data_structures/dtd.cpp

${OBJECTDIR}/_ext/676253835/document.o: nbproject/Makefile-${CND_CONF}.mk ../../data_structures/document.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/document.o ../../data_structures/document.cpp

${OBJECTDIR}/_ext/676253835/main.o: nbproject/Makefile-${CND_CONF}.mk ../../data_structures/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/main.o ../../data_structures/main.cpp

${OBJECTDIR}/_ext/676253835/text_node.o: nbproject/Makefile-${CND_CONF}.mk ../../data_structures/text_node.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/text_node.o ../../data_structures/text_node.cpp

${OBJECTDIR}/_ext/676253835/dtd_elt.o: nbproject/Makefile-${CND_CONF}.mk ../../data_structures/dtd_elt.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/dtd_elt.o ../../data_structures/dtd_elt.cpp

${OBJECTDIR}/_ext/676253835/element.o: nbproject/Makefile-${CND_CONF}.mk ../../data_structures/element.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/element.o ../../data_structures/element.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gl: ${TESTDIR}/_ext/1635097729/element_getters.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc}   -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gl $^ ${LDLIBSOPTIONS} 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/_ext/1635097729/to_xml.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/_ext/1635097729/element_getters.o: ../../tests/element_getters.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1635097729
	${RM} $@.d
	$(COMPILE.c) -O2 -MMD -MP -MF $@.d -o ${TESTDIR}/_ext/1635097729/element_getters.o ../../tests/element_getters.cpp


${TESTDIR}/_ext/1635097729/to_xml.o: ../../tests/to_xml.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1635097729
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/_ext/1635097729/to_xml.o ../../tests/to_xml.cpp


${OBJECTDIR}/_ext/676253835/node_nomain.o: ${OBJECTDIR}/_ext/676253835/node.o ../../data_structures/node.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/676253835/node.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/node_nomain.o ../../data_structures/node.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/676253835/node.o ${OBJECTDIR}/_ext/676253835/node_nomain.o;\
	fi

${OBJECTDIR}/_ext/676253835/child_elt_nomain.o: ${OBJECTDIR}/_ext/676253835/child_elt.o ../../data_structures/child_elt.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/676253835/child_elt.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/child_elt_nomain.o ../../data_structures/child_elt.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/676253835/child_elt.o ${OBJECTDIR}/_ext/676253835/child_elt_nomain.o;\
	fi

${OBJECTDIR}/_ext/676253835/dtd_attr_nomain.o: ${OBJECTDIR}/_ext/676253835/dtd_attr.o ../../data_structures/dtd_attr.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/676253835/dtd_attr.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/dtd_attr_nomain.o ../../data_structures/dtd_attr.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/676253835/dtd_attr.o ${OBJECTDIR}/_ext/676253835/dtd_attr_nomain.o;\
	fi

${OBJECTDIR}/_ext/676253835/dtd_nomain.o: ${OBJECTDIR}/_ext/676253835/dtd.o ../../data_structures/dtd.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/676253835/dtd.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/dtd_nomain.o ../../data_structures/dtd.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/676253835/dtd.o ${OBJECTDIR}/_ext/676253835/dtd_nomain.o;\
	fi

${OBJECTDIR}/_ext/676253835/document_nomain.o: ${OBJECTDIR}/_ext/676253835/document.o ../../data_structures/document.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/676253835/document.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/document_nomain.o ../../data_structures/document.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/676253835/document.o ${OBJECTDIR}/_ext/676253835/document_nomain.o;\
	fi

${OBJECTDIR}/_ext/676253835/main_nomain.o: ${OBJECTDIR}/_ext/676253835/main.o ../../data_structures/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/676253835/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/main_nomain.o ../../data_structures/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/676253835/main.o ${OBJECTDIR}/_ext/676253835/main_nomain.o;\
	fi

${OBJECTDIR}/_ext/676253835/text_node_nomain.o: ${OBJECTDIR}/_ext/676253835/text_node.o ../../data_structures/text_node.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/676253835/text_node.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/text_node_nomain.o ../../data_structures/text_node.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/676253835/text_node.o ${OBJECTDIR}/_ext/676253835/text_node_nomain.o;\
	fi

${OBJECTDIR}/_ext/676253835/dtd_elt_nomain.o: ${OBJECTDIR}/_ext/676253835/dtd_elt.o ../../data_structures/dtd_elt.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/676253835/dtd_elt.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/dtd_elt_nomain.o ../../data_structures/dtd_elt.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/676253835/dtd_elt.o ${OBJECTDIR}/_ext/676253835/dtd_elt_nomain.o;\
	fi

${OBJECTDIR}/_ext/676253835/element_nomain.o: ${OBJECTDIR}/_ext/676253835/element.o ../../data_structures/element.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/676253835
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/676253835/element.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/676253835/element_nomain.o ../../data_structures/element.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/676253835/element.o ${OBJECTDIR}/_ext/676253835/element_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gl || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gl

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
