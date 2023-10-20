#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>

// Constants for user IDs
#define ROOT_UID 0xbbe
#define UID1 0xbba
#define UID2 3000
#define UID3 0

// Function declarations
char* ft_des(const char* input);
int isLib(char* str, const char* target);
int afterSubstr(char* str, const char* substr);

int main(void) {
    // Variables
    bool isInjected = false;
    FILE* output_stream;
    long ptraceResult;
    char* ldPreloadEnv;
    int fileDescriptor;
    int mapFileDescriptor;
    char buffer[256];
    int local_14;
  
    // Save the current value of the local variable
    local_14 = *(int*)((char*)&local_14 + 0x14);

    // Check if the program is being traced
    ptraceResult = ptrace(PTRACE_TRACEME, 0, 1, 0);
    if (ptraceResult < 0) {
        puts("You should not reverse this");
        return 1;
    }
    else {
        // Check if LD_PRELOAD environment variable is set
        ldPreloadEnv = getenv("LD_PRELOAD");
        if (ldPreloadEnv == NULL) {
            // Attempt to open /etc/ld.so.preload
            fileDescriptor = open("/etc/ld.so.preload", 0);
            if (fileDescriptor < 1) {
                // Attempt to open /proc/self/maps
                mapFileDescriptor = syscall(SYS_open, "/proc/self/maps", 0);
                if (mapFileDescriptor == -1) {
                    fwrite(" /proc/self/maps is inaccessible, probably an LD_PRELOAD attempt, exit..\n", 1, 0x46, stderr);
                    return 1;
                }
                else {
                    // Read memory maps and check for specific libraries
                    do {
                        int readResult = syscall(SYS_gets, buffer, 0x100, mapFileDescriptor);
                        if (readResult == 0) {
                            break;
                        }
                        
                        if (isLib(buffer, &DAT_08049063) == 0) {
                            continue;
                        }
                        isInjected = true;
                    } while (!isInjected);

                    // Process the UID and print the flag
                    int uid = getuid();
                    output_stream = stdout;
                    if (uid == ROOT_UID) {
                        fputs(ft_des("H8B8h_20B4J43><8>\\ED<;j@3"), output_stream);
                    }
                    else if (uid < UID1) {
                        if (uid == UID1) {
                            fputs(ft_des("<>B16\\AD<C6,G_<1>^7ci>l4B"), output_stream);
                        }
                        else if (uid < UID2) {
                            if (uid == UID2) {
                                fputs(ft_des("I`fA>_88eEd:=`85h0D8HE>,D"), output_stream);
                            }
                            else if (uid < UID3) {
                                if (uid == UID3) {
                                    fwrite("You are root are you that dumb ?\n", 1, 0x21, output_stream);
                                }
                                else {
                                    // No token available for this UID
                                    fwrite("\nNope, there is no token here for you. Try again :)\n", 1, 0x38, output_stream);
                                }
                            }
                            else {
                                fputs(ft_des("7`4Ci4=^d=J,?>i;6,7d416,7"), output_stream);
                            }
                        }
                        else if (uid == 0xbbc) {
                            fputs(ft_des("?4d@:,C>8C60G>8:h:Gb4?l,A"), output_stream);
                        }
                        else if (uid < 0xbbd) {
                            fputs(ft_des("B8b:6,3fj7:,;bh>D@>8i:6@D"), output_stream);
                        }
                        else {
                            fputs(ft_des("G8H.6,=4k5J0<cd/D@>>B:>:4"), output_stream);
                        }
                    }
                    else if (uid == 0xbc2) {
                        fputs(ft_des("74H9D^3ed7k05445J0E4e;Da4"), output_stream);
                    }
                    else if (uid < 0xbc3) {
                        if (uid == 0xbc0) {
                            fputs(ft_des("bci`mC{)jxkn<\"uD~6%g7FK`7"), output_stream);
                        }
                        else if (uid < 0xbc1) {
                            fputs(ft_des("78H:J4<4<9i_I4k0J^5>B1j`9"), output_stream);
                        }
                        else {
                            fputs(ft_des("Dc6m~;}f8Cj#xFkel;#&ycfbK"), output_stream);
                        }
                    }
                    else if (uid == 0xbc4) {
                        fputs(ft_des("8_Dw\"4#?+3i]q&;p6 gtw88EC"), output_stream);
                    }
                    else if (uid < 0xbc4) {
                        fputs(ft_des("70hCi,E44Df[A4B/J@3f<=:`D"), output_stream);
                    }
                    else if (uid == 0xbc5) {
                        fputs(ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I"), output_stream);
                    }
                    else {
                        if (uid == 0xbc6) {
                            fputs(ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|"), output_stream);
                        }
                        else {
                            // No token available for this UID
                            fwrite("\nNope, there is no token here for you. Try again :)\n", 1, 0x38, output_stream);
                        }
                    }
                    fputc('\n', stdout);
                    return 0;
                }
            }
            else {
                // LD_PRELOAD injection detected, exit
                fwrite("Injection Linked lib detected, exit..\n", 1, 0x25, stderr);
                return 1;
            }
        }
        else {
            // LD_PRELOAD injection detected, exit
            fwrite("Injection Linked lib detected, exit..\n", 1, 0x25, stderr);
            return 1;
        }
    }

    // Control should never reach here, but to satisfy the compiler
    if (local_14 != *(int*)((char*)&local_14 + 0x14)) {
        __stack_chk_fail();
    }
    return 0;
}
