TARGET = Lab8

CC		:= gcc
LINKER		:= gcc -o
CFLAGS		:= -c -Wall -O2
LFLAGS		:= -L ../../libraries -lm -lrt -lpthread 

SOURCES		:= $(wildcard *.c)
INCLUDES	:= $(wildcard *.h)
OBJECTS		:= $(SOURCES:$%.c=$%.o)

RM		:= rm -f

# linking Objects
$(TARGET): $(OBJECTS)
	@$(LINKER) $(@) $(OBJECTS) $(LFLAGS)

# compiling command
$(OBJECTS): %.o : %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $(@)

clean:
	@$(RM) $(OBJECTS)
	@$(RM) $(TARGET)
