#!/usr/bin/python
# -*- coding: utf-8 -*-
#djr
#import socketserver, os

import socket, os, commands, math, time, datetime
HostPing = '8.8.8.8'
QtdReq = '10' 
print 'AGUARDE...' 

#pega o ping e joga pra variavel
data_in=datetime.datetime.now()

pingGoogle = commands.getoutput('ping -c '+QtdReq+' '+HostPing)

#data final
data_fim=datetime.datetime.now()

#pega os times do ping e separa-os 		
ping_t = (commands.getoutput("echo \""+pingGoogle+"\" | grep time= | awk -F 'time=' {'print $2'} | awk -F 'ms' {'print $1'}").split("\n"))

#tempo total gasto
tempo_total=(data_fim - data_in).microseconds
tempo_mili=tempo_total/1000
vazao = (64*2)*float(QtdReq)/float(tempo_mili)

#sum ping
tempo_total = 0
for i in range(0, len(ping_t)):
	tempo_total += float (ping_t[	i])

# ATRASO		
atraso = float (tempo_total/len(ping_t))

#JITTER
jitter_v = 0
for j in range(1, len(ping_t)):      
	jitter_v += math.fabs(float(float(ping_t[j])-float(ping_t[j-1])))
	jitter = jitter_v/(int(QtdReq)-1)
	
	#calcula PERDA
	pacotes = commands.getoutput("echo \""+pingGoogle+"\" | grep received | awk -F ' ' {'print $1 \" \" $4'}").split(" ")
	perda = int(pacotes[0])-int(pacotes[1])
	mensagem = 'ATRASO: '+str(atraso)+' ms\nPACKET LOST: '+str(perda)+' ms\nJITTER: '+str(jitter)+'\nTEMPO EM MILISEGUNDOS: ' +str(tempo_mili)+'\nVAZAO: '+str(vazao)
