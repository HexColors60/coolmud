# Generated automatically from Makefile.in by configure.
# Copyright, (c) 1993 Stephen F. White

# PROTO:	If you want to include the system prototypes in sys_proto.h,
#		use this.  Mostly useful in conjunction with -Wall, but
#		be warned that the prototypes in sys_proto.h may not be
#		portable.
# DEBUG_MALLOC: Use a debugging malloc() function.  Adds significant
#		overhead and should be disabled in a production MUD.
# LOG_YO:	This will cause every YO message sent and received to be
#		written to the log.  High volume; don't use this in
#		a production MUD.
# INLINE:	This will enable inlining on just about everything it's
#		possible to inline, at the cost of a larger executable.
#		Whether this is actually faster will depend largely on
#		your CPU and OS.

# Step 1:  Chose some of the above options.

OPTIONS =

# The rest of this should (cross fingers) be automatic, thanks to configure

CC = gcc
BINDIR = ../bin
SRCDIR = .
YACC = bison -y
LIBS =  -lnsl -lsocket -lresolv

# don't actually need DEFS here; stuff is all in config.h

DEFS = 

# If you want to go mad with warnings, use these:
# WARNINGS = -Wall -Wshadow -Wwrite-strings -Wmissing-prototypes \
# -Wstrict-prototypes -Wpointer-arith -Wcast-qual -Wcast-align

# if your dbm libraries give you problems, add -fpcc-struct-return

# You shouldn't need to set anything beyond this point.

##########################################################################

CFLAGS = -g $(OPTIONS) $(DEFS) $(WARNINGS)
YFLAGS = -d

SRCS =	cool.y perms.c error.c code.c symbol.c utils.c decode.c \
	list.c map.c var.c verb.c method.c compile.c \
	execute.c opcode.c opcodes1.c opcodes2.c opcodes3.c builtins.c \
	servers.c dispatch.c message.c storage.c \
	dbsize.c dbpack.c dbunpack.c \
	hash.c string.c buf.c \
	netio.c playerio.c serverio.c \
	cache.c dbmchunk.c

HDRS =  buf.h code.h cool.h db_config.h db_setup.h execute.h \
	netio.h netio_private.h proto.h servers.h servers_private.h \
	socket_proto.h string.h sys_proto.h

MISC =  Makefile.in config.h.in

DISTFILES = $(SRCS) $(HDRS) $(MISC)

OBJS =	cool.o perms.o error.o code.o symbol.o utils.o decode.o \
	list.o map.o var.o verb.o method.o compile.o \
	execute.o opcode.o opcodes1.o opcodes2.o opcodes3.o builtins.o \
	servers.o dispatch.o message.o storage.o \
	dbsize.o dbpack.o dbunpack.o \
	hash.o string.o buf.o \
	cache.o dbmchunk.o

NETIO = netio.o playerio.o serverio.o

$(BINDIR)/cm: $(OBJS) $(NETIO)
	$(CC) $(CFLAGS) $(OBJS) $(NETIO) $(LIBS) -o $(BINDIR)/cm

x.tab.h: y.tab.h
	-cmp -s x.tab.h y.tab.h || cp y.tab.h x.tab.h

depend:
	makedepend -- $(CFLAGS) -- $(SRCS)

clean:
	rm -f *.o [xy].tab.[ch] cool.c ../bin/core

dist:
	mkdir ../`cat ../.dname`/src
	ln $(DISTFILES) ../`cat ../.dname`/src
	
# DO NOT DELETE THIS LINE -- make depend depends on it.

cool.o: string.h config.h cool.h proto.h sys_proto.h code.h execute.h 
cool.o: servers.h 
perms.o: config.h string.h cool.h proto.h 
error.o: config.h string.h cool.h proto.h sys_proto.h 
code.o: config.h string.h cool.h proto.h sys_proto.h code.h 
symbol.o: config.h string.h cool.h proto.h sys_proto.h 
utils.o: config.h string.h cool.h proto.h sys_proto.h 
decode.o: config.h string.h cool.h proto.h sys_proto.h x.tab.h 
decode.o: execute.h 
list.o: config.h string.h cool.h proto.h sys_proto.h 
map.o: config.h string.h cool.h proto.h 
var.o: config.h string.h cool.h proto.h sys_proto.h servers.h 
verb.o: config.h string.h cool.h proto.h sys_proto.h 
method.o: config.h string.h cool.h proto.h 
compile.o: config.h string.h cool.h proto.h sys_proto.h netio.h 
compile.o: servers.h execute.h 
execute.o: config.h string.h cool.h proto.h sys_proto.h netio.h 
execute.o: execute.h servers.h 
opcode.o: config.h string.h cool.h proto.h sys_proto.h execute.h 
opcode.o: x.tab.h 
opcodes1.o: config.h string.h cool.h proto.h sys_proto.h netio.h 
opcodes1.o: execute.h x.tab.h 
opcodes2.o: config.h string.h cool.h proto.h sys_proto.h servers.h 
opcodes2.o: netio.h execute.h 
opcodes3.o: config.h string.h cool.h proto.h sys_proto.h servers.h 
opcodes3.o: netio.h execute.h 
builtins.o: config.h string.h cool.h proto.h sys_proto.h execute.h 
builtins.o: netio.h x.tab.h 
servers.o: config.h string.h cool.h proto.h sys_proto.h socket_proto.h 
servers.o: buf.h netio.h servers.h servers_private.h 
dispatch.o: config.h string.h cool.h proto.h sys_proto.h netio.h 
dispatch.o: execute.h 
message.o: config.h string.h cool.h proto.h sys_proto.h netio.h 
message.o: servers.h execute.h 
storage.o: config.h string.h cool.h proto.h sys_proto.h netio.h 
storage.o: servers.h 
dbsize.o: config.h string.h cool.h proto.h sys_proto.h 
dbpack.o: config.h string.h cool.h proto.h sys_proto.h db_setup.h 
dbunpack.o: config.h string.h cool.h proto.h sys_proto.h db_setup.h 
hash.o: config.h string.h cool.h proto.h 
string.o: config.h string.h cool.h proto.h sys_proto.h servers.h 
buf.o: config.h string.h buf.h netio.h 
netio.o: config.h string.h netio.h buf.h netio_private.h sys_proto.h 
netio.o: socket_proto.h servers.h 
playerio.o: config.h string.h sys_proto.h netio.h buf.h netio_private.h 
playerio.o: servers.h 
serverio.o: config.h string.h netio.h buf.h netio_private.h 
serverio.o: servers_private.h servers.h sys_proto.h socket_proto.h 
cache.o: db_config.h config.h string.h cool.h proto.h sys_proto.h 
cache.o: netio.h db_setup.h 
dbmchunk.o: db_config.h config.h string.h cool.h proto.h sys_proto.h 
dbmchunk.o: netio.h db_setup.h 
