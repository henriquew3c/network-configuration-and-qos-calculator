#include<stdio.h>

// HOST rede 3.3.3.8/30
	main(){
			system("ifconfig p6p1 1.1.1.10/30");
			system("route add default gw 1.1.1.9");
			system("echo 1 > /proc/sys/net/ipv4/ip_forward");
			system("iptables -F");
			system("iptables -t nat -F");
		}
