all: tcphellosvr tcphellocli

CPP=g++
CPPFLAGS=-Wall -I../common
LDFLAGS=

SRVOBJS=tcphellosvr.o ../common/buffer.o
CLIOBJS=tcphellocli.o

tcphellosvr: $(SRVOBJS)
	$(CPP) $(SRVOBJS) -o tcphellosvr

tcphellocli: $(CLIOBJS)
	$(CPP) $(CLIOBJS) -o tcphellocli

clean:
	$(RM) tcphellocli.o tcphellosvr.o tcphellocli tcphellosvr
