#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/inotify.h>
#include <limits.h>

void CallDetectionEngine(const char* filePath) {
    printf("[+] Called detection\n");
    fflush(stdout);

    // Construct the command to execute, including the file path and the parameter
    char command[1024];
    sprintf(command, "/home/jaywant/Desktop/Antivirus/engine \"%s\"", filePath);

    // Execute the command using system()
    int returnCode = system(command);

    if (returnCode != 0) {
        fprintf(stderr, "[-] Failed to execute command.\n");
    }
}

void* MonitorDirectoryThread(void* arg) {
    const char* directoryPath = (const char*)arg;
    int inotifyFd = inotify_init();

    if (inotifyFd == -1) {
        perror("inotify_init");
        return (void*)1;
    }

    int watchFd = inotify_add_watch(inotifyFd, directoryPath, IN_MODIFY | IN_CREATE | IN_DELETE);
    if (watchFd == -1) {
        perror("inotify_add_watch");
        return (void*)1;
    }

    char buffer[4096] __attribute__((aligned(__alignof__(struct inotify_event))));
    ssize_t numRead;
    char* ptr;
    struct inotify_event* event;

    while (1) {
        numRead = read(inotifyFd, buffer, sizeof(buffer));
        if (numRead == 0) {
            printf("[-] Read from inotify fd returned 0!");
            break;
        }

        if (numRead == -1) {
            perror("read");
            break;
        }

        for (ptr = buffer; ptr < buffer + numRead; ) {
            event = (struct inotify_event*) ptr;
            if (event->mask & (IN_MODIFY | IN_CREATE | IN_DELETE)) {
                printf("[+] Change detected in file: %s/%s\n", directoryPath, event->name);
                fflush(stdout);

                char fullPath[PATH_MAX];
                snprintf(fullPath, PATH_MAX, "%s/%s", directoryPath, event->name);

                // Call your detection engine with the file path
                CallDetectionEngine(fullPath);
            }
            ptr += sizeof(struct inotify_event) + event->len;
        }
    }

    close(inotifyFd);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <directory_list>\n", argv[0]);
        return 1;
    }

    char* pathList = argv[1];
    char* token = strtok(pathList, ";");

    while (token != NULL) {
        pthread_t thread;
        int result = pthread_create(&thread, NULL, MonitorDirectoryThread, (void*)token);
        if (result != 0) {
            fprintf(stderr, "Failed to create thread for directory monitoring\n");
            return 1;
        }
        token = strtok(NULL, ";");
    }

    printf("Press 'q' followed by Enter to exit...\n");

    // Wait for user input to exit
    char userInput;
    do {
        userInput = getchar();
    } while (userInput != 'q');

    return 0;
}
