/**
 * @file network_packet_type.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-08-30
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>

//
// Define an enum to represent thenetwork packet types
//
typedef enum {
    PACKET_DATA,
    PACKET_ACK,
    PACKET_NACK,
} PacketType;

//
// Define the network packet structure
//
typedef struct {
    PacketType type;     // Enum field specifying the packet classification
    int sequence_number; // Sample metadata tracking packet order
    char payload[1024];  // Sample data buffer for content
} NetworkPacket;

//
// Function to process and identify the packet type
//
void process_packet(NetworkPacket pkt) {
    printf("O/P: ");
    switch (pkt.type) {
        case PACKET_DATA:
            printf("This is a DATA packet (Seq: %d)\n", pkt.sequence_number);
            break;
        case PACKET_ACK:
            printf("This is an ACK packet\n");
            break;
        case PACKET_NACK:
            printf("This is a NACK packet\n");
            break;
        default:
            printf("Unknown packet type\n");
    }
}

int main() {
    NetworkPacket ack_packet;
    ack_packet.type = PACKET_ACK;
    ack_packet.sequence_number = 101;

    printf("I/P: Packet: ACK\n");
    process_packet(ack_packet);
    printf("\n");

    NetworkPacket data_packet;
    data_packet.type = PACKET_DATA;
    data_packet.sequence_number = 102;

    printf("I/P: Packet: DATA\n");
    process_packet(data_packet);

    return 0;
}
