#include<stdio.h>

// HOST rede 3.3.3.0/30
	main(){
			system("ifconfig p6p1 1.1.1.2/30");
			system("route add default gw 1.1.1.1");
			system("echo 1 > /proc/sys/net/ipv4/ip_forward");
			system("iptables -F");
			system("iptables -t nat -F");
		}
