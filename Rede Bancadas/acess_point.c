#include <stdio.h>
main()
{
//	system("ifconfig eth0 200.129.176.42/30"); //dependendo do caso estes comandos são desnecessários
//	system("ifconfig eth0:0 200.129.176.45/30");
//	system("ifconfig eth0:1 200.129.176.48/30");
	system("ifconfig wlan0 down");
	system("hostapd /etc/hostapd/hostapd.conf &"); // esse comando inicializa o serviço hostapd
	system("sysctl net.ipv4.ip_forward=1");
	system("iptables -t nat -A POSTROUTING -o eth0 -j MASQUERATE");
	system("ifconfig wlan0 192.168.0.1/24"); // esse ip tem que ser o mesmo que foi inserido no arquivo dhcpd.conf como ip da placa
	system("dhcpd3 -cf /etc/dhcp3/dhcpd.conf");  // esse comando inicializa o serviço dhcp
	system("route add default gw 10.10.6.1");

}
