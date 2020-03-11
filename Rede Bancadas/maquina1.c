#include<stdio.h>

// Gateway rede 1.1.1.0/30
	main(){
			system("ifconfig p6p1 1.1.1.1/30");
			system("ifconfig p6p1:0 1.1.1.13/30");
			system("route add default gw 1.1.1.14");
			system("route add -net 1.1.1.4/30 gw 1.1.1.14");
			system("route add -net 1.1.1.8/30 gw 1.1.1.14");
			system("route add -net 1.1.1.16/30 gw 1.1.1.14");
			system("echo 1 > /proc/sys/net/ipv4/ip_forward");
			system("iptables -F");
			system("iptables -t nat -F");
		}
