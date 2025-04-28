# Implement a Custom `whois` Command

## Problem Statement

Create a program that mimics the `whois` command by connecting to a `whois` server, querying a domain, and displaying its registration information.

## Requirements

- Use socket programming to establish a TCP connection with a `whois` server (typically `whois.verisign-grs.com` for `.com` domains).
- Send the domain name as a query over the socket.
- Read and display the response from the server.

## Input

Domain name to query.

```bash
Domain: "example.com"
```

## Output

Whois record of the given domain.

```bash
Output:
Domain Name: EXAMPLE.COM
Registrar: Example Registrar, Inc.
Creation Date: 1995-08-13T04:00:00Z
...
```

## Constraints

- Port 43 is used for `whois` queries.
- The domain must be valid and reachable.
- Handle basic network errors (e.g., connection failures).

> [!NOTE]
>
> - For better accuracy, you can first connect to a generic `whois` server, and if necessary, redirect to the specific registrar's whois server.
> - Ensure to close the socket properly after the transaction.
