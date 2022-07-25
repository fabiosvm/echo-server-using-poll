//
// socket.h
//

#ifndef SOCKET_H
#define SOCKET_H

#ifdef _WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
#else
  #include <sys/socket.h>
  #include <sys/ioctl.h>
  #include <arpa/inet.h>
  #include <unistd.h>
  #include <poll.h>
#endif

#ifdef _WIN32
  #define socket_t  SOCKET
  #define pollfd_t  WSAPOLLFD
#else
  #define socket_t       int
  #define INVALID_SOCKET -1
  #define SOCKET_ERROR   -1
  #define pollfd_t       struct pollfd
#endif

#ifndef __APPLE__
  #define socklen_t int
#endif

int socket_startup(void);
int socket_cleanup(void);
int socket_get_last_error(void);
int socket_ioctl(socket_t sock, int cmd, void *arg);
int socket_poll(pollfd_t *fds, unsigned long nfds, int timeout);
int socket_close(socket_t sock);
int socket_send(socket_t sock, const void *buf, int len, int flags);
int socket_recv(socket_t sock, void *buf, int len, int flags);

#endif // SOCKET_H
