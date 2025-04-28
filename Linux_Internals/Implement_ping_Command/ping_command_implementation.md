# `ping` Command Implementation

## Problem Statement

Design and implement a ping command in C that mimics the basic functionality of the Linux ping utility. The program should use raw sockets and the ICMP (Internet Control Message Protocol) to send echo requests and measure round-trip times.

## Requirements

- Networking: Use raw sockets to create send ICMP packets and capture ICMP replies to calculate response time.
- Construct ICMP echo requests with proper headers (Type8 for request, Type 0 for reply).
- Track the number of packets sent, received, and lost.
- Calculate the minimum, maximum, and average round-trip time (RTT).
- Implement a timeout mechanism to exit gracefully if no response is received.
- Validate the IP address or hostname and handle raw socket permission error (requires root or CAP_NET_RAW).

## Input

IP address or hostname.

```bash
./ping_sim <IP_address_or_hostname>

e.g.
./ping_sim 8.8.8.8
./ping_sim google.com
```

## Output

Display statistics on successful ping:

```bash
PING google.com (142.250.183.206): 56 data bytes  
64 bytes from 142.250.183.206: icmp_seq=1 ttl=116 time=12.34 ms  
64 bytes from 142.250.183.206: icmp_seq=2 ttl=116 time=10.45 ms  

--- google.com ping statistics ---  
2 packets transmitted, 2 received, 0% packet loss  
rtt min/avg/max = 10.45/11.39/12.34 ms  
```

Display error messages on failure:

```bash
Error: Invalid IP address or hostname.  
Error: Unable to create raw socket. Run with root privileges.
```

## Constraints

- **Permissions:** Requires root or **CAP_NET_RAW** to open raw sockets.
- **Packet size:** Send ICMP packets with **56 bytes of data** and a **8-byte header** (64 bytes total).
- **Timeout:** Set a default timeout of **5 seconds** for unresponsive hosts.

> [!NOTE]
>
> - **ICMP Packet Structure:**
>   - Type (1 byte): 8 for request, 0 for reply
>   - Code (1 byte): Always 0 for echo requests
>   - Checksum (2 bytes): Calculated using the packet’s content
>   - Identifier (2 bytes): Used to match request and reply pairs
>   - Sequence Number (2 bytes): Incremented for each request
>
> - **Checksum Calculation:** Implement a checksum function like:
>
> ```c
> unsigned short checksum(void * b, int len) {
>     unsigned short * buf = b;
>     unsigned int sum = 0;
>     for (sum = 0; len > 1; len -= 2) sum += *buf++;
>     if (len == 1) sum += *(unsigned char * )buf;
>     sum = (sum >> 16) + (sum & 0xFFFF);
>     return ~sum;
> }
> ```
>
> - **Socket Setup:** Create a raw socket.
>
> ```c
> int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
> ```
>
> - **Edge cases:**
>   - Host unreachable scenarios.
>   - High latency responses.
>   - Interrupted pings (e.g., with Ctrl+C).
