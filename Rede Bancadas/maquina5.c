#include<stdio.h>

// Gateway rede 3.3.3.8/30
	main(){
			system("ifconfig p6p1 1.1.1.9/30");
			system("ifconfig p6p1:0 1.1.1.18/30");
			system("route add -net 1.1.1.0/30 gw 1.1.1.17");
			system("route add -net 1.1.1.4/30 gw 1.1.1.17");
			system("route add -net 1.1.1.12/30 gw 1.1.1.17");
			system("echo 1 > /proc/sys/net/ipv4/ip_forward");
			system("iptables -F");
			system("iptables -t nat -F");
		}

