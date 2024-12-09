#
# 'make'        build executable file 'main'
# 'make clean'  removes all .o and executable files
#

# define the C++ compiler to use
CXX = clang++

# define any compile-time flags
CXXFLAGS := -std=c++17 -Wall -Wextra -g

# define library paths in addition to /usr/lib
LFLAGS := -L/usr/lib -L/usr/include -L/usr/include/glad

# define libraries to link against
LIBS := -lGL -lglfw -lGLU -lboost_system -lboost_filesystem

# define output directory
OUTPUT := output

# define source directory
SRC := src

# define include directory
INCLUDE := include

# define lib directory
LIB := lib

# External include directories
EXTERNAL_INCLUDES := -I/usr/include

# path to the glad files (absolute path outside the working directory)
GLAD_PATH := src

ifeq ($(OS),Windows_NT)
MAIN := main.exe
SOURCEDIRS := $(SRC)
INCLUDEDIRS := $(INCLUDE)
LIBDIRS := $(LIB)
FIXPATH = $(subst /,\,$1)
RM := del /q /f
MD := mkdir
else
MAIN := main
SOURCEDIRS := $(shell find $(SRC) -type d)
INCLUDEDIRS := $(shell find $(INCLUDE) -type d)
LIBDIRS := $(shell find $(LIB) -type d)
FIXPATH = $1
RM = rm -f
MD := mkdir -p
endif

# define any directories containing header files other than /usr/include
INCLUDES := $(patsubst %,-I%, $(INCLUDEDIRS:%/=%)) $(EXTERNAL_INCLUDES) -I$(GLAD_PATH)

# define the C++ source files
SOURCES := $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))

# define the C++ object files
OBJECTS := $(SOURCES:.cpp=.o)

# define the dependency output files
DEPS := $(OBJECTS:.o=.d)

# include glad.c file in the source (glad.c located in /usr/include/glad)
GLAD_SRC := $(GLAD_PATH)/glad.c

# Output main executable path
OUTPUTMAIN := $(call FIXPATH,$(OUTPUT)/$(MAIN))

# Default target
all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

# Create output directory
$(OUTPUT):
	$(MD) $(OUTPUT)

# Linking step: build the final executable
$(MAIN): $(OBJECTS) $(GLAD_SRC:.c=.o)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(GLAD_SRC:.c=.o) $(LFLAGS) $(LIBS)

# include all .d files
-include $(DEPS)


# Rule for compiling .cpp files to .o and .d files
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -MMD $< -o $@

# Rule for compiling .c files to .o and .d files (for glad.c)
.c.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -MMD $< -o $@

# Clean up object files and executable
.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	$(RM) $(call FIXPATH,$(DEPS))
	@echo Cleanup complete!

# Run the compiled program
run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete!
