  #include <cstdlib>
#include <iostream>
#include <winsock2.h>
#include <stdlib.h>

using namespace std;

// Fonction temporisation
void temporise (int duree)
{int i;
 long J; 
for (i=0;i<=duree;i++) 
{ for (J=0;J<=200000;J++);
 }
 }
 
int main()
{
//D�claration des buffers d'envoie et de r�ception
char buf2[7]; //R�ception
unsigned char buf[2]; //Envoie
int batterie ;
int vit_avant_gauche ;
int vit_ar_gauche ;
int vit_avant_droite ;
int vit_ar_droite ;
int infrarouge_gauche ;
int infrarouge_droite ;
char comg,comd;
//D�claration des �l�ments du socket :
SOCKET sock;
SOCKADDR_IN san;
char* Adresse = "192.168.0.140";// Adresse IP du robot
int Port = 15000 ; // Le port utilis�
//Initialisation des variables socket pour l'OS
WSADATA WSAData;
WSAStartup(MAKEWORD(2,0), &WSAData);
//Initialisation des param�tres du socket
san.sin_addr.s_addr = inet_addr(Adresse);
san.sin_family = AF_INET;
san.sin_port = htons(Port);
sock = socket(AF_INET,SOCK_STREAM,0);
bind(sock, (SOCKADDR *)&san, sizeof(san));



//Initialisation commandes
comg= 0x5F ;  // marche avant vitesse = 31
comd= 0x5F ;  // marche avant vitesse = 31
buf[0] = comg ;
buf[1] = comd ;


/*gestion des erreurs de connections*/
if (connect(sock, (SOCKADDR *)&san, sizeof(san)) == -1)
{
cout << "Erreur de connection au robot" << endl;

  system("PAUSE");

exit(0);
}

else
{
cout << "Connecte" << endl;
}
temporise (100);
send(sock,(char *) &buf,sizeof(buf),0);
recv(sock,(char *) &buf2, sizeof(buf2),0);
batterie = buf2[0];
vit_avant_gauche = buf2[1];
vit_ar_gauche = buf2[2];
vit_avant_droite = buf2[3];
vit_ar_droite = buf2[4];
infrarouge_gauche = buf2[5];
infrarouge_droite = buf2[6];
cout << "batterie = " << batterie  << "\n " ;
cout << "vit_avant_gauche = " << vit_avant_gauche  << "\n " ;
cout << "vit_ar_gauche =  " << vit_ar_gauche  << "\n " ;
cout << "vit_avant_droite = " << vit_avant_droite  << "\n " ;
cout << "vit_ar_droite =  " << vit_ar_droite  << "\n " ;

  system("PAUSE");
closesocket(sock);//fermeture du socket pour le robot
return(0);
}
