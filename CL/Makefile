# $Id: Makefile,v 1.4 2011/09/14 21:09:05 slava77 Exp $

CC = g++
INCLUDE = -I${CMS2_LOCATION}/NtupleMacros
CFLAGS = -Wall -g -O0 -fPIC $(shell root-config --cflags) $(INCLUDE) $(EXTRACFLAGS) -DTOOLSLIB

LINKER = g++
LINKERFLAGS = $(shell root-config --ldflags) -z muldefs
ifeq ($(shell root-config --platform),macosx)
	# linker option for Mac OS X, got it from old project, seems to work ;-)
	LINKERFLAGS = -bundle -undefined suppress -Wl,-x -O -Xlinker -bind_at_load -flat_namespace $(shell root-config --libs) -lEG -lGenVector
endif

CORESOURCES = $(wildcard ${CMS2_LOCATION}/NtupleMacros/CORE/*.cc) 
COREHEADERS = $(wildcard ${CMS2_LOCATION}/NtupleMacros/CORE/*.h) 
COREOBJECTS = $(CORESOURCES:.cc=.o) linkdef_core.o
CORELIB = libCMS2NtupleMacrosCORE.so

TOOLSSOURCES = $(wildcard ${CMS2_LOCATION}/NtupleMacros/Tools/*.cc) 
TOOLSOBJECTS = $(TOOLSSOURCES:.cc=.o) 
TOOLSLIB = libCMS2NtupleMacrosTools.so

LOOPERSOURCES = $(wildcard *.cc) 
LOOPEROBJECTS = $(LOOPERSOURCES:.cc=.o) linkdef_out.o
LOOPERLIB = libCMS2CL.so

LIBS = $(LOOPERLIB) $(CORELIB) #$(TOOLSLIB) 

TABLES = Results.tbl

.PHONY: all
all:	check_env $(LIBS) 

.PHONY: check_env
check_env:
	if [ -z $(CMS2_LOCATION) ] ; then echo "first set CMS2_LOCATION" ; exit 1 ; fi

.PHONY: libs
libs:	$(LIBS)

$(TOOLSLIB):	$(TOOLSOBJECTS) 
	$(LINKER) $(LINKERFLAGS) -shared $(TOOLSOBJECTS) -o $@ 

$(CORELIB):	$(COREOBJECTS) 
	$(LINKER) $(LINKERFLAGS) -shared $(COREOBJECTS) -o $@ 

$(LOOPERLIB):	$(LOOPEROBJECTS) 
	$(LINKER) $(LINKERFLAGS) -shared $(LOOPEROBJECTS) -o $@ 

linkdef_out.cxx: CMS2TreePlayer.h
	rootcint -f $@ -c $(INCLUDE) CMS2TreePlayer.h $<

linkdef_core.cxx: $(COREHEADERS) linkdef.h
	rootcint -f $@ -c $(INCLUDE) $(COREHEADERS) linkdef.h

# General rule for making object files
%.d:	%.cc
	$(CC) -MM -MT $@ -MT ${@:.d=.o} $(CFLAGS) $< > $@; \
                     [ -s $@ ] || rm -f $@
%.d:	%.cxx
	$(CC) -MM -MT $@ -MT ${@:.d=.o} $(CFLAGS) $< > $@; \
                     [ -s $@ ] || rm -f $@

%.o: 	%.cc 
	$(CC) $(CFLAGS) $< -c -o $@

%.o: 	%.cxx
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:  
	rm -f ${CMS2_LOCATION}/NtupleMacros/Tools/*.o ${CMS2_LOCATION}/NtupleMacros/Tools/*.d $(TOOLSLIB) \
		${CMS2_LOCATION}/NtupleMacros/CORE/*.o ${CMS2_LOCATION}/NtupleMacros/CORE/*.d $(CORELIB) \
		*.o *.d linkdef_*.* $(LOOPERLIB) \
		$(TABLES) 

# how to make tables
$(TABLES): $(LIBS)

%.tbl %.root %.log:	$(LIBS)
	echo $(@:.tbl=)"()" | root.exe -b setup.C

-include $(TOOLSSOURCES:.cc=.d)
-include $(CORESOURCES:.cc=.d)
-include $(LOOPERSOURCES:.cc=.d)
-include linkdef_out.d

.PRECIOUS: $(wildcard *.tbl) $(wildcard *.log) $(wildcard *.root)
