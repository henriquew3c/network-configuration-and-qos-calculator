#inlude<stdio.h>
void main()
{

//*********************************** GW NORMAIS ******************************************************************************************

// Setando o ip e a máscara para o getway

system("ifconfig p6p1 1.1.1.1/30");

//Criando ALIAS e setanto ip e máscara para conexão com outras redes - CASO NECESSÁRIO

system("ifconfig p6p1:0 1.1.1.17/30");

// limpa as tabelas - NECESSÁRIO PARA PREVENIR FALHAS

system("iptables -t nat -F POSTROUTING");
system("iptables -t nat -F PREROUTING");
system("iptables -t nat -F OUTPUT");
system("iptables -F");

// Adicionar rota para uma rede - NECESSÁRIO PARA QUE O GETWAY CONHECA A EXISTENCIA DA REDE INDICADA, basicamente estou informando que se caso o getway precisar enviar algum pacote para a rede 4 a saida padrão será pelo getway 1.1.1.17.

system("route add -net 1.1.1.4/30 gw 1.1.1.17");

// Adicionar rota de fuga padrão - NESTE CASO SERA O PROXIMO GETWAY

system("route add default gw 1.1.1.1");

// Habilita o ip_forward.
 
system("sysctrl net.ipv4.ip_forward=1");

}

/*

********************************** PARTE UTILIZADA PARA O GW QUE FORNECERÁ ACESSO A INTERNET *************************************************
//

//Fazer o IP Masquerading para todas as máquinas da rede, NECESSÁRIO PARA TER ACESSO A INTERNET: 

system("iptables -t nat -A POSTROUTING -o p6p1 -j MASQUERADE");

// Após definir a regra para fazer Masquerading (SNAT), execute o comando para habilitar o suporte a redirecionamento de pacotes no kernel:
// Habilita o ip_forward.
 
system("sysctrl net.ipv4.ip_forward=1");

// Especificar o endereço IP da máquina masquerading (servidor) como Gateway da rede

system("route add default gw 10.10.6.4"); 

*/
