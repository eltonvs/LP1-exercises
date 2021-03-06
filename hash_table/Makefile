# DIRS
INCDIR = include
BINDIR = bin
SRCDIR = src
BUILDDIR = build
LIBDIR = lib
# LIB OPTIONS
# TARGET
TARGET = $(BINDIR)/hash_table
# EXTENSIONS
SRCEXT = cpp
HEADEREXT = hpp
# SOURCES LIST
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# OBJECTS
OBJS = $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))
# COMPILER
CC = g++
# FOR CLEANING
RM = /bin/rm
# WARNING FLAG
WARN = -Wall
# DEBUG FLAGS
DEBUG = -g
# LINKING FLAGS
LIBOPTS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
LIBFLAG = -L $(LIBDIR) $(LIBOPTS)
INCFLAG = -I $(INCDIR)
LFLAGS = $(DEBUG) $(WARN) $(INCFLAG) # $(LIBFLAG)
V = 3
# COMPILATION FLAGS
CFLAGS = $(DEBUG) -c $(WARN) -D_VERSION_=$(V) -std=c++11

# ----------------------
# ENTRIES
# ----------------------

$(TARGET): $(OBJS)
	@echo "Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LFLAGS)"; $(CC) $^ -o $(TARGET) $(LFLAGS)
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INCFLAG) -o $@ $<"; $(CC) $(CFLAGS) $(INCFLAG) -o $@ $<

# DUMMY ENTRIES
clean:
	@echo "Cleaning..."
	@echo " $(RM) -r $(OBJS) $(TARGET)"; $(RM) -r $(OBJS) $(TARGET)

.PHONY: clean
