/**
 * @file ip_address_conversion.c
 * @author Vikrant (vikrant_ap@hotmail.com)
 * @date 2026-09-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <stdio.h>
#include <string.h>

//
// Union to hold the IP address in dual formats
//
typedef union {
    char ipString[16];       // IPv4 maximum length is 15 chars + '\0'
    struct {
        unsigned char byte1; // First octet
        unsigned char byte2; // Second octet
        unsigned char byte3; // Third octet
        unsigned char byte4; // Fourth octet
    } bytes;
} IPAddress;

void string_to_bytes(IPAddress* ip) {
    int b1, b2, b3, b4;

    //
    // Parse the string into 4 temporary integers to prevent buffer overflow
    //
    if (sscanf(ip->ipString, "%d.%d.%d.%d", &b1, &b2, &b3, &b4) == 4) {
        ip->bytes.byte1 = (unsigned char)b1;
        ip->bytes.byte2 = (unsigned char)b2;
        ip->bytes.byte3 = (unsigned char)b3;
        ip->bytes.byte4 = (unsigned char)b4;
    }
}

void bytes_to_string(IPAddress* ip) {
    //
    // Format the bytes back into the string array component of the union
    //
    snprintf(ip->ipString, sizeof(ip->ipString), "%d.%d.%d.%d",
        ip->bytes.byte1, ip->bytes.byte2, ip->bytes.byte3, ip->bytes.byte4);
}

int main() {
    IPAddress myIP1;

    //
    // Set the active data representation via String
    //
    strncpy(myIP1.ipString, "10.0.0.1", sizeof(myIP1.ipString));

    printf("Input String: \"%s\"\n", myIP1.ipString);

    //
    // Convert representation internally
    //
    string_to_bytes(&myIP1);

    //
    // Output the byte structures
    //
    printf("Output Bytes: %d, %d, %d, %d\n\n",
        myIP1.bytes.byte1,
        myIP1.bytes.byte2,
        myIP1.bytes.byte3,
        myIP1.bytes.byte4);

    IPAddress myIP2;

    //
    // Set the active data representation via individual Bytes
    //
    myIP2.bytes.byte1 = 192;
    myIP2.bytes.byte2 = 168;
    myIP2.bytes.byte3 = 1;
    myIP2.bytes.byte4 = 254;

    printf("Input Bytes: %d, %d, %d, %d\n",
        myIP2.bytes.byte1,
        myIP2.bytes.byte2,
        myIP2.bytes.byte3,
        myIP2.bytes.byte4);

    //
    // Convert representation internally
    //
    bytes_to_string(&myIP2);

    //
    // Output the reconstrcuted string format
    //
    printf("Output String: \"%s\"\n", myIP2.ipString);

    return 0;
}
