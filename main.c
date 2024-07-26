#include <stdio.h>

// #define VERSION_STRING                                                         \
//   "VERSION_STRING: SLURM-SHARP plugin v1.0.0, for SLURM 24.05.1"

#if defined(__arm__) || defined(__aarch64__)
#define ASM_DEFINE_STRING ".asciz"
#elif defined(__x86_64__) || defined(__i386__)
#define ASM_DEFINE_STRING ".string"
#else
#error "Unsupported architecture for version string embedding"
#endif

__asm__(".section .rodata\n"       // Define the section as read-only data
        ".hidden version_string\n" // Make the symbol hidden
        ".global version_string\n" // Make the symbol globally accessible
        "version_string:\n"        // Define the label for the string
        ASM_DEFINE_STRING " \"" VERSION_STRING "\"\n" // The string to embed
);
extern const char version_string[] __attribute__((visibility("hidden")));

int main() {
  printf("Hidden string address: %p\n", version_string);
  return 0;
}
