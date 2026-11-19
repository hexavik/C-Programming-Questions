/**
 * @file data_packet_serialization.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-17
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

enum {
    PAYLOAD_SIZE = 3,
};

//
// Force the compiler to remove all padding bytes so the structure maps
// exactly to the raw serial stream size layout.
//
typedef struct __attribute__((packed)) {
    uint16_t header;               // 2 Bytes (e.g., 0x1234)
    uint8_t payload[PAYLOAD_SIZE]; // 3 Bytes (e.g., 0xAA, 0xBB, 0xCC)
    uint16_t checksum;             // 2 Bytes (e.g., 0xABCD)
} DataPacket;

/**
 * @brief Serialize a structure into a raw byte buffer
 *
 * @param packet Input existing data packet structure
 * @param buffer Input an empty buffer to hold the bytes
 */
void serialize(const DataPacket* packet, uint8_t* buffer) {
    //
    // We can copy field by field to handle endianness safely across systems
    //

    //
    // Copy Header (Big-Endian format layout)
    //
    buffer[0] = (packet->header >> 8) & 0xFF;
    buffer[1] = packet->header & 0xFF;

    //
    // Copy Payload
    //
    for (int i = 0; i < PAYLOAD_SIZE; ++i) {
        buffer[2 + i] = packet->payload[i];
    }

    //
    // Copy Checksum (Big-Endian format layout)
    //
    buffer[2 + PAYLOAD_SIZE] = (packet->checksum >> 8) & 0xFF;
    buffer[3 + PAYLOAD_SIZE] = packet->checksum & 0xFF;
}

/**
 * @brief Deserialize a raw byte buffer back into a structure
 *
 * @param buffer Input existing byte buffer
 * @param packet Input an empty data packet structure
 */
void deserialize(const uint8_t* buffer, DataPacket* packet) {
    //
    // Reconstruct header from bytes
    //
    packet->header = (buffer[0] << 8) | buffer[1];

    //
    // Reconstruct Payload
    //
    for (int i = 0; i < PAYLOAD_SIZE; ++i) {
        packet->payload[i] = buffer[2 + i];
    }

    //
    // Reconstruct Checksum from bytes
    //
    packet->checksum =
        (buffer[2 + PAYLOAD_SIZE] << 8) | buffer[3 + PAYLOAD_SIZE];
}

int main() {
    DataPacket in_packet;
    in_packet.header = 0x1234;
    in_packet.payload[0] = 0xAA;
    in_packet.payload[1] = 0xBB;
    in_packet.payload[2] = 0xCC;
    in_packet.checksum = 0xABCD;

    //
    // Buffer size calculated precisely:
    // 2 (HEader) + 3 (Payload) + 2 (Checksum) = 7 Bytes
    //
    uint8_t serial_buffer[sizeof(DataPacket)];

    printf("--- Serialization ---\n");
    printf("Input Packet Details:\n");
    printf("  Header:   0x%04X\n", in_packet.header);
    printf("  Payload:  [0x%02X, 0x%02X, 0x%02X]\n",
        in_packet.payload[0], in_packet.payload[1], in_packet.payload[2]);
    printf("  Checksum: 0x%04X\n\n", in_packet.checksum);

    //
    // Run Serialization
    //
    serialize(&in_packet, serial_buffer);

    //
    // Output raw serialized byte stream
    //
    printf("Output Serialized Stream:\n  [");
    for (size_t i = 0; i < sizeof(DataPacket); ++i) {
        printf("0x%02X", serial_buffer[i]);
        if (i < sizeof(DataPacket) - 1) { printf(", "); }
    }
    printf("]\n\n");

    //
    // Deserialization Verification
    //
    DataPacket out_packet;
    deserialize(serial_buffer, &out_packet);

    printf("--- Deserialization ---\n");
    printf("Reconstructed Header:   0x%04X\n", out_packet.header);
    printf("Reconstructed Checksum: 0x%04X\n", out_packet.checksum);

    return 0;
}
