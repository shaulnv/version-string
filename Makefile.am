AUTOMAKE_OPTIONS = foreign

# Get the last commit hash prefix (first 7 characters)
GIT_COMMIT_HASH = $(shell git log -1 --format="%h")

# Get the current date and time
BUILD_DATE_TIME = $(shell date "+%Y-%m-%d %H:%M:%S")

# Define the version string
VERSION_STRING = "\"VERSION_STRING: SLURM-SHARP plugin: v1.0.0, SLURM: 24.05.1, Build: $(BUILD_DATE_TIME), Commit: $(GIT_COMMIT_HASH)\""

# Add the version string as a macro definition
AM_CPPFLAGS = -DVERSION_STRING=$(VERSION_STRING)

# Your standard automake definitions
bin_PROGRAMS = hello-world
hello_world_SOURCES = main.c
