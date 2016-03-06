#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <common/mavlink.h>

int main(int argc, char *argv[]) {
    printf("Connecting to local mavproxy...\n");
    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in *mavlink_server = (struct sockaddr_in *)calloc(sizeof(struct sockaddr_in), 1);
    mavlink_server->sin_family = AF_INET;
    mavlink_server->sin_addr.s_addr = inet_addr("127.0.0.1");
    mavlink_server->sin_port = htons(5760);
    connect(sock, (struct sockaddr *)mavlink_server, sizeof(struct sockaddr_in));
    printf("Connected\n");
    unsigned char received_byte = '\0';
    while (recv(sock, &received_byte, sizeof(received_byte), 0)) {
        printf("received_byte = %c", received_byte);
        mavlink_message_t msg;
        mavlink_status_t status;
        int channel = 0;
        if (mavlink_parse_char(channel, received_byte, &msg, &status)) {
            printf("Received message with ID %d, sequence: %d from component %d of system %d\n", msg.msgid, msg.seq, msg.compid, msg.sysid);
        }
    }
    free(mavlink_server);
}
