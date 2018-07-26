#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<linux/ip.h>
#include<linux/icmp.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include"pcap.h"

int main(void)
{
  /* Allocate a buffer large enough to hold IP and ICMP header */
  char* packet = (char*)malloc(sizeof(struct iphdr) + sizeof(struct icmphdr));

  /* Declare pointers to appropriately offset IP and ICMP headers */
  struct iphdr* ip = (struct iphdr*)packet; // Points to the beginning of the iphdr, which is at the beginning of the packet.
  struct icmphdr* icmp = (struct icmphdr*)(packet + sizeof(struct iphdr)); // Points to the start of the icmphdr, which is just after the end of the iphdr in the packet.

  /* Populate the headers with data */
  ip->ihl = 0x05; // Header length with no options.
  ip->version = 0x04;
  ip->tos = 0x00;
  ip->protocol = 0x01; // ICMP
  ip->saddr = inet_addr("192.168.0.67"); 
  ip->daddr = inet_addr("192.168.0.67"); 
  icmp->type = 0x08; // Echo reply

  /* Write the buffer to file using write_pcap() */
  write_pcap("packet", packet, sizeof(struct iphdr) + sizeof(struct icmphdr));

  /* Free dynamic memory */
  free(packet);
  
  return EXIT_SUCCESS;
}
